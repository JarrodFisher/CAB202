#include <stdio.h>
#include <math.h>

void area_circ(void) {
	// (a) Prompt user to enter value.
	printf("Please enter the radius of the circle:\n");
	
	// (b) Declare local variable to hold input value.
	double r,A;
	
	// (c) Read input value.
	scanf("%lf", &r);
	
	// (d) Compute output value.
    A = M_PI*(r*r);

	// (e) Display the result.
	printf("A radius of %.5lf corresponds to an area of %.5lf.\n",r,A);
}

int main(void) {
	area_circ();
	return 0;
}
