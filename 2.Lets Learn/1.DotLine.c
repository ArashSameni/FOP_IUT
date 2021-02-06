#include <stdio.h>

int main(){
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	if(y1 == y2)
		printf("Horizontal");
	else if(x1 == x2)
		printf("Vertical");
	else
		printf("Try again");
}
