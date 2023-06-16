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

#define GPIO0   0
#define GPIO1   1
#define GPIO2   2
#define GPIO3   3


#define RELAY_PIN GPIO0
#define RELAY_OUTPUT OUTPUT


typedef enum relay_state
{
    OFF = LOW,
    ON = HIGH 
}relay_state_t ;


class relay
{
    private:
        int _pin;
    public:
        relay_state_t state;
    
        relay(int pin);
        ~relay();
        void relay_turnon(); //Função que liga o rele
        void relay_turnoff(); //Função que desliga o rele
};

#endif
