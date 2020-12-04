#include <stdio.h>
#include <math.h>

int main(){
	float x, y;

	scanf("%f%f", &x, &y);

	int distance = sqrt((x*x)+(y*y));

	printf("%d", distance);
	return 0;
}
