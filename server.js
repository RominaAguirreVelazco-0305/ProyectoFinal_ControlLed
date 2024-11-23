const fs = require('fs');
const express = require('express');
const axios = require('axios');
const cors = require('cors');
const app = express();
const PORT = process.env.PORT || 5030;

// Clave API de OpenAI - Asegúrate de reemplazar esto con tu clave real de la API de OpenAI
const OPENAI_API_KEY = "";

// Configuración de middleware para permitir CORS y parseo de JSON
app.use(cors({
    origin: '*',
    methods: ['GET', 'POST', 'OPTIONS'],
    allowedHeaders: ['Content-Type', 'Authorization']
}));

app.use(express.json());

// Cargar el archivo de preguntas y respuestas al inicio del servidor
const preguntasRespuestas = loadQuestions();

function loadQuestions() {
    try {
        const data = fs.readFileSync('preguntas.json', 'utf-8');
        return JSON.parse(data);
    } catch (err) {
        console.error('Error al leer el archivo preguntas.json:', err);
        return { preguntas: {} };
    }
}

// Función para enviar comandos al ESP8266
async function sendCommandToESP(command) {
    console.log(`Sending command to ESP8266: ${command}`);
    try {
        const response = await axios.post('http://192.168.100.84/command', { command: command }, {
            headers: {
                'Content-Type': 'application/json'
            }
        });
        console.log(`Response from ESP8266: ${response.data.response}`);
        return response.data.response;
    } catch (error) {
        console.error("Error sending command to ESP8266:", error);
        return "Error communicating with ESP8266";
    }
}

// Función para obtener respuesta de OpenAI
async function fetchGPTResponse(text) {
    try {
        const response = await axios.post('https://api.openai.com/v1/engines/davinci/completions', {
            prompt: text,
            max_tokens: 150
        }, {
            headers: {
                'Authorization': `Bearer ${OPENAI_API_KEY}`,
                'Content-Type': 'application/json'
            }
        });
        return response.data.choices[0].text.trim();
    } catch (error) {
        console.error('Error calling OpenAI API:', error);
        return "Error processing response from OpenAI";
    }
}

// Rutas del servidor
app.get('/', (req, res) => {
    res.json({ status: 'Server running correctly' });
});

app.all('/get-answer', async (req, res) => {
    const pregunta = req.method === 'POST' ? req.body.text : req.query.text;
    console.log(`Received question: ${pregunta}`);

    if (!pregunta) {
        return res.status(400).json({ response: 'Error: No question received' });
    }

    let respuesta;
    let comando = "";

    const preguntaKey = pregunta.toLowerCase().trim();

    if (preguntasRespuestas.preguntas.hasOwnProperty(preguntaKey)) {
        respuesta = preguntasRespuestas.preguntas[preguntaKey].respuesta;
        comando = preguntasRespuestas.preguntas[preguntaKey].comando;

        if (comando) {
            const espResponse = await sendCommandToESP(comando);
            respuesta += " " + espResponse;
        }
    } else {
        respuesta = await fetchGPTResponse(pregunta);
    }

    res.json({ response: respuesta });
});

// Iniciar servidor
app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
