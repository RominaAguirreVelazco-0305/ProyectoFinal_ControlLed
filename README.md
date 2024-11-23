# 🌐 IoT & AI Intelligent LED Control Project

## 📝 Proyecto: Control Inteligente de LEDs con IoT e IA

### 📋 Definición del Proyecto

Este proyecto tiene como objetivo **controlar de manera inteligente un conjunto de LEDs** a través de una combinación de un **ESP8266** y una **plataforma web**, utilizando el poder del **Internet de las Cosas (IoT)** y **Inteligencia Artificial (IA)**. El sistema permite a los usuarios encender, apagar y parpadear los LEDs a través de una **interfaz intuitiva**, así como recibir respuestas automáticas mediante la integración de un asistente virtual.

Además, el proyecto cuenta con un **chat integrado** que permite a los usuarios enviar peticiones como "prender LED rojo" o "apagar todos los LEDs". Gracias a la **API de ChatGPT 3.5 Turbo**, el sistema responde a estas peticiones de manera natural y ayuda a controlar los LEDs de manera eficiente.

- **Claridad y Relevancia del Objetivo**: Este proyecto aborda la interacción física con componentes de hardware mediante una interfaz intuitiva, **proporcionando un enfoque de automatización accesible para el aprendizaje**.
- **Innovación y Aplicabilidad**: Se trata de una solución innovadora que **simplifica la conectividad entre usuarios y dispositivos físicos**, con aplicaciones en el campo de la educación, la automatización del hogar y el control industrial.

### 🛠️ Materiales Necesarios

Para llevar a cabo este proyecto, se necesita la siguiente lista de materiales:

- **ESP8266**: Microcontrolador utilizado para la conectividad WiFi y el control de los LEDs.
- **4 LEDs** (rojo, amarillo, verde, azul): Utilizados para indicar diferentes estados.
- **Resistencias de 220 Ω**: Para limitar la corriente de cada LED y proteger los componentes.
- **Protoboard**: Para realizar las conexiones temporales y pruebas.
- **Cables jumper macho-macho**: Para conectar los componentes en la protoboard.
- **Fuente de Alimentación USB**: Para alimentar el ESP8266.

- **Disponibilidad y Coste**: Todos los materiales son **fácilmente accesibles** en tiendas de electrónica o en línea. El coste total se estima en unos **20 a 25 USD**.

### 🧩 Configuración del Hardware

- **Conexión y Configuración de los LEDs**: Los LEDs están conectados al **ESP8266** mediante resistencias de 220 Ω, siguiendo las especificaciones técnicas para garantizar una corriente adecuada. Los pines GPIO del ESP8266 se utilizaron para **controlar el encendido/apagado** de cada LED.

- **Programación del Microcontrolador**: El ESP8266 se programó usando **Arduino IDE** para establecer una conexión WiFi y responder a solicitudes HTTP desde el servidor Node.js. El microcontrolador **interpreta los comandos** recibidos (e.g., encender/apagar LEDs) y **realiza acciones físicas** sobre los LEDs.

### 💾 Almacenamiento de Datos

- **Estructura de la Base de Datos**: Se utilizó un archivo JSON para almacenar información sobre preguntas frecuentes y comandos para los LEDs. La estructura del JSON incluye **timestamps**, **comandos de usuario** y **respuestas automáticas** generadas por el sistema.

- **Conexión y Almacenamiento en la Nube**: La información se almacena en la nube mediante el uso de **API REST**, permitiendo a los usuarios acceder a datos y respuestas en tiempo real.

### 🤖 Desarrollo del Modelo de IA

- **Preparación de Datos**: Los datos fueron limpiados y estructurados para garantizar una **integración eficiente** con la API de OpenAI y respuestas precisas.
- **Selección y Entrenamiento del Modelo**: Se utilizó la API de **OpenAI (ChatGPT 3.5 Turbo)** para proporcionar respuestas naturales y relevantes en función de las preguntas de los usuarios. El modelo fue ajustado para interpretar **comandos específicos de control** de los LEDs.
- **Validación y Ajuste del Modelo**: Se realizaron varias pruebas para mejorar la **precisión** del modelo, ajustando los **parámetros de temperatura y el número de tokens** para que las respuestas fueran concisas y específicas.

