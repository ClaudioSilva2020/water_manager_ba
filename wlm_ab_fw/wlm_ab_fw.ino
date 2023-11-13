#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <PubSubClient.h>
#include <FS.h>
#include "comm_manager.h"
#include "relay.h"

const char* mqttServer = "broker.emqx.io";
const int mqttPort = 1883;
const char* topic = "active_pump";
const char* mqtt_username = "wlm";
const char* mqtt_password = "wlm123";

CommManager commManager(SSID_P, PASSWORD, mqttServer, mqttPort, mqtt_username, mqtt_password);
relay bomba(RELAY_PIN); 

AsyncWebServer server(80);

/**
 * @brief 
 * * Função callback para requisições MQTT
 * 
 * @param topic  Tópico MQTT do projeto active_pump
 * @param payload Mensagem 
 * @param length  Tamanho da menagem
 */
void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Mensagem recebida [");
  Serial.print(topic);
  Serial.print("] ");

  String message;

  for (int i = 0; i < length; i++)
  {
    message += (char) payload[i];
  }
  Serial.println(message);

  if (message == "on" && !bomba.state)
  {
    Serial.println("Pump activated");
    bomba.relay_turnon();
  }
  if (message == "off" && bomba.state)
  {
    Serial.println("Pump deactivated");
    bomba.relay_turnoff();
  }
  
  Serial.println();
  Serial.println("-----------------------");
}

void setup() 
{
  Serial.begin(115200);
  delay(1000);
  
  if(!SPIFFS.begin()){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

 
  
  commManager.wifi_init();
  bomba.relay_turnoff();
//  commManager.mqtt_init();
//  commManager.setCallback(callback);
//  commManager.connect();
//
//  commManager.publish(topic, "join in WLM");
//  commManager.subscribe(topic);

     // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false);
  });
  
  // Route to load style.css file
  server.on("/style/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style/style.css", "text/css");
  });

   // Route to load style.css file
  server.on("/style/reset.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/style/reset.css", "text/css");
  });

  // Start server
  server.begin();
}

void loop() 
{
//  commManager.loop();
  
  
//  delay(100);
  
}
