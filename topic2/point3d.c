#include <stdio.h>

void point_3d( void ) {
    double x;
	double y;
	double z;
	
	printf("Please provide values for X and Y:");
	
	scanf(" %lf %lf", &x, &y);
	
	if (x >= 0 && y >= 0){
		z=(3.60516*x)+(3.45722*y);
		printf("\nThe resulting point is (%.3lf, %.3lf, %.3lf).\n", x, y, z);
	} else if (x >= 0 && y < 0){
		z=(3.60516*x)+(y*y);
		printf("\nThe resulting point is (%.3lf, %.3lf, %.3lf).\n", x, y, z);
	} else if (x < 0 && y >= 0){
		z=(x*x)+(3.45722*y);
		printf("\nThe resulting point is (%.3lf, %.3lf, %.3lf).\n", x, y, z);
	} else {
		z=(x*x)+(y*y);
		printf("\nThe resulting point is (%.3lf, %.3lf, %.3lf).\n", x, y, z);
	}
}


//int main() {
//	point_3d();
//	return 0;
//}