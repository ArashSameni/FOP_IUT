#include <stdio.h>

int main(){
	int x1,x2,x3;
	scanf("%d%d%d", &x1, &x2, &x3);
	int a = 0,b = 0,c = 0;

	if(x1 > x2 && x1 > x3)
	{
		c = x1;
		b = x2>x3?x2:x3;
		a = x2>x3?x3:x2;
	}
	else if(x2 > x1 && x2 > x3)
	{
		c = x2;
		b = x3>x1?x3:x1;
		a = x3>x1?x1:x3;
	}
	else{
		c = x3;
		b = x2>x1?x2:x1;
		a = x2>x1?x1:x2;
	}
	char inp[5];
	scanf("%s", inp);

	if(inp[0] == 'A' && inp[1] == 'B')
		printf("%d %d %d", a, b, c);
	else if(inp[0] == 'A' && inp[1] == 'C')
		printf("%d %d %d", a, c, b);
	else if(inp[0] == 'B' && inp[1] == 'A')
		printf("%d %d %d", b, a, c);
	else if(inp[0] == 'B' && inp[1] == 'C')
		printf("%d %d %d", b, c, a);
	else if(inp[0] == 'C' && inp[1] == 'A')
		printf("%d %d %d", c, a, b);
	else if(inp[0] == 'C' && inp[1] == 'B')
		printf("%d %d %d", c, b, a);
}
