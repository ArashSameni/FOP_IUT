#include <stdio.h>

int main(){
	int num;
	scanf("%d", &num);

	int sum = 0;
	for(int i=1;i<num;i++){
		if(num%i==0)
			sum+=i;
	}
	if(sum == num)
		printf("YES");
	else
		printf("NO");
}
