#include <stdio.h>

void tennis_anyone( void ) {
	char a;
	char b;
	
    printf("How does the weather look?\ns - sunny\no - overcast\nr - rainy\n");
	
	scanf(" %c", &a);

	if (a == 's') {
		printf("Please rate the humidity:\nh - high\nn - normal\n");
		scanf(" %c", &b);
		if (b == 'h') {
			printf("Tennis is cancelled due to high humidity!\n");
		} else if (b == 'n') {
			printf("Tennis will be played!\n");
		} else {
			printf("Invalid choice for humidity: '%c'\n",b);
			printf("Valid options are 'h', and 'n'.\n");
		}
	} 
	else if (a == 'r') {
		printf("Please rate the wind strength:\nw - windy\nc - calm\n");
		scanf(" %c", &b);
		if (b == 'w') {
			printf("Tennis is cancelled due to rain and high winds!\n");
		} else if (b == 'c') {
			printf("Tennis will be played!\n");
		} else {
			printf("Invalid choice for wind: '%c'\n",b);
			printf("Valid options are 'w', and 'c'.\n");
		}
	} else if (a == 'o') {
		printf("Tennis will be played!\n");
	} else {
		printf("Invalid choice for outlook: '%c'\n",a);
		printf("Valid options are 's', 'o', and 'r'.\n");
	}
}

int main(void) {
	tennis_anyone();
	return 0;
}