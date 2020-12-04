#include <stdio.h>

int main(){
	int x1,x2,x3;
	scanf("%d%d%d", &x1, &x2, &x3);

	if(x1 == 0 || x2 == 0 || x3 == 0){
		printf("NO");
	}else{
		if(x1*x1 == x2*x2 + x3*x3)
			printf("YES");
		else if(x2*x2 == x1*x1 + x3*x3)
			printf("YES");
		else if(x3*x3 == x1*x1 + x2*x2)
			printf("YES");
		else
			printf("NO");
	}
}
