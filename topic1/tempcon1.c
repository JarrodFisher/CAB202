#include <stdio.h>

void far2cel(void) {
	// (a) Prompt user to enter value.
	printf("Please enter the temperature in Fahrenheit degrees:\n");
	
	// (b) Declare local variable to hold input value.
	double F,C;
	
	// (c) Read input value.
	scanf("%lf", &F);
	
	// (d) Compute output value.
	C = (5.0/9.0)*(F-32);
	
	// (e) Display the result.
	printf("A temperature of %.4lf degrees Fahrenheit is equal to %.4lf degrees Celsius.\n",F,C);
}

int main(void) {
	far2cel();
	return 0;
}
