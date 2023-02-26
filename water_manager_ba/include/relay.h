/**
 * @file relay.h
 * @author Rafael Silva (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef __RELAY_H__
#define __RELAY_H__

#include <Arduino.h>


#define RELAY_PIN GPIO2
#define RELAY_OUTPUT OUTPUT


typedef enum relay_state
{
    OFF = LOW,
    ON = HIGH 
}relay_state_t ;

//estrutura de configuração
typedef struct relay
{
    uint8_t pin;
    relay_state_t state;
}relay_t;

// protótipo da função
int8_t config_relay(relay_t *config_relay);
void relay_turnon(); //Função que liga o rele
void relay_turnoff(); //Função que desliga o rele

#endif

