#include <stdio.h>

void list_integers( void ) {
    int cn = 7;

    printf("Integers less than or equal to 373, and greater than 7...\n");

    while (cn <= 373) {
        printf("%d\n",cn);
        cn++;
    }
}

int main( void ) {
    list_integers( );
    return 0;
}