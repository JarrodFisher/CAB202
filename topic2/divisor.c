#include <stdio.h>

void is_divisible( void ) {

	printf("Please enter integers X and Y, separated by one or more space characters:");

	int a;
	int b;
	int temp;
	
	scanf( "%d %d", &a, &b );
	
	temp = a%b;

	if (temp != 0){
		printf("\nX is not divisible by Y.\n");
	} else {
		printf("\nX is divisible by Y.\n");
	}
}


int main() {
	is_divisible();
	return 0;
}