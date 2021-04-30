#include <stdio.h>
#include <stdlib.h>

int rolled_vals [90];

void roll_dice( void ) {
    //  Seed the random number generator with the value 489207.
    int seed = 489207;
    srand(seed);
    int i;

    for (i=0; i < 90; i++) {
        rolled_vals[i] = rand() % 17 + 1;
    }
}

int main( void ) {
    //  Fill array with distinctive data pattern to help identify bugs. If you
    //  see the number 13283842 in your output there must a bug in your code.
//    for ( int i = 0; i < 90; i++ ) {
//        rolled_vals[i] = 0xCAB202;
//    }

    //  Call your code.
    roll_dice();

    //  Display contents of array rolled_vals.
    for ( int i = 0; i < 90; i++ ) {
        if ( i > 0 ) {
            printf( "," );
        }
        printf( "%d", rolled_vals[i] );
    }

    printf( "\n" );

    return 0;
}
