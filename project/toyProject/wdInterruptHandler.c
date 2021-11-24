#include <msp430.h>
#include "stateMachine.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  static char dim_count = 0;
  static char advance = 0;
  static char buzzer_count = 0;
  
  if (++dim_count == 2){
    dim_both();
    if(++advance == 250){
      dim_advance();
      advance = 0;
    }
    dim_count = 0;
  }
  if (++blink_count == 150){
    state_advance();
    blink_count = 0;
  }
  if (++buzzer_count == 250){
    state_advance_buzzer();
    buzzer_count = 0;
  }
}
