#include <stdio.h>
#include <math.h>

int digits(long int num){
    int counter = 0;
    while(num > 0)
    {
        counter ++;
        num /= 10;
    }
    return counter;
}

int main(){
  long int num;
    scanf("%li", &num);
    int digs = digits(num);
    int count = 0;
    for (int i = 1; i < digs; i++)
        count += (int)pow(2, i-1);
        
    for (long int i = pow(10, digs-1); i <= num; i++)
    {
        long int temp = i;
        int is = 1;
        while(temp > 0){
            if(temp % 10 != 1 && temp % 10 != 0)
            {
                is = 0;
                break;
            }
            temp /= 10;
        }
        if(is)
            count++;
    }
    
    printf("%d", count);
}
