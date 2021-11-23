#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_led_state = 0, green_led_state = 0, leds_changed = 0;
static char redLed[] = {0, LED_RED}, greenLed[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  // if (switch_state_changed) {
  if(leds_changed){
    char ledFlags = redLed[red_led_state] | greenLed[green_led_state]; /* by default, no LEDs on */

    //ledFlags |= switch_state_down[0] ? LED_GREEN : 0;
    //ledFlags |= switch_state_down[1] ? LED_RED : 0;
    //ledFlags |= switch_state_down[2] ? LED_GREEN : 0;
    //ledFlags |= switch_state_down[3] ? LED_RED : 0;

    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags; // set bits for on leds
    leds_changed = 0;
  }
  // switch_state_changed = 0;
}

