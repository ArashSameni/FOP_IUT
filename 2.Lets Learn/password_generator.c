#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	srand(time(NULL));
	char lower[30] = "abcdefghijklmnopqrstuvwxyz";
    char upper[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char nums[15] = "0123456789";
    char symbols[10] = "!@#$\%^&*";
    char password[20];

	char diff;

	printf("(w)eak or (s)trong password: ");
	scanf("%c", &diff);

	while(diff != '0'){
		int lastChar = 0;
		if(diff == 's'){
			for(int i=0;i<16;i++){
				switch (rand() % 4)
				{
					case 0:
						password[i] = lower[rand() % 26];
						break;
					case 1:
						password[i] = upper[rand() % 26];
						break;
					case 2:
						password[i] = nums[rand() % 10];
						break;
					case 3:
						password[i] = symbols[rand() % 8];
						break;
					default:
						break;
				}
				lastChar = i+1;
			}
		}
		else if(diff == 'w')
		{
			for(int i=0;i<12;i++){
				switch (rand() % 2)
				{
					case 0:
						password[i] = lower[rand() % 26];
						break;
					case 1:
						password[i] = upper[rand() % 26];
						break;
					default:
						break;
				}
				lastChar = i+1;
			}
		}
		password[lastChar] = '\0';
		printf("%s", password);
		printf("\n");
		scanf("%c", &diff);
	}

	
}
