#include <stdio.h>

void flag_multiples( void ) {
    int cn;

    for (cn = 64; cn <= 3073; cn++) {
        if (cn%7==0) {
            printf("%d <===\n", cn);
        } else {
            printf("%d\n", cn);
        }
    }
}

int main( void ) {
    flag_multiples( );
    return 0;
}
