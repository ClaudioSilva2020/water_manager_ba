#include "relay.h"


relay bomba(RELAY_PIN); 
relay led(GPIO2);


void setup() {
  // put your setup code here, to run once:
  led.relay_turnon();

}

void loop() {
  bomba.relay_turnon();
  delay(200);
  bomba.relay_turnoff();
  delay(500);

}
