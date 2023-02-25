/**
 * @file relay.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "relay.h"

/**
 * @brief Esta função configura o estato inicial do rele
 * 
 * @param config_relay ponteiro para esta estrutura
 * @return int8_t se erro -1, se sucesso 0
 */
int8_t config_relay(relay_t *config_relay)
{
    if (config_relay == nullptr)
    {
        return -1;
    }
    pinMode(config_relay->pin, RELAY_OUTPUT);

    digitalWrite(config_relay->pin, config_relay->state);
    
    return 0;    
}

void relay_turnon()
{
    digitalWrite(RELAY_PIN, ON);
}
void relay_turnoff()
{
    digitalWrite(RELAY_PIN, OFF);
}