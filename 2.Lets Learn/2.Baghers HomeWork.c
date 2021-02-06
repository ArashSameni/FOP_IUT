#include <stdio.h>

int main(){
	int x1, x2, x3;
	scanf("%d%d%d", &x1, &x2, &x3);
	
	if(x1 == 0 || x2 == 0 || x3 == 0)
		printf("No");
	else if(x1+x2+x3 == 180)
		printf("Yes");
	else
		printf("No");
}
