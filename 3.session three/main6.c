#include <stdio.h>


int main(){
	int y[4];
	scanf("%d%d%d%d", &y[0], &y[1], &y[2], &y[3]);
	int x[4];
	x[0] = 1;
	x[1] = 2;
	x[2] = 3;
	x[3] = 4;

	int done = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if(y[i] == y[j] || (x[i]-y[i] == x[j]-y[j]) || (x[i] == y[j] && x[j] == y[i]))
			{
				printf("NO");
				done = 1;
				i = 5;
				j = 5; // :DDDD
			}
		}
	}

	if(!done)
		printf("YES");
}
