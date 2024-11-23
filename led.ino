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

// Página HTML almacenada en memoria flash
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Control Inteligente de LEDs ESP8266</title>
    <style>
        :root {
            --primary-color: #ff1493;
            --secondary-color: #8a2be2;
            --background-color: #000000;
            --panel-bg: #1a1a1a;
            --text-color: #ffffff;
            --button-inactive: #333333;
            --chat-bg: #1e1e1e;
            --led-blue: #007bff;
            --led-yellow: #ffd700;
            --led-red: #dc3545;
            --led-green: #28a745;
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: Arial, sans-serif;
            background-color: var(--background-color);
            color: var(--text-color);
            min-height: 100vh;
            display: flex;
            justify-content: center;
            align-items: center;
            padding: 20px;
        }

        .container {
            width: 100%;
            max-width: 500px;
            background-color: var(--panel-bg);
            border-radius: 20px;
            overflow: hidden;
        }

        .header {
            background: linear-gradient(to right, #ff1493, #8a2be2);
            padding: 20px;
            text-align: center;
        }

        .led-grid {
            display: grid;
            grid-template-columns: repeat(2, 1fr);
            gap: 15px;
            padding: 15px;
        }

        .led-control {
            background-color: var(--button-inactive);
            border: 2px solid var(--primary-color);
            border-radius: 15px;
            padding: 15px;
            text-align: center;
            position: relative;
        }

        .led-title {
            color: var(--text-color);
            margin-bottom: 15px;
            font-size: 16px;
        }

        .switch {
            position: relative;
            display: inline-block;
            width: 60px;
            height: 34px;
            background-color: #ccc;
            border-radius: 34px;
            cursor: pointer;
        }

        .switch input {
            opacity: 0;
            width: 0;
            height: 0;
        }

        .slider {
            position: absolute;
            cursor: pointer;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background-color: #ccc;
            transition: .4s;
            border-radius: 34px;
        }

        .slider:before {
            position: absolute;
            content: "";
            height: 26px;
            width: 26px;
            left: 4px;
            bottom: 4px;
            background-color: white;
            transition: .4s;
            border-radius: 50%;
        }

        input:checked + .slider {
            background-color: var(--primary-color);
        }

        input:checked + .slider:before {
            transform: translateX(26px);
        }

        .led-indicator {
            width: 8px;
            height: 8px;
            border-radius: 50%;
            margin: 10px auto 0;
            transition: opacity 0.3s;
        }

        .led-blue .led-indicator { background-color: var(--led-blue); }
        .led-yellow .led-indicator { background-color: var(--led-yellow); }
        .led-red .led-indicator { background-color: var(--led-red); }
        .led-green .led-indicator { background-color: var(--led-green); }
        
        .led-indicator.apagado { opacity: 0.3; }

        .action-buttons {
            padding: 15px;
            display: flex;
            flex-direction: column;
            gap: 10px;
        }

        .action-button {
            padding: 15px;
            border: none;
            border-radius: 10px;
            color: white;
            font-size: 16px;
            cursor: pointer;
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 10px;
        }

        .action-button:first-child {
            background-color: #9333ea;
        }

        .action-button:last-child {
            background-color: #4f46e5;
        }

        .chat-container {
            padding: 15px;
            background-color: var(--chat-bg);
            border-radius: 10px;
            margin: 15px;
        }

        #mensajes {
            height: 200px;
            overflow-y: auto;
            margin-bottom: 15px;
        }

        .mensaje {
            padding: 8px 12px;
            border-radius: 10px;
            margin-bottom: 8px;
            max-width: 80%;
        }

        .mensaje-usuario {
            background-color: #4f46e5;
            margin-left: auto;
        }

        .mensaje-asistente {
            background-color: #3b82f6;
        }

        .input-container {
            display: flex;
            gap: 10px;
        }

        #entrada-comando {
            flex-grow: 1;
            padding: 12px;
            border: none;
            border-radius: 10px;
            background-color: rgba(255, 255, 255, 0.1);
            color: white;
        }

        #boton-enviar {
            padding: 12px;
            border: none;
            border-radius: 10px;
            background: linear-gradient(to right, #ff1493, #8a2be2);
            color: white;
            cursor: pointer;
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>🎮 Control Inteligente de LEDs ESP8266</h1>
            <p>🤖 Asistente Virtual ChatGPT</p>
        </div>

        <div class="led-grid">
            <div class="led-control led-blue">
                <div class="led-title">LED Azul</div>
                <label class="switch">
                    <input type="checkbox" onchange="controlarLED('azul', this.checked)">
                    <span class="slider"></span>
                </label>
                <div class="led-indicator apagado"></div>
            </div>
            <div class="led-control led-yellow">
                <div class="led-title">LED Amarillo</div>
                <label class="switch">
                    <input type="checkbox" onchange="controlarLED('amarillo', this.checked)">
                    <span class="slider"></span>
                </label>
                <div class="led-indicator apagado"></div>
            </div>
            <div class="led-control led-red">
                <div class="led-title">LED Rojo</div>
                <label class="switch">
                    <input type="checkbox" onchange="controlarLED('rojo', this.checked)">
                    <span class="slider"></span>
                </label>
                <div class="led-indicator apagado"></div>
            </div>
            <div class="led-control led-green">
                <div class="led-title">LED Verde</div>
                <label class="switch">
                    <input type="checkbox" onchange="controlarLED('verde', this.checked)">
                    <span class="slider"></span>
                </label>
                <div class="led-indicator apagado"></div>
            </div>
        </div>

        <div class="action-buttons">
            <button class="action-button" onclick="controlarTodosLeds('parpadear')">
                ✨ Haz que parpadeen las luces
            </button>
            <button class="action-button" onclick="controlarTodosLeds('alternar')">
                🔄 Apaga y prende las luces
            </button>
        </div>

        <div class="chat-container">
            <div id="mensajes"></div>
            <div class="input-container">
                <input type="text" id="entrada-comando" placeholder="Escribe un comando o pregunta...">
                <button id="boton-enviar" onclick="enviarMensaje()">➤</button>
            </div>
        </div>
    </div>

    <script>
        const estadosLED = {
            azul: false,
            amarillo: false,
            rojo: false,
            verde: false
        };

        function controlarLED(color, encendido) {
            // Primero mostramos el mensaje del usuario
            const mensajeUsuario = `${encendido ? 'Prende' : 'Apaga'} LED ${color}`;
            agregarMensajeUsuario(mensajeUsuario);
            
            // Actualizamos el estado local
            estadosLED[color] = encendido;
            actualizarIndicadorLED(color);
            
            // Enviamos el comando al ESP8266
            const comando = encendido ? `enciende ${color}` : `apaga ${color}`;
            enviarComandoESP8266(comando);
        }

        function actualizarIndicadorLED(color) {
            const indicador = document.querySelector(`.led-${color} .led-indicator`);
            if (indicador) {
                if (estadosLED[color]) {
                    indicador.classList.remove('apagado');
                } else {
                    indicador.classList.add('apagado');
                }
            }
        }

        function controlarTodosLeds(accion) {
            if (accion === 'parpadear') {
                agregarMensajeUsuario('Haz que parpadeen las luces');
                enviarComandoESP8266('parpadea');
            } else if (accion === 'alternar') {
                const todosEncendidos = Object.values(estadosLED).every(estado => estado);
                agregarMensajeUsuario(todosEncendidos ? 'Apaga todas las luces' : 'Prende todas las luces');
                enviarComandoESP8266('toggle');
            }
        }

        function agregarMensajeUsuario(texto) {
            agregarMensaje(texto, true);
        }

        function agregarMensajeAsistente(texto) {
            agregarMensaje(texto, false);
        }

        function agregarMensaje(texto, esUsuario) {
            const mensajes = document.getElementById('mensajes');
            const mensajeDiv = document.createElement('div');
            mensajeDiv.className = `mensaje ${esUsuario ? 'mensaje-usuario' : 'mensaje-asistente'}`;
            mensajeDiv.textContent = esUsuario ? `👤 Tú: ${texto}` : `🤖 ChatGPT: ${texto}`;
            mensajes.appendChild(mensajeDiv);
            mensajes.scrollTop = mensajes.scrollHeight;
        }

        function enviarComandoESP8266(comando) {
            fetch('/command', {
                method: 'POST',
                headers: {'Content-Type': 'application/json'},
                body: JSON.stringify({command: comando})
            })
            .then(response => response.json())
            .then(data => {
                // Actualizar estados de los LEDs según la respuesta del servidor
                if (data.ledStates) {
                    Object.keys(data.ledStates).forEach(color => {
                        estadosLED[color] = data.ledStates[color];
                        const checkbox = document.querySelector(`.led-${color} input[type="checkbox"]`);
                        if (checkbox) {
                            checkbox.checked = data.ledStates[color];
                        }
                        actualizarIndicadorLED(color);
                    });
                }
                // Mostrar mensaje de respuesta del servidor
                if (data.message) {
                    agregarMensajeAsistente(data.message);
                }
            })
            .catch(error => {
                console.error('Error:', error);
                agregarMensajeAsistente('Error al comunicarse con el dispositivo');
            });
        }

        function enviarMensaje() {
            const entrada = document.getElementById('entrada-comando');
            const comando = entrada.value.trim();
            if (comando) {
                procesarComando(comando);
                entrada.value = '';
            }
        }

        function procesarComando(comando) {
            const comandoMinusculas = comando.toLowerCase();
            
            // Primero agregamos el mensaje del usuario
            agregarMensajeUsuario(comando);
            
            if (comandoMinusculas.includes('prende') || comandoMinusculas.includes('enciende')) {
                const color = obtenerColor(comandoMinusculas);
                if (color) {
                    enviarComandoESP8266(`enciende ${color}`);
                } else {
                    agregarMensajeAsistente('No se especificó un color válido');
                }
            } else if (comandoMinusculas.includes('apaga')) {
                const color = obtenerColor(comandoMinusculas);
                if (color) {
                    enviarComandoESP8266(`apaga ${color}`);
                } else {
                    agregarMensajeAsistente('No se especificó un color válido');
                }
            } else if (comandoMinusculas.includes('parpadeen')) {
                enviarComandoESP8266('parpadea');
            } else if (comandoMinusculas.includes('toggle') || 
                      (comandoMinusculas.includes('apaga') && comandoMinusculas.includes('prende'))) {
                enviarComandoESP8266('toggle');
            } else {
                agregarMensajeAsistente('No he entendido el comando. Por favor, intenta de nuevo.');
            }
        }

        function obtenerColor(comando) {
            const colores = ['azul', 'amarillo', 'rojo', 'verde'];
            return colores.find(color => comando.includes(color));
        }

        document.getElementById('entrada-comando').addEventListener('keypress', function(e) {
            if (e.key === 'Enter') {
                enviarMensaje();
            }
        });
    </script>
</body>
</html>
)rawliteral";

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


