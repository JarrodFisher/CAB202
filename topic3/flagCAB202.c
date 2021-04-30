#include <stdio.h>

void cab_202( void ) {
    int cn;

    for (cn = 64; cn <= 3073; cn++) {
        if (cn%7==0 && cn%19==0) {
            printf("CAB202\n");
        } else if (cn%7==0) {
            printf("CAB\n");
        } else if (cn%19==0) {
            printf("202\n");
        } else {
            printf("%d\n", cn);
        }
    }
}

int main( void ) {
    cab_202( );
    return 0;
}
