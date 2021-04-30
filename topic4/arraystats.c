#include <stdio.h>

//  Declare Global variables here.
double term [34];
int term_count;
double term_mean, term_min, term_max;

void arraystats() {
    //  removes any junk AMS might throw in
    for (int i = 0; i < (sizeof(term)/sizeof(term[0]));i++) {
        term[i] = 0;
    }
    term_count = 0;
    term_mean = 0;

    //scans values into array and increments count
    while( term_count < 34 && scanf("%lf", &term[term_count]) == 1) {
        term_count++;
    }

    //calculates mean
    double temp = 0.0;
    for (int j = 0; j < (sizeof(term)/sizeof(term[0])); j++) {
        temp = temp + term[j];
    }
    term_mean = temp/term_count;

    //calculates max term
    term_max = term[0];
    for (int k = 1; k < (sizeof(term)/sizeof(term[0])); k++) {
        if (term[k]>term_max) {
            term_max = term[k];
        }
    }

    //calculates min term
    term_min = term[0];
    for (int l = 0; l < (sizeof(term)/sizeof(term[0])); l++) {
//        if (term[l]==0) {
//            break;
//        }
        if (term[l]<term_min) {
            term_min = term[l];
        }
    }

    if (term_count == 0) {
        term_min = 0;
        term_max = 0;
        term_mean = 0;
    }
}

#include <stdlib.h>
#include <time.h>

int main() {

    // Call submitted code.
    arraystats();

    // Display contents of array term.
    for (int i = 0; i < term_count; i++) {
        //printf("%f ", term[i]);
    }

    printf("\n");
    printf("Item count: %d\n", term_count);
    printf("Item mean : %f\n", term_mean);
    printf("Item min  : %f\n", term_min);
    printf("Item max  : %f\n", term_max);

    return 0;
}