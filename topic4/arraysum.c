#include <stdio.h>
#include <stdlib.h>

//  HERE: Declare an array called seq with capacity to hold 35 double
//  precision floating point values.
double seq [35];

//  HERE: Declare an integer called seq_len which will track the number of items
//  that have been appended to the list stored.
int seq_len;

//  HERE: Declare a double precision floating point value called seq_sum which will
//  be used to remember the total sum of the items stored in the list.
double seq_sum;

void arraysum() {
    //  Initially the list is empty, so assign 0 to seq_len.
    seq_len = 0;

    //  Append items to the list by reading from standard input until either
    //  seq_len >= 35, or the value returned by scanf is not 1.
    while( seq_len < 35 && scanf("%lf", &seq[seq_len]) == 1) {
        seq_len++;
    }

    //  Assign 0 to seq_sum.
    seq_sum = 0;

    //  Traverse the items that have been appended to the list, and accumulate
    //  the sum in seq_sum.
    for (int i = 0; i < seq_len; i++) {
        seq_sum += seq[i];
    }
}

#include <stdlib.h>
#include <time.h>

int main(void) {
    // AMS will do something a bit like this before it calls your solution.
    // Do not change any of this; instead, write your solution in such a way
    //  that it works correct even with this.
    for ( int i = 0; i < 35; i++ ) {
        double randVal = ((double) rand()) / RAND_MAX;
        seq[i] = randVal;

        if (randVal != seq[i]) {
            printf("Incorrect numeric type appears to be in use.\n");
            return 1;
        }
    }

    seq_len = rand();
    seq_sum = rand();

    // Call submitted code.
    arraysum();

    // Display contents of array seq.
    for (int i = 0; i < seq_len; i++) {
        printf("%f ", seq[i]);
    }

    printf("\n");
    printf("Item count: %d\n", seq_len);
    printf("Item sum  : %f\n", seq_sum);

    return 0;
}