### 🖥️ Desarrollo de la Interfaz de Usuario

- **Diseño de la Interfaz**: La interfaz fue desarrollada con **HTML, CSS y JavaScript**, proporcionando un panel de control moderno y accesible. Los usuarios pueden encender, apagar y parpadear los LEDs mediante un simple **clic en botones interactivos**.
- **Chat Integrado**: La interfaz incluye un **chat integrado** que permite al usuario interactuar de manera más natural con el sistema. A través de este chat, el usuario puede **enviar comandos en lenguaje natural** (e.g., "enciende LED azul") y recibir respuestas automáticas mediante la API de ChatGPT.
- **Implementación de Notificaciones**: Se integraron **notificaciones visuales** y respuestas en el chat para informar al usuario sobre el estado de los LEDs y las acciones realizadas.

### 🧪 Pruebas y Validación

- **Pruebas Funcionales**: Se realizaron pruebas exhaustivas para verificar que todos los componentes del sistema (ESP8266, servidor Node.js, interfaz web) **funcionan correctamente y sin errores**.
- **Precisión del Modelo**: Las pruebas con el modelo de IA mostraron que éste proporciona respuestas precisas y consistentes para diferentes condiciones y preguntas de los usuarios.

### 📚 Documentación y Presentación

- **Documentación Técnica**: La documentación incluye **diagramas de arquitectura** del sistema, el **código fuente completo** y una **guía de usuario** para la correcta operación del sistema. También se proporciona un README detallado que describe cada componente.
- **Presentación del Proyecto**: El proyecto se presentó mediante una **demostración en vivo** que explicó claramente la arquitectura del sistema, el funcionamiento de los LEDs, y los beneficios educativos y prácticos de la solución.

### 🌟 Características Adicionales y Creatividad

- **Creatividad e Innovación Extra**: El proyecto incluye la posibilidad de **controlar los LEDs mediante comandos de voz** (utilizando el móvil como interfaz de entrada), y también una funcionalidad para sincronizar el parpadeo de los LEDs con **música**, agregando un elemento de entretenimiento y diversificación a la aplicación.

### 🚀 Cómo Empezar

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/tu-usuario/IoT-Intelligent-LEDs.git
   ```
2. **Instalar las dependencias del servidor**:
   ```bash
   cd servidor && npm install
   ```
3. **Configurar el ESP8266**:
   - Utiliza el **Arduino IDE** para cargar el código en el ESP8266.
4. **Ejecutar el servidor**:
   ```bash
   npm start
   ```
5. **Acceder a la interfaz**:
   - Ingresa a la dirección IP del ESP8266 desde tu navegador para empezar a **controlar los LEDs**.

### 📸 Capturas de Pantalla

1. **Panel de Control de LEDs**:
   ![Panel de LEDs](ruta/a/tu/imagen1.png)

2. **Comunicación en el Chat**:
   ![Chat Control](ruta/a/tu/imagen2.png)

### ✨ Tecnologías Utilizadas

- **ESP8266**: Para la conectividad y control de hardware.
- **Node.js y Express**: Para la comunicación entre el microcontrolador y el servidor.
- **OpenAI API (ChatGPT 3.5 Turbo)**: Para el procesamiento de preguntas y respuestas inteligentes.
- **HTML, CSS, JavaScript**: Para el desarrollo de la interfaz web.

### 🔗 Recursos y Referencias

- [Documentación de ESP8266](https://espressif.com/esp8266)
- [API de OpenAI](https://openai.com/)
- [Arduino IDE](https://www.arduino.cc/en/software)

### 📧 Contacto

- **Correo Electrónico**: tuemail@ejemplo.com
- **GitHub**: [TuUsuario](https://github.com/tu-usuario)

---

¡Gracias por interesarte en este proyecto! 😊 Espero que sea tan divertido y educativo para ti como lo fue para mí crearlo. 🚀

Cualquier comentario o sugerencia es bienvenido. ¡Éxito en tu viaje con IoT e IA! 🌟

