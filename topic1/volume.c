#include <stdio.h>
#include <math.h>

void vol_cyl(void) {
    double r,h,V;

	printf("Please enter the radius of the cylinder:\n");
	scanf("%lf",&r);

    printf("Please enter the height of the cylinder:\n");
    scanf("%lf",&h);

    V = M_PI*(r*r)*h;

    printf("A radius of %.5lf and a height of %.5lf correspond to a volume of %.5lf.\n",r,h,V);
}

int main(void) {
	vol_cyl();
	return 0;
}
