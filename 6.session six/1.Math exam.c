#include <stdio.h>
#include <math.h>

long double answer(int x, int n){
   long double res = 0;
	for (long long int i = 0; i < n; i++)
	{
		long long int fac = 1;
		for (long long int j = 1; j <= i; ++j)
            fac *= j;
		res += pow(x, i) / fac;
	}
   return res;
}

int main(){
	float x;
   int n;
	scanf("%f%d", &x, &n);
   if(n > 20)
      n = 20;
	
	long double res = answer(x, n);

	printf("%.3Lf", res);
}
