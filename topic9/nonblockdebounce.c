#include <stdint.h>
#include <stdio.h>
#include <avr/io.h> 
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void uart_setup(void);
void uart_put_byte(unsigned char byte_val);
void uart_printf(const char * fmt, ...);

void setup(void) {
    //  (a) Initialise Timer 0 in normal mode so that it overflows 
    //  with a period of approximately 0.004 seconds.
    //  Hint: use the table in Lecture 9.
    TCCR0B = 4; //256 pre scaler
    //  (b) Enable timer overflow interrupt for Timer 0.
    sei();
    //  (c) Turn on interrupts.
    TIMSK0 = 1;
    //  (d) Enable the I/O pin labelled A3 for digital input.
    DDRC &= ~(1<<3);
    //  (e) Send a debugging message to the serial port using
    //  the uart_printf function defined below. The message should consist of 
    //  your student number, "n10462091", followed immediately by a comma, 
    //  followed by the pre-scale factor that corresponds to a timer overflow 
    //  period of approximately 0.004 seconds. Terminate the 
    //  debugging message with a carriage-return-linefeed pair, "\r\n".
    uart_printf("n10462091,256\r\n");
}

//  (f) Create a volatile global variable called bit_counter.
//  The variable should be an 8-bit unsigned integer. 
//  Initialise the variable to zero.

volatile uint8_t bit_counter = 0; //history

//  (g) Define a volatile 8-bit unsigned global variable 
//  called pressed which will store the current state of the switch.
//  Initialise it to zero.

volatile uint8_t pressed = 0; //debounced state

//  (h) Define an interrupt service routine to process timer overflow
//  interrupts for Timer 0. Every time the interrupt service
//  routine is called, bit_counter should:
//      (h.a) Left-shift bit_counter one place;
//      (h.b) Bitwise AND bit_counter with a mask in which the 
//          4 bits on the right are 1 and the others are 0.
//      (h.c) Use bitwise OR to add the current open/closed value of the 
//          I/O pin labelled A3 to the history.
//      (h.d) If bit_counter is equal to the bit mask, then the switch has been 
//          observed 4 times in a row to be closed. Assign the value 1 to 
//          pressed, indicating that the switch should now be considered to be
//          officially "closed".
//      (h.e) If bit_counter is equal to 0, then the switch has been observed 
//          to be open at least 4 in a row, so store 0 in pressed, 
//          indicating that the switch should now be considered to be officially "open".

ISR(TIMER0_OVF_vect) {
    //h.a.
    bit_counter = (bit_counter<<1);
    //h.b.
    uint8_t mask = 0b00001111;
    bit_counter &= mask;
    //h.c
    //WRITE_BIT(bit_counter, 0, BIT_VALUE(PINC,3));
    bit_counter = ((bit_counter & ~(1<<(0))) | (((PINC >> 3) & 1) << 0));
    //h.d
    if (bit_counter == mask) {
        pressed = 1;
    }
    //h.e
    else if (bit_counter == 0) {
        pressed = 0;
    }
}

// -------------------------------------------------
// Helper functions.
// -------------------------------------------------

// Make sure this is not too big!
char buffer[100];

void uart_setup(void) {
#define BAUD (9600)
#define UBRR (F_CPU / 16 / BAUD - 1)
    UBRR0H = UBRR >> 8;
    UBRR0L = UBRR & 0b11111111;
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (3 << UCSZ00);
}

void uart_printf(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    for (int i = 0; buffer[i]; i++) {
        uart_put_byte(buffer[i]);
    }
}

#ifndef __AMS__
void uart_put_byte(unsigned char data) {
    while (!(UCSR0A & (1 << UDRE0))) { /* Wait */ }
    UDR0 = data;
}
#endif

int main() {
    uart_setup();
    setup();

    uint8_t prevState = 0;

    for (;;) {
        if (pressed != prevState) {
            prevState = pressed;
            uart_printf("Switch is %s.\r\n",  prevState ? "closed" : "open");
        }
    }

    return 0;
}
