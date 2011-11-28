#include "timers.h"
#include <avr/interrupt.h>
#include <avr/io.h>

void timer_setup(void) {

}

//Set motor speed, 8 bit variable from 0 to 255
void pwm_set(uint8_t motor, uint8_t speed) {
 cli(); //Disable interrupts
 if (speed != 0) { //Check if we're asking to turn off the motors
  switch (motor) {
   case 0: //All motors
    TC0CRA = speed; //Set speeds
    TC0CRB = speed;
    TC2CRA = speed;
    TC2CRB = speed;
    TCCR0A |= (1<<COM0A1) | (1<<COM0A0) | (1<<COM0B1) | (1<<COM0B0); //Turn on toggling on output pins
    TCCR2A |= (1<<COM2A1) | (1<<COM2A0) | (1<<COM2B1) | (1<<COM2B0);
    break;
   case 1:
    TC0CRA = speed;
    TCCR0A |= (1<<COM0A1);
    break;
   case 2:
    TC0CRB = speed;
    TCCR0A |= (1<<COM0A0);
    break;
   case 3:
    TC2CRA = speed;
    TCCR2A |= (1<<COM2A1);
    break;
   case 4:
    TC2CRB = speed;
    TCCR2A |= (1<<COM2A0);
    break;
  }
  return;
 } else {
//Turn off register bits responsible for causing pins tied to timers to toggle.
  switch (motor) {
   case 0: //All motors
    TCCR0A &= ~( (1<<COM0A1) | (1<<COM0A0) | (1<<COM0B1) | (1<<COM0B0) ); //Turn off output toggling
    TCCR2A &= ~( (1<<COM2A1) | (1<<COM2A0) | (1<<COM2B1) | (1<<COM2B0) );
    break;
   case 1:
    TCCR0A &= ~(1<<COM0A1);
    break;
   case 2:
    TCCR0A &= ~(1<<COM0A0);
    break;
   case 3:
    TCCR2A &= ~(1<<COM2A1);
    break;
   case 4:
    TCCR2A &= ~(1<<COM2A0);
    break;
  }
 }
 sei(); //Enable interrupts
}


void pwm_change(uint8_t motor, int8_t speed) {
 switch (motor) {
  case 0: //All motors
      
   break;
  case 1:
    if ((TC0CRA - 255) < //Todo: make sure changing doesn't overflow any of the variables, if so, default them to on/off
   break;
  case 2:
   TCCR0A &= ~(1<<COM0A0);
   break;
  case 3:
   TCCR2A &= ~(1<<COM2A1);
   break;
  case 4:
   TCCR2A &= ~(1<<COM2A0);
   break;
 }

}
