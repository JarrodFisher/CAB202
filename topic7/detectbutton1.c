#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

// Declare a global variable named was_on which is suitable to store a 
//  single byte. Do not initialise the variable at the point of declaration. 
//  The value of the variable will be managed by the setup_switch and is_rising
//  functions.

unsigned char was_on;

//  Define a parameterless function called setup_switch which returns nothing.
//
//  The function must enable digital input from a pull-down switch connected to 
//  the I/O pin labelled "PC1" on an Arduino Uno board. It should also
//  assign zero to global variable .
//
//  Apart from updating the global variable, the function must update only 
//  those bits required to enable digital input from the designated switch. The
//  function must achieve the required side effect regardless of the prior 
//  state of all registers. In particular, **do not assume** that memory has
//  previously been initialised with some value, zero or otherwise. 

void setup_switch(void) {
    DDRC &=~ (1<<1);
    was_on = 0;
}

//  Define a parameterless function called is_rising which returns an 
//  int which indicates that a rising edge has been detected in the state of 
//  a pull-down switch connected to I/O pin labelled "PC1" on an 
//  Arduino Uno board.
//
//  The function returns 1 if a rising edge is detected in the signal from the 
//  switch and 0 otherwise.
//
//  The function may read and update the value of global variable was_on 
//  but apart from that it may not alter the value of any other register or 
//  global variable. 
//  To detect a rising edge, use the global variable to remember the old state
//  of the switch, and compare it to the current state of the switch. If the 
//  old state is 0 and it is now non-zero, you have a rising edge. Otherwise, 
//  you do not have a rising edge.
//  https://www.google.com/search?q=rising+edge

int is_rising(void) {
    unsigned char state = PINC & (1<<1);

    int rise = (was_on == 0) && (state != 0);
    was_on = state;
    return rise;
}

void setup_builtin_led(void);
void toggle_builtin_led(void);
void simulate_other_setup();

int main(void) {
    simulate_other_setup();
    setup_builtin_led();
    setup_switch();

    while(1) {
        int rising = is_rising();
        
        if (rising) toggle_builtin_led();
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
    srand(17029);
     DDRB = rand() & 255;
     PINB = rand() & 255;
    PORTB = rand() & 255;
     DDRC = rand() & 255;
     PINC = rand() & 255;
    PORTC = rand() & 255;
     DDRD = rand() & 255;
     PIND = rand() & 255;
    PORTD = rand() & 255;
    was_on =  rand() & 255;
}
