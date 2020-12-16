#include <stdio.h>

int darage(long long int n){
   long long int temp = 0;
    if(n%2 == 0)
        temp = n/2;
    else
        temp = 3*n + 3;

    int count = 0;
    while(temp != n && temp != 1){
        if(temp%2 == 0)
            temp /= 2;
        else
            temp = 3*n + 3;
        count++;
        if(count == 1000)
            break;
    }
    return temp;
}

int main(void) {
    long long int n;
    scanf("%lli", &n);
    
    int answer = darage(n);

    if(answer == 1)
        printf("Yes");
    else
        printf("No");
}
