#include <stdio.h>

int power(int n, int pow){
    int ans = 1;
    for (int i = 0; i < pow; i++)
        ans *= n;
    return ans;
}

int shouldICheck(int num,int n){
	while (num > 0)
	{
		if(num%10 != 1 && num%10 != 2 && num%10 != 3 && num%10 != 5 && num%10 != 7 && num%10 != 9)
			return 0;
		num /= 10;
	}
	return 1;
}

int isPrime(int n){
	int flag = 0;
	for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
	if(n == 1)
		return 0;
	if (flag == 0)
		return 1;
	else
		return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    int i = power(10, n-1);
    for (int j = n-2; j >= 0; j--)
        i += power(10, j);
        
    for (i; i < power(10, n); i += 2)
    {
        long int temp = i;
        int joonSakht = 1;
        while(temp > 0){
			for (int x = n-1; x >= 1; x--)
			{
				if(!isPrime(temp / power(10, x))){

					i += power(10, x);
					i -= i%power(10, x);
					i -= 1;
					joonSakht = 0;
				}
			}
			if(!joonSakht)
				break;
			if(shouldICheck(temp, n)){
				if(!isPrime(temp)){
					joonSakht = 0;
					break;
				}
				temp /= 10;
			}else
			{
				joonSakht = 0;
				break;
			}
        }
        if(joonSakht)
            printf("%i\n", i);
    }
}
