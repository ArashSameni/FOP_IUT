#include <stdio.h>
#include <math.h>

int main(){
	int num;
	scanf("%d", &num);

	int x = num;
	int counter = 0;
	while(x>0)
	{
		x /= 10;
		counter++;
	}
	
	int y = num;

	if(counter == 1)
		x = y;
	else
		for (int i = counter-1; i >= 0; i--)
		{
			int aDigit = y%10;
			y /= 10;
			x += aDigit * pow(10,i);
		}

	if(x == num)
		printf("YES");
	else
		printf("NO");
}
