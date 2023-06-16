#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "comm_manager.h"
#include "relay.h"

const char* mqttServer = "broker.emqx.io";
const int mqttPort = 1883;
const char* topic = "active_pump";
const char* mqtt_username = "wlm";
const char* mqtt_password = "wlm123";

CommManager commManager(SSID_P, PASSWORD, mqttServer, mqttPort, mqtt_username, mqtt_password);
relay bomba(RELAY_PIN); 

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
  Serial.print(receivedChar);

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
  
  commManager.wifi_init();
  bomba.relay_turnoff();
  commManager.mqtt_init();
  commManager.setCallback(callback);
  commManager.connect();

  commManager.publish(topic, "join in WLM");
  commManager.subscribe(topic);
}

void loop() 
{
  commManager.loop();
  
  
  delay(100);
  
}
