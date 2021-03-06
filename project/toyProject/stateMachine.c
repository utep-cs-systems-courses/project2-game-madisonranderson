#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

static char dim = 0;

char toggle_red() {
  static char state = 0;
  switch(state) {
    case 0:
      red_led_state = 1;
      state = 1;
      break;
    case 1:
      red_led_state = 0;
      state = 0;
      break;
  }
  return 1;
}


char toggle_green() {
  static char state = 0;
  switch(state) {
    case 0:
      green_led_state = 0;
      state = 1;
      break;
    case 1:
      green_led_state = 1;
      state = 0;
      break;
  }
  return 1;
}


void state_advance(){

  if(switch_state_down[0]){
    char changed = 0;
    static char state = 0;
    switch(state) {
      case 0: changed = toggle_red(); state = 1; break;
      case 1: changed = toggle_green(); state = 0; break;
    }
    leds_changed = changed;
    led_update();
  }
  else if(switch_state_down[2]){
    char changed = 0;
    static char state = 0;
    switch (state){
      case 0: changed = toggle_green(); state = 1; break;
      case 1: changed = toggle_red(); state = 0; break;
    }
    leds_changed = changed;
    led_update();
  }
}

char dim_both_leds(){
  static char state = 0;
  switch(state){
    case 0:
      green_led_state = 0;
      red_led_state = 1;
      state = 1;
      break;
    case 1:
      green_led_state = 1;
      red_led_state = 0;
      state = 0;
      break;
  }
  return 1;
}

char bright_both_leds(){
  green_led_state = 1;
  red_led_state = 1;
  return 1;
}

void dim_both(){
  if(switch_state_down[1]){
    char changed = 0;
    switch (dim){
      case 0: changed = dim_both_leds(); break;
      case 1: changed = bright_both_leds(); break;
    }
    leds_changed = changed;
    led_update();
  }
}

void dim_advance(){
  switch(dim){
    case 0: dim = 1;
    case 1: dim = 0;
  }
}

void state_advance1(){
  if(switch_state_down[1]){
    char changed = 0;
    static char state = 0;
    switch (state){
      case 0: changed = toggle_green(); state = 1; break;
      case 1: changed = toggle_red(); state = 0; break;
    }
    leds_changed = changed;
    led_update();
  }
  
}

void state_advance_buzzer() {
  static char buzz_state = 0;
  if(switch_state_down[3]){
    switch(buzz_state) {
      case 0: buzzer_set_period(5727); buzz_state++; break;
      case 1: buzzer_set_period(4545); buzz_state++; break;
      case 2: buzzer_set_period(3822); buzz_state=0; break;
  // case 3: buzzer_set_period(0); buzz_state = 0; break;
      default: buzz_state = 0;
    }
  }
  else {
    buzzer_set_period(0);
  }
}
