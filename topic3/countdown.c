#include <stdio.h>

void count_down( void ) {
    int cn;

    for (cn = 3634; cn >= 73; cn = cn - 3) {
        printf("%d\n", cn);
    }
}

int main( void ) {
    count_down( );
    return 0;
}