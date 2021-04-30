#include <stdio.h>

void echo_char() {
	char ch;
	
	printf("Please enter a character:");
	
	scanf(" %c", &ch);

	printf("\nYou supplied the character '%c'. Thank you.\n",ch);

	printf("The code for character '%c' is %d.\n",ch,ch);
}


int main() {
	echo_char();
	return 0;
}
