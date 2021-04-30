#include <stdio.h>
#include <ctype.h>

//  HERE: Declare a global array of char called list with capacity to hold
//  84 elements. AMS will insert data into this array prior to calling your function.
char list [84];

//  HERE: Declare a global array of int called term_count with capacity to hold
//  one element for each symbol in the designated character range.
int term_count [26];

//  HERE: Declare a global array of int called term_count with capacity to hold
//  one element for each symbol in the designated character range.
//  AMS will read results from this array after calling your function.
//  The contents of this array will be overwritten by AMS before calling your
//  function, so you should not make any assumptions about it.

void string_char_count_2() {

    //  Insert your solution here.
    for (int i = 0; i< (26); i++) {
        term_count[i] = 0;
    }

    for (int j = 0; list[j] != 0; j++) {
//        char ch = tolower(list[j]);
        char ch = list[j];
        if ('A' <= ch && ch <= 'Z') {
            int index = ch - 'A';
            term_count[index]++;
        }
    }
}

#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way
    //  that it works correctly even with this.
    srand( time( NULL ) );

#define CHAR_SET_SIZE (1 + 'Z' - 'A')

    for ( int i = 0; i < CHAR_SET_SIZE; i++ ) {
        term_count[i] = rand();
    }

    //  Read as much data from stdin as we can, and append each char to the
    //  buffer.
    int chars_read = 0;

    for ( chars_read = 0; chars_read < (84 - 1); chars_read++ ) {
        int scanf_result = scanf( "%c", &list[chars_read] );

        if ( 1 != scanf_result ) break;
    }

    //  Terminate the string in the buffer.
    list[chars_read] = 0;

    // Pad remainder of string with garbage to help with debugging.
    for ( int i = chars_read + 1; i < (84); i++ ) {
        list[i] = 'A' + rand() % CHAR_SET_SIZE;
    }

    // Call submitted code.
    string_char_count_2();

    // Display contents of string, and number of occurrences of each symbol.
    printf( "Input string        = '%s'\n", list );
    printf( "Input string length = %zu\n", strlen( list ) );
    printf( "Array capacity      = %d\n", 84 );
    printf( "Symbol frequencies:\n" );

    for ( int i = 0; i < CHAR_SET_SIZE; i++ ) {
        printf( "%c\t%d\n", 'A' + i, term_count[i] );
    }

    return 0;
}
