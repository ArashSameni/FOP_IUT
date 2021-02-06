#include <stdio.h>
#include <math.h>

int main(){
	int num, mabna1, mabna2;
	scanf("%d%d%d", &num, &mabna1, &mabna2);

	
	int Mabna10 = 0;
	if(mabna1 != 10){
		int x = num;
		int tavan = 0;
		while(x>0){
			Mabna10 += (x%10) * pow(mabna1, tavan);
			tavan++;
			x /= 10;
		}
	}
	else
	{
		Mabna10 = num;
	}
	
	char num_mabna[100];
	int count = 0;

	while(Mabna10 > 0){
		num_mabna[count] = (Mabna10%mabna2) + 48;
		Mabna10 /= mabna2;
		count++;
	}
	
	for (int i = 0; i < count; i++)
	{
		if(num_mabna[i] != num_mabna[count-i-1]){
			printf("NO");
			break;
		}else if(i == count - 1)
			printf("YES");
	}
}
