#include <stdio.h>
#include <stdlib.h>

void process(uint8_t b);

int main(void) {
    int x;
    while (1 == scanf("%d", &x)) {
        if (x & 255) {
            process(x & 255);
        }
    }
    return 0;
}

void process(uint8_t b) {
    printf("%d ->", b);
    for (int i = 7; i >= 0; i--) {
        if (!((b >> i) & 1)) printf(" %d", i);
    }
    printf("\n");
}

// ANSWER
// Results: When executed via command
// echo "8 22 54 61 68 70 150 214 236 243" | ./example
// the resulting output is
// 8 -> 7 6 5 4 2 1 0
// 22 -> 7 6 5 3 0
// 54 -> 7 6 3 0
// 61 -> 7 6 1
// 68 -> 7 5 4 3 1 0
// 70 -> 7 5 4 3 0
// 150 -> 6 5 3 0
// 214 -> 5 3 0
// 236 -> 4 1 0
// 243 -> 3 2

// Process: The process function lists the indices of all bits that are non-zero in the binary representation of parameter b, which is assumed to be non-zero.
// The indices appear in order with more significant bits appearing before less significant bits.

// Basically it is showing the positions of the binary number where there is a 0. E.G., 8 => 0 0 0 0 1 0 0 0
//                                                                                  index => 7 6 5 4 3 2 1 0
