#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void process(char ch);
int n = 0; 

int main(void) {
    char x;
    while (1 == scanf("%c", &x)) {
        process(x);
    }
    printf("n = %d\n", n);
    return 0;
}

void process(char ch) {
    static int p = 0;
    int q = isalnum(ch);
    if( p && (!q) ) n++;
    p = q;
}