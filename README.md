# 🌐 IoT & AI Intelligent LED Control Project 💡🤖

## 📝 Proyecto: Control Inteligente de LEDs con IoT e IA 

### 📋 Definición del Proyecto 📖

Este proyecto tiene como objetivo **controlar de manera inteligente un conjunto de LEDs** a través de una combinación de un **ESP8266** y una **plataforma web**, utilizando el poder del **Internet de las Cosas (IoT)** y **Inteligencia Artificial (IA)**. El sistema permite a los usuarios encender, apagar y parpadear los LEDs a través de una **interfaz intuitiva** 💻, así como recibir respuestas automáticas mediante la integración de un asistente virtual.

Además, el proyecto cuenta con un **chat integrado** 💬 que permite a los usuarios enviar peticiones como "prender LED rojo" 🔴 o "apagar todos los LEDs" 💡. Gracias a la **API de ChatGPT 3.5 Turbo** ⚡, el sistema responde a estas peticiones de manera natural y ayuda a controlar los LEDs de manera eficiente.

- **Claridad y Relevancia del Objetivo** 🎯: Este proyecto aborda la interacción física con componentes de hardware mediante una interfaz intuitiva, **proporcionando un enfoque de automatización accesible para el aprendizaje** 📚.

- **Innovación y Aplicabilidad** 💡: Se trata de una solución innovadora que **simplifica la conectividad entre usuarios y dispositivos físicos**, con aplicaciones en el campo de la educación, la automatización del hogar y el control industrial.

  

### 🛠️ Materiales Necesarios 🧰

Para llevar a cabo este proyecto, se necesita la siguiente lista de materiales:

- **ESP8266**: Microcontrolador utilizado para la conectividad WiFi y el control de los LEDs 🌐.
- **4 LEDs** (rojo 🔴, amarillo 🟡, verde 🟢, azul 🔵): Utilizados para indicar diferentes estados.
- **Resistencias de 220 Ω**: Para limitar la corriente de cada LED y proteger los componentes 🔧.
- **Protoboard**: Para realizar las conexiones temporales y pruebas 🛠️.
- **Cables jumper macho-macho**: Para conectar los componentes en la protoboard 🔌.
- **Fuente de Alimentación USB**: Para alimentar el ESP8266 ⚡.
- **Disponibilidad y Coste** 💵: Disponibilidad y Coste (5 puntos): Los materiales son accesibles y se ha considerado el coste de los mismos.

