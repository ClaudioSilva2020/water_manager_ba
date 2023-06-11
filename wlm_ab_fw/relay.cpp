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

    pinMode(pin, RELAY_OUTPUT);

    digitalWrite(pin, OFF);
}

relay::~relay()
{
    relay::_pin = 0;
}

void relay::relay_turnon()
{
    digitalWrite(_pin, ON);
}

void relay::relay_turnoff()
{
    digitalWrite(_pin, OFF);
}
