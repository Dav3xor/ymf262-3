#include <avr/io.h>
#include "../ymf262-common/ymf-common.h"
#include "i2c_master.h"

#define I2C_BOARD2 0x10
#define I2C_BOARD1 0x11

#define PIN_OUT1 PC0
#define PIN_OUT2 PC1
#define PIN_OUT3 PC2
#define LED_ON PORTD |= _BV(PD4);
#define LED_OFF PORTD &= _BV(PD4);

int main(void) {
  DDRB |= _BV(PB0);

  i2c_init();
  adc_init(); 

  //set_output(PORTB,PB0);

  set_input(PORTC,PIN_OUT1);
  set_input(PORTC,PIN_OUT2);
  set_input(PORTC,PIN_OUT3);

  DDRD |= _BV(PD0);
  DDRD |= _BV(PD1);
  DDRD |= _BV(PD2);
  DDRD |= _BV(PD3);
  DDRD |= _BV(PD4);

  //pin_high(PORTD, PD0);
  pin_high(PORTD, PD1);
  //pin_high(PORTD, PD2);
  pin_high(PORTD, PD3);

  for(;;) {
    /*
    delay_ms(50);
    PORTD |= _BV(PD4);
    delay_ms(50);
    PORTD &= ~_BV(PD4);
    */
    
    uint16_t val;
    val = read_adc(PIN_OUT1)/4;
    if(val>128) {
      PORTD |= _BV(PD4);
    } else { 
      PORTD &= ~_BV(PD4);
    } 
   /* 
    PORTD |= _BV(PD4);
    delay_short(val);
    PORTD &= ~_BV(PD4);
    delay_short(100);
   */
  }

}

