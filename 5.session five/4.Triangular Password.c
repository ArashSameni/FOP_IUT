#include <stdio.h>
#include <math.h>

int fact(int n){
	int res=1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}

int main(){
	int tedad;
	scanf("%d", &tedad);

	printf("1\n");
	if(tedad > 1){
		for (int n = 1; n < tedad; n++)
		{
			printf("1 ");

			for (int i = 1; i < n; i++)
			{
				int num = 1;
				for (int x = n; x > n-i; x--)
					num *= x;
				
				num /= fact(i);
				printf("%d ", num);
			}

			printf("1\n");
		}
	}
}