- **Protoboard**: $39 pesos
- ![Imagen de WhatsApp 2024-11-23 a las 14 56 29_3f47a8e5](https://github.com/user-attachments/assets/ca55e619-65a2-4bde-a16f-0f78cafc4461)

- **LEDs**: $3 pesos cada uno
-![Imagen de WhatsApp 2024-11-23 a las 14 55 52_b57971a0](https://github.com/user-attachments/assets/25bca450-1421-4491-9c2e-369a54481bdb)

- **Resistencia de 220 Ω**: $0.50 pesos cada una
- ![Imagen de WhatsApp 2024-11-23 a las 14 56 04_b3b4c481](https://github.com/user-attachments/assets/5a54190f-098d-4776-8f78-e07401777fac)

- **Cable Dupont Macho-Macho**: $1.50 pesos cada uno
-![Imagen de WhatsApp 2024-11-23 a las 14 55 43_9de8163d](https://github.com/user-attachments/assets/3a5bd870-cca2-423e-8408-7f1ee33120a6)

- **ESP8266**: $100 pesos
-![Imagen de WhatsApp 2024-11-23 a las 14 55 31_704a7159](https://github.com/user-attachments/assets/dc03f949-45e3-4919-b830-85f77796ea36)

- **Cable de transferencia de archivos**: $100 pesos
-![Imagen de WhatsApp 2024-11-23 a las 14 55 13_b9eda198](https://github.com/user-attachments/assets/128beeb8-bc27-46c8-a6bd-ac03457fde29)




### 🧩 Configuración del Hardware 🔧

- **Conexión y Configuración de los LEDs** : Los LEDs están conectados al **ESP8266** mediante resistencias de 220 Ω, siguiendo las especificaciones técnicas para garantizar una corriente adecuada. Los pines GPIO del ESP8266 se utilizaron para **controlar el encendido/apagado** de cada LED .

- **Programación del Microcontrolador**: El ESP8266 se programó usando **Arduino IDE** para establecer una conexión WiFi y responder a solicitudes HTTP desde el servidor Node.js. El microcontrolador **interpreta los comandos** recibidos (e.g., encender/apagar LEDs) y **realiza acciones físicas** sobre los LEDs.
  
- **Conexión y Configuración de los LEDs**
Los LEDs están conectados al ESP8266 mediante resistencias de 220 Ω para limitar la corriente y proteger los diodos. Cada LED está conectado a un pin GPIO diferente para su control individual:

- **LED Rojo**: Pin GPIO 4
- **LED Amarillo**: Pin GPIO 5
- **LED Verde**: Pin GPIO 12
- **LED Azul**: Pin GPIO 13

### 🚀 Funcionalidades Principales 🌟

- **Control Individual de LEDs** 💡: Enciende, apaga o haz parpadear cada LED de manera individual (rojo 🔴, azul 🔵, verde 🟢, amarillo 🟡).
- **Control Simultáneo de LEDs** 🔄: Utiliza botones para encender, apagar o parpadear todos los LEDs al mismo tiempo 🕹️.
- **Chat Integrado con IA** 🤖💬: Envía comandos en lenguaje natural a través del chat integrado para controlar los LEDs, gracias a la API de **ChatGPT 3.5 Turbo** 🧠.
- **Notificaciones y Respuestas en Tiempo Real** ⏱️: El sistema muestra notificaciones y respuestas en tiempo real sobre el estado de los LEDs 🔔.


### 💾 Almacenamiento de Datos 🗄️

- **Estructura de la Base de Datos**: Se utilizó un archivo JSON para almacenar información sobre preguntas frecuentes y comandos para los LEDs. La estructura del JSON incluye **timestamps**, **comandos de usuario**  y **respuestas automáticas** generadas por el sistema.

- **Conexión y Almacenamiento en la Nube** ☁️: La información se almacena en la nube mediante el uso de **API REST**, permitiendo a los usuarios acceder a datos y respuestas en tiempo real.
  

### 🤖 Desarrollo del Modelo de IA 🧠

- **Preparación de Datos** 🧹: Los datos fueron limpiados y estructurados para garantizar una **integración eficiente** con la API de OpenAI y respuestas precisas.
  
- **Selección y Entrenamiento del Modelo** 🏋️‍♂️: Se utilizó la API de **OpenAI (ChatGPT 3.5 Turbo)** para proporcionar respuestas naturales y relevantes en función de las preguntas de los usuarios 💬. El modelo fue ajustado para interpretar **comandos específicos de control** de los LEDs.
  
- **Validación y Ajuste del Modelo** 🔧: Se realizaron varias pruebas para mejorar la **precisión** del modelo, ajustando los **parámetros de temperatura y el número de tokens** para que las respuestas fueran concisas y específicas.
  

### 🖥️ Desarrollo de la Interfaz de Usuario 💻

- **Diseño de la Interfaz** 🎨: La interfaz fue desarrollada con **HTML, CSS y JavaScript**, proporcionando un panel de control moderno y accesible. Los usuarios pueden encender, apagar y parpadear los LEDs mediante un simple **clic en botones interactivos**.
  
- **Chat Integrado** 💬: La interfaz incluye un **chat integrado** que permite al usuario interactuar de manera más natural con el sistema. A través de este chat, el usuario puede **enviar comandos en lenguaje natural** (e.g., "enciende LED azul" 🔵) y recibir respuestas automáticas mediante la API de ChatGPT.
  
- **Implementación de Notificaciones** 🔔: Se integraron **notificaciones visuales** y respuestas en el chat para informar al usuario sobre el estado de los LEDs y las acciones realizadas 📩.

  

### 🧪 Pruebas y Validación 🧷

- **Pruebas Funcionales** 🛠️: Se realizaron pruebas exhaustivas para verificar que todos los componentes del sistema (ESP8266, servidor Node.js, interfaz web) **funcionan correctamente y sin errores** ✅.
- ![Imagen de WhatsApp 2024-11-23 a las 15 08 20_7a606be3](https://github.com/user-attachments/assets/b132bedd-5ba1-456c-b139-fdf84a19324d)

- **Precisión del Modelo** 📊: Las pruebas con el modelo de IA mostraron que éste proporciona respuestas precisas y consistentes para diferentes condiciones y preguntas de los usuarios.

### 📚 Documentación y Presentación 

- **Documentación Técnica** 📜: La documentación incluye **diagramas de arquitectura**del sistema
- ![image](https://github.com/user-attachments/assets/714747be-f9ba-4d8e-8c0a-3844981256a0)

  
### código fuente completo📑

### 1. Arduino Code (ESP8266) 📟
Este código se carga en el ESP8266 y se encarga de conectarse a la red WiFi, crear un punto de acceso y responder a los comandos HTTP para controlar el LED.

```cpp
// Al inicio del archivo, justo después de los includes:
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

// Variables para mantener el estado de los LEDs (solo definir una vez)
bool ledStates[4] = {false, false, false, false}; // azul, amarillo, rojo, verde

// Configuración de WiFi
const char* ap_ssid = "ESP8266_Access_Point";
const char* ap_password = "12345678";
const char* ssid = "LOS_CHINGONES_DE_CHINGONES";
const char* password = "Canisrominaagvela0305";
const char* serverUrl = "http://192.168.100.84:5030/get-answer";

// Definición de pines LED
const int redLedPin = 4;     // LED Rojo
const int yellowLedPin = 5;  // LED Amarillo
const int greenLedPin = 12;  // LED Verde
const int blueLedPin = 13;   // LED Azul

ESP8266WebServer server(80);

// Función para servir la página principal
void handleRoot() {
    server.send(200, "text/html", index_html);
}

// Función para manejar comandos de LED// Función para manejar comandos de LED individual
void handleLED(String color, String action) {
    int pin;
    int index = -1;
    String ledName = "";
    
    if (color == "azul") { 
        pin = blueLedPin; 
        index = 0;
        ledName = "LED Azul";
    }
    else if (color == "amarillo") { 
        pin = yellowLedPin; 
        index = 1;
        ledName = "LED Amarillo";
    }
    else if (color == "rojo") { 
        pin = redLedPin; 
        index = 2;
        ledName = "LED Rojo";
    }
    else if (color == "verde") { 
        pin = greenLedPin; 
        index = 3;
        ledName = "LED Verde";
    }
    else return;

    String responseMessage = "";

    if (action == "enciende") {
        digitalWrite(pin, HIGH);  // Cambiado a HIGH para encender
        ledStates[index] = true;
        responseMessage = "Encendiendo " + ledName;
    }
    else if (action == "apaga") {
        digitalWrite(pin, LOW);   // Cambiado a LOW para apagar
        ledStates[index] = false;
        responseMessage = "Apagando " + ledName;
    }
    else if (action == "parpadea") {
        bool originalState = ledStates[index];
        for(int i = 0; i < 5; i++) {
            digitalWrite(pin, LOW);   // Cambiado a LOW para apagar
            delay(200);
            digitalWrite(pin, HIGH);  // Cambiado a HIGH para encender
            delay(200);
        }
        digitalWrite(pin, originalState ? HIGH : LOW);
        responseMessage = "Haciendo parpadear " + ledName;
    }
    else if (action == "toggle") {
        ledStates[index] = !ledStates[index];
        digitalWrite(pin, ledStates[index] ? HIGH : LOW);  // Cambiado HIGH/LOW
        responseMessage = (ledStates[index] ? "Encendiendo " : "Apagando ") + ledName;
    }

    // Construir y enviar respuesta JSON
    if (index != -1) {
        String jsonResponse = "{\"status\":\"success\",\"message\":\"" + responseMessage + "\",\"ledStates\":{";
        jsonResponse += "\"azul\":" + String(ledStates[0] ? "true" : "false") + ",";
        jsonResponse += "\"amarillo\":" + String(ledStates[1] ? "true" : "false") + ",";
        jsonResponse += "\"rojo\":" + String(ledStates[2] ? "true" : "false") + ",";
        jsonResponse += "\"verde\":" + String(ledStates[3] ? "true" : "false");
        jsonResponse += "}}";
        
        server.send(200, "application/json", jsonResponse);
    }
}

// Función principal para manejar comandos
void handleCommand() {
    if (server.hasArg("plain")) {
        String message = server.arg("plain");
        DynamicJsonDocument doc(1024);
        DeserializationError error = deserializeJson(doc, message);
        
        if (!error) {
            String command = doc["command"].as<String>();
            Serial.println("Comando recibido: " + command);
            
            int spaceIndex = command.indexOf(" ");
            if (spaceIndex != -1) {
                String action = command.substring(0, spaceIndex);
                String color = command.substring(spaceIndex + 1);
                handleLED(color, action);
            } else {
                // Manejar comandos globales
                if (command == "parpadea") {
                    // Guardar estados originales
                    bool originalStates[4];
                    for(int i = 0; i < 4; i++) {
                        originalStates[i] = ledStates[i];
                    }
                    
                    // Hacer parpadear todos los LEDs
                    for(int i = 0; i < 5; i++) {
                        digitalWrite(blueLedPin, LOW);     // Cambiado a LOW para apagar
                        digitalWrite(yellowLedPin, LOW);
                        digitalWrite(redLedPin, LOW);
                        digitalWrite(greenLedPin, LOW);
                        delay(200);
                        digitalWrite(blueLedPin, HIGH);    // Cambiado a HIGH para encender
                        digitalWrite(yellowLedPin, HIGH);
                        digitalWrite(redLedPin, HIGH);
                        digitalWrite(greenLedPin, HIGH);
                        delay(200);
                    }
                    
                    // Restaurar estados originales
                    digitalWrite(blueLedPin, originalStates[0] ? HIGH : LOW);      // Cambiado HIGH/LOW
                    digitalWrite(yellowLedPin, originalStates[1] ? HIGH : LOW);
                    digitalWrite(redLedPin, originalStates[2] ? HIGH : LOW);
                    digitalWrite(greenLedPin, originalStates[3] ? HIGH : LOW);
                    
                    String response = "{\"status\":\"success\",\"message\":\"Parpadeo completado\",\"ledStates\":{";
                    response += "\"azul\":" + String(ledStates[0] ? "true" : "false") + ",";
                    response += "\"amarillo\":" + String(ledStates[1] ? "true" : "false") + ",";
                    response += "\"rojo\":" + String(ledStates[2] ? "true" : "false") + ",";
                    response += "\"verde\":" + String(ledStates[3] ? "true" : "false");
                    response += "}}";
                    server.send(200, "application/json", response);
                } 
                else if (command == "toggle") {
                    // Verificar si algún LED está encendido
                    bool anyLedOn = false;
                    for(int i = 0; i < 4; i++) {
                        if (ledStates[i]) {
                            anyLedOn = true;
                            break;
                        }
                    }
                    
                    // Actualizar estados
                    bool newState = !anyLedOn;
                    for(int i = 0; i < 4; i++) {
                        ledStates[i] = newState;
                    }
                    
                    // Actualizar LEDs físicos (HIGH = encendido, LOW = apagado)
                    digitalWrite(blueLedPin, newState ? HIGH : LOW);      // Cambiado HIGH/LOW
                    digitalWrite(yellowLedPin, newState ? HIGH : LOW);
                    digitalWrite(redLedPin, newState ? HIGH : LOW);
                    digitalWrite(greenLedPin, newState ? HIGH : LOW);
                    
                    String response = "{\"status\":\"success\",\"message\":\"" + 
                        String(newState ? "Encendiendo" : "Apagando") + " todos los LEDs\",\"ledStates\":{";
                    response += "\"azul\":" + String(ledStates[0] ? "true" : "false") + ",";
                    response += "\"amarillo\":" + String(ledStates[1] ? "true" : "false") + ",";
                    response += "\"rojo\":" + String(ledStates[2] ? "true" : "false") + ",";
                    response += "\"verde\":" + String(ledStates[3] ? "true" : "false");
                    response += "}}";
                    server.send(200, "application/json", response);
                } else {
                    server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"Comando no reconocido\"}");
                }
            }
        } else {
            server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"JSON inválido\"}");
        }
    } else {
        server.send(400, "application/json", "{\"status\":\"error\",\"message\":\"No se recibió comando\"}");
    }
}


void setup() {
    // Inicializar comunicación serial
    Serial.begin(115200);
    Serial.println("\nIniciando configuración...");
    
    // Configurar pines como salida
    pinMode(redLedPin, OUTPUT);
    pinMode(yellowLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    pinMode(blueLedPin, OUTPUT);
    
    // Inicializar todos los LEDs como apagados
    digitalWrite(redLedPin, HIGH);    // Volvemos a HIGH para apagar
    digitalWrite(yellowLedPin, HIGH); // Volvemos a HIGH para apagar
    digitalWrite(greenLedPin, HIGH);  // Volvemos a HIGH para apagar
    digitalWrite(blueLedPin, HIGH);   // Volvemos a HIGH para apagar
    
    // Configurar modo WiFi
    WiFi.mode(WIFI_AP_STA);
    
    // Crear Access Point
    bool apSuccess = WiFi.softAP(ap_ssid, ap_password);
    if(apSuccess) {
        Serial.println("Access Point creado exitosamente");
        Serial.print("Nombre de la red: ");
        Serial.println(ap_ssid);
        Serial.print("IP del Access Point: ");
        Serial.println(WiFi.softAPIP());
    } else {
        Serial.println("Error al crear Access Point");
    }
    
    // Intentar conectar a WiFi existente
    WiFi.begin(ssid, password);
    Serial.println("\nConectando a WiFi existente...");
    
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }
    
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConectado a WiFi");
        Serial.print("IP asignada: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("\nNo se pudo conectar a WiFi existente");
    }
    
    // Configurar rutas del servidor
    server.on("/", HTTP_GET, handleRoot);
    server.on("/command", HTTP_POST, handleCommand);
    
    // Habilitar CORS
    server.enableCORS(true);
    
    // Iniciar servidor
    server.begin();
    Serial.println("Servidor HTTP iniciado");
    Serial.println("Configuración completa!");

    // Indicador visual de inicio exitoso
    for(int i = 0; i < 3; i++) {
        digitalWrite(blueLedPin, LOW);  // LOW para encender
        delay(200);
        digitalWrite(blueLedPin, HIGH); // HIGH para apagar
        delay(200);
    }
}
void loop() {
    server.handleClient();
}

```

### 2. Backend Server (Node.js) 💻
Este archivo es el backend que se comunica con el ESP8266 y ChatGPT. Procesa las peticiones del usuario y envía las respuestas a través de la API de OpenAI.

```javascript
const fs = require('fs');
const express = require('express');
const axios = require('axios');
const cors = require('cors');
const app = express();
const PORT = process.env.PORT || 5030;

// Clave API de OpenAI
const OPENAI_API_KEY = "sk-...";  // Reemplaza con tu clave real de OpenAI

app.use(cors({
    origin: '*',
    methods: ['GET', 'POST', 'OPTIONS'],
    allowedHeaders: ['Content-Type', 'Authorization']
}));

app.use(express.json());

let preguntasRespuestas;
try {
    const data = fs.readFileSync('preguntas.json', 'utf-8');
    preguntasRespuestas = JSON.parse(data);
} catch (err) {
    console.error('Error al leer el archivo preguntas.json:', err);
    preguntasRespuestas = { preguntas: {} };
}

async function sendCommandToESP(command) {
    try {
        const response = await axios.post('http://192.168.100.84/command', { command: command }, {
            headers: {
                'Content-Type': 'application/json'
            }
        });
        return response.data.response;
    } catch (error) {
        console.error("Error al enviar comando al ESP8266:", error);
        return "Error al comunicar con el ESP8266";
    }
}

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
        return "Error al procesar la respuesta de OpenAI";
    }
}

app.get('/', (req, res) => {
    res.json({ status: 'Servidor funcionando correctamente' });
});

app.all('/get-answer', async (req, res) => {
    const pregunta = req.method === 'POST' ? req.body.text : req.query.text;
    if (!pregunta) {
        return res.status(400).json({ response: 'Error: No se recibió ninguna pregunta' });
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

app.listen(PORT, () => {
    console.log(`Server running on port ${PORT}`);
});
```

### 3. Archivo de Preguntas (preguntas.json) 📋
Este archivo JSON contiene las respuestas predefinidas para algunas preguntas comunes. ChatGPT se encarga de procesar estas preguntas y responder.

```json
{
  "preguntas": {
    "enciende la luz azul": {
      "respuesta": "Encendiendo la luz azul.",
      "comando": "enciende azul"
    },
    "apaga la luz azul": {
      "respuesta": "Apagando la luz azul.",
      "comando": "apaga azul"
    },
    "haz que parpadee la luz azul": {
      "respuesta": "Haciendo que la luz azul parpadee.",
      "comando": "parpadea azul"
    },
    "apaga y prende la luz azul": {
      "respuesta": "Apagando y luego prendiendo la luz azul.",
      "comando": "toggle azul"
    },
    "enciende la luz amarilla": {
      "respuesta": "Encendiendo la luz amarilla.",
      "comando": "enciende amarillo"
    },
    "apaga la luz amarilla": {
      "respuesta": "Apagando la luz amarilla.",
      "comando": "apaga amarillo"
    },
    "haz que parpadee la luz amarilla": {
      "respuesta": "Haciendo que la luz amarilla parpadee.",
      "comando": "parpadea amarillo"
    },
    "apaga y prende la luz amarilla": {
      "respuesta": "Apagando y luego prendiendo la luz amarilla.",
      "comando": "toggle amarillo"
    },
    "enciende la luz roja": {
      "respuesta": "Encendiendo la luz roja.",
      "comando": "enciende rojo"
    },
    "apaga la luz roja": {
      "respuesta": "Apagando la luz roja.",
      "comando": "apaga rojo"
    },
    "haz que parpadee la luz roja": {
      "respuesta": "Haciendo que la luz roja parpadee.",
      "comando": "parpadea rojo"
    },
    "apaga y prende la luz roja": {
      "respuesta": "Apagando y luego prendiendo la luz roja.",
      "comando": "toggle rojo"
    },
    "enciende la luz verde": {
      "respuesta": "Encendiendo la luz verde.",
      "comando": "enciende verde"
    },
    "apaga la luz verde": {
      "respuesta": "Apagando la luz verde.",
      "comando": "apaga verde"
    },
    "haz que parpadee la luz verde": {
      "respuesta": "Haciendo que la luz verde parpadee.",
      "comando": "parpadea verde"
    },
    "apaga y prende la luz verde": {
      "respuesta": "Apagando y luego prendiendo la luz verde.",
      "comando": "toggle verde"
    }
  }
}

```

### 📸 Guía de usuario con capturas de pantalla del control Inteligente 📷

1. **Panel de Control de LEDs** 🕹️

   - **Prende LED AZUL 🔵**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 28 36_c449a3e4](https://github.com/user-attachments/assets/45e532ac-44d6-4d92-9931-eba0d84cb73f)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 28 36_2a063668](https://github.com/user-attachments/assets/b7b5a00a-f742-4103-a61c-997e1da8b27a)


   - **Apaga LED AZUL 🔵**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 28 36_873daa37](https://github.com/user-attachments/assets/e012787f-143b-4285-b943-21a30776525d)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 28 36_59b7962c](https://github.com/user-attachments/assets/aa1c306a-9259-4ddc-9593-b3e8834f7d0b)


   - **Prende LED Amarillo 🟡**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 34 16_47fead29](https://github.com/user-attachments/assets/9251e256-1633-4d0e-8853-f0ec72b7bf47)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 34 33_153b698d](https://github.com/user-attachments/assets/d60310b9-d2f0-4f63-b5ea-c2e28bcc4eca)


   - **Apaga LED Amarillo 🟡**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 34 53_397aa6f2](https://github.com/user-attachments/assets/b628870d-448b-4277-858c-fa3a97829be4)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 35 06_d6e71879](https://github.com/user-attachments/assets/cb5257b6-dcf9-42e9-aff1-7cf906e9dfab)


   - **Prende LED Rojo 🔴**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 41 52_3b600e24](https://github.com/user-attachments/assets/a68a8505-7d2a-413e-95ee-1e0b7d2c9837)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 42 20_d3627fed](https://github.com/user-attachments/assets/125e650f-ba41-4880-9de4-89524ac1a487)


   - **Apaga LED Rojo 🔴**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 42 39_4242229d](https://github.com/user-attachments/assets/3e43da19-7698-48ae-ae6d-e9122c70e130)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 42 48_c609008f](https://github.com/user-attachments/assets/29cffe3c-7f81-4e71-a924-c1d2411c4717)


   - **Prende LED Verde 🟢**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 47 21_bdc8f3a2](https://github.com/user-attachments/assets/87b4c3ec-f2f6-4e88-b029-0c67bf1020cf)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 47 47_3890d412](https://github.com/user-attachments/assets/8366ce6c-4e34-49d8-ace4-51e4da4a87ea)


   - **Apaga LED Verde 🟢**
   - ![Imagen de WhatsApp 2024-11-23 a las 16 48 13_a0881add](https://github.com/user-attachments/assets/86d0f61e-d548-4077-b1d3-5815ed7e883f)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 48 21_990b443a](https://github.com/user-attachments/assets/a016dada-1a25-4096-aecd-0f387da32b2b)



2. **Parpadeen Luces** 🌟⚡:
   
   - ![Imagen de WhatsApp 2024-11-23 a las 16 55 44_be668ef3](https://github.com/user-attachments/assets/09ad7f69-30f3-451b-8e2b-52d2871dbe30)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 55 54_e5bb977c](https://github.com/user-attachments/assets/837d5a37-6378-41d7-a5cb-37a072f91d41)


  
3. **Apaga y prende las luces** ✨:
  
   - ![Imagen de WhatsApp 2024-11-23 a las 16 59 52_997130be](https://github.com/user-attachments/assets/67f5de9b-f0ea-4a7d-90c5-02523647f0cb)
   - ![Imagen de WhatsApp 2024-11-23 a las 16 59 57_40353208](https://github.com/user-attachments/assets/11749331-608e-4f93-a9b8-05eb731a5e2d)
   - ![Imagen de WhatsApp 2024-11-23 a las 17 00 06_af142318](https://github.com/user-attachments/assets/f3205175-d127-4e53-8e3f-e7bead7c6ead)
   - ![Imagen de WhatsApp 2024-11-23 a las 17 00 12_e22a5091](https://github.com/user-attachments/assets/74eccd4c-eae7-4772-830a-b9538c541102)



### 🚀 Cómo Empezar a clonar el repositorio 📂

1. **Clonar el repositorio** 📋:
   ```bash
   https://github.com/RominaAguirreVelazco-0305/ProyectoFinal_ControlLed.git
   ```
2. **Instalar las dependencias del servidor** 🛠️:
   ```bash
   cd servidor && npm install
   ```
3. **Configurar el ESP8266** ⚙️:
   - Utiliza el **Arduino IDE** para cargar el código en el ESP8266 💻.
4. **Ejecutar el servidor** 🚀:
   ```bash
   npm start
   ```
5. **Acceder a la interfaz** 🌐:
   - Ingresa a la dirección IP del ESP8266 desde tu navegador para empezar a **controlar los LEDs** 💡.



### ✨ Tecnologías Utilizadas 🛠️

- **ESP8266** 🌐: Para la conectividad y control de hardware.
- **Node.js y Express** 💻: Para la comunicación entre el microcontrolador y el servidor.
- **OpenAI API (ChatGPT 3.5 Turbo)** 🤖: Para el procesamiento de preguntas y respuestas inteligentes.
- **HTML, CSS, JavaScript** 🎨: Para el desarrollo de la interfaz web.

### 🔗 Recursos y Referencias 📚

- [Documentación de ESP8266](https://espressif.com/esp8266) 🌐
- [API de OpenAI](https://openai.com/) 🤖
- [Arduino IDE](https://www.arduino.cc/en/software) 💻

### 📧 Contacto 📬

- **Correo Electrónico** 📧: romina.aguirre8841@alumnos.udg.mx
- **GitHub** 🐙: [RominaAguirre-0305](https://github.com/RominaAguirreVelazco-0305)

---

¡Gracias por interesarte en este proyecto! 😊 Espero que sea tan divertido y educativo para ti como lo fue para mí crearlo. 🚀

Cualquier comentario o sugerencia es bienvenido. ¡Éxito en tu viaje con IoT e IA! 🌟🎉

