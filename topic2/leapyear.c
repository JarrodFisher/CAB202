#include <stdio.h>

void is_leap( void ) {
    printf("What year would you like to check?\n");
	
	int y;
	int a;
	int b;
	int c;
	
	scanf("%d", &y);
	
	a = y%4;
	b = y%100;
	c = y%400;

	printf("a %d, b %d, c %d\n", a, b, c);
	
	if (b == 0 && c == 0){
		printf("The year %d is a leap year.\n",y);
	} else if (a == 0 && b == 0){
		printf("The year %d is not a leap year.\n",y);
	} else if (a == 0){ 
		printf("The year %d is a leap year.\n",y);
	} else {
		printf("The year %d is not a leap year.\n",y);
	}
}


int main() {
	is_leap();
	return 0;
}