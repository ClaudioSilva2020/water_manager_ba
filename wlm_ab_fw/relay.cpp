/**
 * @file relay.cpp
 * @author Rafael Silva (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "relay.h"

relay::relay(int pin)
{   
    _pin = pin;
    state = OFF;

    pinMode(pin, RELAY_OUTPUT);

    digitalWrite(pin, state);
}

relay::~relay()
{
    relay::_pin = 0;
}

void relay::relay_turnon()
{
    digitalWrite(_pin, OFF);
    state = ON;
}

void relay::relay_turnoff()
{
    digitalWrite(_pin, ON);
    state = OFF;
}
