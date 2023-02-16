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


#define RELAY_PIN GPIO2

struct relay
{
    int pin;
    int initial_state;
}relay_t;


void config_relay(relay_t *config_relay);

#endif
