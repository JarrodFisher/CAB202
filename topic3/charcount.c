#include <stdio.h>

void count_chars() {
    int cn=0;
    char st;
	int flag = 0;

    while (flag == 0) {
		int sVal = scanf("%c",&st);

		if (sVal == EOF) {
		    break;
		}
		cn++;
    }
    printf("The document contains %d characters.\n",cn);
}


int main() {
    count_chars();
    return 0;
}