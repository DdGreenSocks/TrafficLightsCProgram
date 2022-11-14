#include <avr/io.h>
#include <util/delay.h>

int main(void)

{
 //setup
 int x;

 DDRB= 0xFF;        //All PORT B pins are outputs
 DDRC= 0XF7;        //All PORT C pins are outputs except PC3 - 1111 0111 
 PORTB= 0xFF;       // Enable pullup resisrs on PORTB

 #define TRAFFIC_RED 0x01       //0000 0001
 #define TRAFFIC_ORANGE 0x02    // 0000 0010
 #define TRAFFIC_GREEN 0x04     // 0000 0100
 #define PED_RED 0x20           // 0010 0000
 #define PED_GREEN 0x10         // 0001 0000
 #define MASK 0x00              // 0000 0000


  while(1){

    x=PINC;
    x= x & MASK; 

    PORTB= TRAFFIC_RED;
    PORTC = PED_GREEN;
    _delay_ms(6000);
    PORTB=  TRAFFIC_ORANGE;
    PORTC=  PED_RED;
    _delay_ms(3000);
    PORTB= TRAFFIC_GREEN;
    _delay_ms(6000); 

  }
}