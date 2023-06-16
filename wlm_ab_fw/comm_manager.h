/**
 * @file comm_manager.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-06-11
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __COMM_MANAGER_H__
#define __COMM_MANAGER_H__

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define SSID_P      "claudiocell"
#define PASSWORD    "detamms2"



class CommManager
{
    private:
        WiFiClient espClient;
        PubSubClient client(espClient);      
        const char* ssid;
        const char* password;
        const char* mqttServer;
        const char* mqtt_username;
        const char* mqtt_password; 
        const int mqttPort;
        void connect();
    public:
        CommManager(const char* ssid, const char* password, const char* mqttServer, const int mqttPort, const char* mqtt_username, const char* mqtt_password);
        ~CommManager();
        void begin();
        void wifi_init();
        void mqtt_init();
        bool isConnected();
        void loop();
        void test_conn();
        bool publish(const char* topic, const char* payload);
        bool subscribe(const char* topic);
        void setCallback(MQTT_CALLBACK_SIGNATURE);
};
#endif
