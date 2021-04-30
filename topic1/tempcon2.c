#include <stdio.h>

void cel2far(void) {
	// (a) Prompt user to enter value.
	printf("Please enter the temperature in Celsius degrees:\n");
	
	// (b) Declare local variable to hold input value.
	double F,C;
	
	// (c) Read input value.
	scanf("%lf", &C);
	
	// (d) Compute output value.
	F = ((9.0/5.0)*(C))+32;
	
	// (e) Display the result.
	printf("A temperature of %.4lf degrees Celsius is equal to %.4lf degrees Fahrenheit.\n",C,F);
}

int main(void) {
	cel2far();
	return 0;
}
