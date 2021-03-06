#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

//  Define a parameterless function called setup_ddrs which returns nothing.
//
//  The function must enable digital input from two pull-down switches, as 
//  follows:
//  *   Connect Button 1 to I/O pin labelled "PC0".
//  *   Connect Button 2 to I/O pin labelled "PC2".
//
//  In addition to this, enable digital output to a collection of LEDs, as 
//  follows:
//  *   Connect LED 0 to I/O pin labelled "PC5".
//  *   Connect LED 1 to I/O pin labelled "PD0".
//  *   Connect LED 2 to I/O pin labelled "PD2".
//  *   Connect LED 3 to I/O pin labelled "PD5".
//  *   Connect LED 4 to I/O pin labelled "PD7".
//  *   Connect LED 5 to I/O pin labelled "PB1".
//  *   Connect LED 6 to I/O pin labelled "PB2".
//  *   Connect LED 7 to I/O pin labelled "PB5".
//
//  The function must update only those bits required to enable digital I/O 
//  using the designated pins. The function must achieve the required side 
//  effect regardless of the prior state of all registers. In particular, 
//  **do not assume** that memory has previously been initialised with some 
//  value, zero or otherwise. 

void setup_ddrs(void) {
    // BUTTON    1  &  2
    DDRC &=~ ((1<<0)|(1<<2));

    // LEDs
    DDRC |= (1<<5); //LED0
    DDRD |= (1<<0); //LED1
    DDRD |= (1<<2); //LED2
    DDRD |= (1<<5); //LED3
    DDRD |= (1<<7); //LED4
    DDRB |= (1<<1); //LED5
    DDRB |= (1<<2); //LED6
    DDRB |= (1<<5); //LED7
}

//  Define a parameterless function called b1_click which returns an 
//  int which indicates that a falling edge has been detected in the signal 
//  coming from I/O pin labelled "PC0" on an Arduino Uno 
//  board. This corresponds to a release event on Button 1.
//
//  The function returns 1 if a falling edge is detected in the signal from the 
//  switch, and 0 otherwise.
//
//  You may use a static local variable to monitor the on-going state of the 
//  pin, or you may use a global variable. Either choice is acceptable.

int b1_click(void) {
    static unsigned char old_state = 0;
    unsigned char curr_state = PINC & (1<<0);

    int result = (old_state != 0) && (curr_state == 0);
    old_state = curr_state;
    return result;
}

//  Define a parameterless function called b2_click which returns an 
//  int which indicates that a falling edge has been detected in the signal 
//  coming from I/O pin labelled "PC2" on an Arduino Uno 
//  board. This corresponds to a release event on Button 2.
//
//  The function returns 1 if a falling edge is detected in the signal from the 
//  switch, and 0 otherwise.
//
//  You may use a static local variable to monitor the on-going state of the 
//  pin, or you may use a global variable. Either choice is acceptable.

int b2_click(void) {
    static unsigned char old_state = 0;
    unsigned char curr_state = PINC & (1<<2);

    int result = (old_state != 0) && (curr_state == 0);
    old_state = curr_state;
    return result;
}

//  Define a function called show which returns nothing, but expects 
//  a single argument named x which contains an unsigned 8-bit integer. 
//
//  The function must use 8 LEDs, which are connected to I/O pins as indicated
//  in the setup_ddrs function, to display the binary value of the argument.
//  
//  To do this, each of the 8 LEDs must be turned on or off as follows:
//  *  LED 0 must be turned on if and only if bit 0 is set in x. C5
//  *  LED 1 must be turned on if and only if bit 1 is set in x. D0
//  *  LED 2 must be turned on if and only if bit 2 is set in x. D2
//  *  LED 3 must be turned on if and only if bit 3 is set in x. D5
//  *  LED 4 must be turned on if and only if bit 4 is set in x. D7
//  *  LED 5 must be turned on if and only if bit 5 is set in x. B1
//  *  LED 6 must be turned on if and only if bit 6 is set in x. B2
//  *  LED 7 must be turned on if and only if bit 7 is set in x. B5
//
//  Other than the digitial I/O pins assigned to the LEDs, no registers or bits 
//  may be altered by this function. 

void show(unsigned char x) {
    // DDRC |= (1<<5); //LED0
    // DDRD |= (1<<0); //LED1
    // DDRD |= (1<<2); //LED2
    // DDRD |= (1<<5); //LED3
    // DDRD |= (1<<7); //LED4
    // DDRB |= (1<<1); //LED5
    // DDRB |= (1<<2); //LED6
    // DDRB |= (1<<5); //LED7
    PORTC = (PORTC &~ (1<<5)) | (((x & (1<<0))>>0)*(1<<5));
    PORTD = (PORTD &~ (1<<0)) | (((x & (1<<1))>>1)*(1<<0));
    PORTD = (PORTD &~ (1<<2)) | (((x & (1<<2))>>2)*(1<<2));
    PORTD = (PORTD &~ (1<<5)) | (((x & (1<<3))>>3)*(1<<5));
    PORTD = (PORTD &~ (1<<7)) | (((x & (1<<4))>>4)*(1<<7));
    PORTB = (PORTB &~ (1<<1)) | (((x & (1<<5))>>5)*(1<<1));
    PORTB = (PORTB &~ (1<<2)) | (((x & (1<<6))>>6)*(1<<2));
    PORTB = (PORTB &~ (1<<5)) | (((x & (1<<7))>>7)*(1<<5));
}

void setup_builtin_led(void);
void toggle_builtin_led(void);
void simulate_other_setup();

int main(void) {
    simulate_other_setup();
    
    setup_ddrs();

    unsigned char x = 0;

    while(1) {
        if (b1_click() ) {
            x++;
        }
        
        if (b2_click() ) {
            x--;
        }
        
        show(x);
    } 
}

void setup_builtin_led(void) {
    DDRB |= (1<<5);
}

void toggle_builtin_led(void) {
    PORTB ^= (1<<5);
}

void simulate_other_setup(void) {
    //  Simulate situation where other important setup actions have been 
    //  performed prior to calling our functions.
    srand(17099);
     DDRB = rand() & 255;
     PINB = rand() & 255;
    PORTB = rand() & 255;
     DDRC = rand() & 255;
     PINC = rand() & 255;
    PORTC = rand() & 255;
     DDRD = rand() & 255;
     PIND = rand() & 255;
    PORTD = rand() & 255;
}
