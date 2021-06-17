#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define MIN_VAL 'a'
#define MAX_VAL 'z'
#define ALPHABET 26

int max_count = 0;
int min_count = 0;
int letterCount[ALPHABET];


void process(int x) {
    // Process one value here.
    for (int i = MIN_VAL; i <= MAX_VAL; i++){
        if (x == i || x == (i-32)){         // accounts for ASCII Table value of lower case and upper case letters.
            ++letterCount[i];               // ASCII Capital letter values are exactly 32 Decimal numbers less than lowercase
        }
    }
}

void post_process(){

// To find the max and min count values
    max_count = letterCount[0];
    min_count = letterCount[0];

    for(int i = MIN_VAL; i<MAX_VAL; i++){   // For the number of letters in the Alphabet
        if(letterCount[i]<min_count){       // If the count for that specific letter is less than the stored min_count
            min_count = letterCount[i];     // That letter becomes the new min_count
         }
        if(letterCount[i]>max_count){       // Same as above but with max_count instead of min count
            max_count = letterCount[i];
         }
    }
}

void print(){
// Print output.
    int printIter = 0;       // Print Iter is the iteration of how many letters have been printed for their corresponding count.

    printf("The highest count is %d, at ", max_count);
    for(int i = MIN_VAL; i <= MAX_VAL; i++) {
        if(letterCount[i] == max_count && printIter == 0){  // If there is only one letter that has the max_count value
            printf("%c", i);                                // Print only that letter
            printIter++;                                    // Make the print iteration number go up one so it can check
        }                                                   // if there are others
        else if(letterCount[i] == max_count && printIter > 0){
            printf(", %c", i);                              // If there is another letter than the first one which
        }                                                   // contains the max_count value, it is also printed
    }
    printf("\n");

    printIter = 0;                                          // Resets Print Iteration to 0

    printf("The lowest count is %d, at ", min_count);
    for(int i = MIN_VAL; i <= MAX_VAL; i++) {           // Same as above but working with min_count now
        if(letterCount[i] == min_count && printIter == 0){
            printf("%c", i);
            printIter++;
        }
        else if(letterCount[i] == min_count && printIter > 0){
            printf(", %c", i);
        }
    }
    printf("\n");

    printf("The complete histogram is:\n");
    for(int i = MIN_VAL; i<= MAX_VAL; i++){
        printf("%c -> %d\n", i, letterCount[i]);        // Prints each (lowercase) letter of the alphabet with their
    }                                                   // corresponding count value.
}

int main(void)  {
    char ch;
    while (1 == scanf("%c", &ch)){
        process(ch);
    }
    post_process();
    print();
    return 0;
}
