#include <stdio.h>

int fib(int n){
    return (n == 1 || n == 2)? 1 : fib(n-1) + fib(n-2);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d",  fib(n));
}
