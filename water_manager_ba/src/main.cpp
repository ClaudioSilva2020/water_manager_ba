#include <Arduino.h>
#include "relay.h"


relay_t relay_init_g = {0};

relay_init_g->pin = RELAY_PIN;
relay_init_g->state = OFF; 


void setup() {
  config_relay(&relay_init_g);

  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}