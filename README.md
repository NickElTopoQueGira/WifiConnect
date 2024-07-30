# WiFiConnect

WiFiConnect is a simple program for ESP8266 to connect to a simple server (see [**Simple-Java-server-with-soket**](https://github.com/NickElTopoQueGira/Simple-Java-server-with-soket)) for sending data. 

The project was created through the visual studio code [PlatformIO IDE](https://platformio.org/platformio-ide) plugin.

## Configuration

1. WiFi network access
    
    ```cpp
    const char* ssid = "The name of your WiFi network"; 
    const char* password = "The password to access the network ";  
    ```
    
2. Server
    
    ```cpp
    const char* serverAddress = "192.168.1.7"; // The address of the server
    const uint16_t port = 500; // Server port 
    ```
    

## Execution

<aside>
⚠️ The server must be turned on, otherwise the data will not be sent successfully.

</aside>