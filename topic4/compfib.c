#include <stdio.h>
#include <stdlib.h>

int val [31];
int x, y;

void compute_fib( void ) {
    scanf("%d",&x);
    scanf(" %d",&y);
    val[0] = x;
    val[1] = y;

    for (int i = 2; i < 31; i++) {
        val[i] = val[i-2]+val[i-1];
    }
}

int main(void) {
    //  Run your code.
    compute_fib();

    //  Display contents of array val.
    for (int i = 0; i < 31; i++) {
        printf("%d\n", val[i]);
    }

    return 0;
}
