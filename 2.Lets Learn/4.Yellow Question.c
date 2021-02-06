#include <stdio.h>

int main(){
	int x;
	scanf("%d", &x);

	char wow[15];
	wow[0] = 'W';
	int last = 0;
	for(int i=1; i<=x; i++){
		wow[i] = 'o';
		last = i;
	}
	wow[last+1] = 'w';
	wow[last+2] = '!';
	wow[last+3] = '\0';
	printf("%s", wow);
}
