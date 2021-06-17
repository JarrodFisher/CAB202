#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define MIN_VAL 'a'
#define MAX_VAL 'z'
#define al 26

int hCount; // Highest count
int lCount; // Lowest Count
int count[al]; // Histogram array

void process(int x) {
    // Process one value here.
    for (int i = MIN_VAL; i <= MAX_VAL; i++) {
        if (x == i || x == (i-32)) { // accounts for lower and uppercase letters only in the counter
            ++count[i];
        }
    }
}

void post_process() {
    // Compute derived results here.
    hCount = count[0];
    lCount = count[0];

    for (int i = MIN_VAL; i <= MAX_VAL; i++) { // For iterating the counter a thru z
        if (count[i]<lCount) {                 // if count at index for letter is less than
            lCount = count[i];                 // the lowest count, set new lowest count
        }
        
        if (count[i]>hCount) {                 // ditto for highest count
            hCount = count[i];
        }
    } 
}

void print(){
// Print output.
    int printIter = 0;       // Print Iter is the iteration of how many letters have been printed for their corresponding count.

    printf("The highest count is %d, at ", hCount);
    for(int i = MIN_VAL; i <= MAX_VAL; i++) {
        if(count[i] == hCount && printIter == 0){  // If there is only one letter that has the max_count value
            printf("%c", i);                                // Print only that letter
            printIter++;                                    // Make the print iteration number go up one so it can check
        }                                                   // if there are others
        else if(count[i] == hCount && printIter > 0){
            printf(", %c", i);                              // If there is another letter than the first one which
        }                                                   // contains the max_count value, it is also printed
    }
    printf("\n");

    printIter = 0;                                          // Resets Print Iteration to 0

    printf("The lowest count is %d, at ", lCount);
    for(int i = MIN_VAL; i <= MAX_VAL; i++) {           // Same as above but working with min_count now
        if(count[i] == lCount && printIter == 0){
            printf("%c", i);
            printIter++;
        }
        else if(count[i] == lCount && printIter > 0){
            printf(", %c", i);
        }
    }
    printf("\n");

    printf("The complete histogram is:\n");
    for(int i = MIN_VAL; i<= MAX_VAL; i++){
        printf("%c -> %d\n", i, count[i]);        // Prints each (lowercase) letter of the alphabet with their
    }                                                   // corresponding count value.
}

int main(void) {
    char ch;
    while (1 == scanf("%c", &ch)) {
        process(ch);
    }
    post_process();
    print();
    return 0;
}