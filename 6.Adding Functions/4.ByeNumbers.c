#include <stdio.h>

int digits(long long int num){
    int count = 0;
    while(num > 0){
        count++;
        num /= 10;
    }
    return count;
}

int byeNumbers(long long int n){
   while(digits(n) > 1){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n /= 10;
        }
        n = sum;
    }
    return n;
}

int main(void) {
    long long int n;
    scanf("%lli", &n);
    
    printf("%d", byeNumbers(n));
}
