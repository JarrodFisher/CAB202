#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VAL 20
#define MIN_VAL -20
#define NUMS 41

int max_count = 0;
int min_count = 0;
int numcount[NUMS];

void process(int x) {
    // Process one value here.
    for (int i = MIN_VAL; i <= MAX_VAL; i++) {
        if (x == (i+20)) {
            ++numcount[(i+20)];
        }
    }
}

void post_process() {
    // Compute derived results here.
    max_count = numcount[0];
    min_count = numcount[0];

    // Checks count for specific number and compares against min and max
    for (int i = MIN_VAL; i <= MAX_VAL; i++) {
        if (numcount[(i+20)] < min_count) {
            min_count = numcount[ (i+20) ];
        }
        if (numcount[ (i+20) ] > max_count) {
            max_count = numcount[(i+20)];
        }
    }
}

void print() {
    // Print results here
    int iter = 0; // Set iteration variable for checking all min and max numbers

    printf("The highest count was at %d, at ", max_count);
    // checks and prints all numbers at the max count value
    for (int i = MIN_VAL; i <= MAX_VAL; i++) {
        if (numcount[(i+20)] == max_count && iter ==0) {
            printf("%d",(i+20));
            iter++;
        } else if (numcount[(i+20)] == max_count && iter > 0) {
            printf(", %d",(i+20));
        }
    }
    printf("\n");
    iter = 0; // reset iteration variable

    printf("The lowest count was at %d, at ", min_count);
    // checks and prints all numbers at the min count value
    for (int i = MIN_VAL; i <= MAX_VAL; i++) {
        if (numcount[(i+20)] == min_count && iter ==0) {
            printf("%d",(i+20));
            iter++;
        } else if (numcount[(i+20)] == min_count && iter > 0) {
            printf(", %d",(i+20));
        }
    }
    printf("\n");

    //prints the histogram from -20 to 20 inclusive
    printf("The complete histogram is:\n");
    for(int i = MIN_VAL; i<= MAX_VAL; i++){
        printf("%d -> %d\n", i, numcount[(i+20)]);
    }
}

int main(void) {
    int x;
    while (1 == scanf("%d", &x)) {
        process(x);
    }
    post_process();
    print();
    return 0;
}