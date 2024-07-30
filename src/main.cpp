/**
 * @author NickElTopoQueGira
 * @date 30/7/2024
 */

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Connection to local network parameters
const char* ssid = ""; 
const char* password = "";

// Server (Socket) address
const char* serverAddress = "192.168.1.7";
const uint16_t port = 500;
WiFiClient client;

void setup() {
  // Serial configuration
  Serial.begin(115200);

  Serial.println("Connecting to"); 
  Serial.println(ssid);

  // Connection to the local network
  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println(""); 
  Serial.println("WiFi Connected"); 
  Serial.println("IP Address: "); 
  Serial.println(WiFi.localIP());

}

void loop() {
  // Connection with server
  if(!client.connect(serverAddress,port)){
    Serial.println("Connection with server failed!");
    delay(1000);
    return;
  }

  Serial.println("Successful connection with the server ");
  // String to send to server
  client.println("Hello form ESP8266");
  delay(250); 

  //Sending data to the server
  while(client.available() > 0){
    char c = client.read();
    Serial.write(c);
  } 
  client.stop();
  delay(5000);

}