#include <stdio.h>
#include <math.h>

int main(){
	unsigned int a, b; // b kochike
	scanf("%d%d", &a, &b);
	if(b >= a)
		printf("Wrong order!");
	else if((a-b)%2 != 0)
		printf("Wrong difference!");
	else{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				if((i < (a-b)/2 || i >= a-((a-b)/2)) || (j < (a-b)/2 || j >= a-((a-b)/2)))
					printf("* ");
				else
					printf("  ");
				
			}
			printf("\n");
		}
		
	}
}
