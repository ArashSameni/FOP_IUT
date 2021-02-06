#include <stdio.h>
#include <math.h>

int findGroup(int num){
    int counter = 0;
    int sum = 0;
    if(num%2 == 0)
        num /= 2;
    else
        num = (num-1)/2;
    while (sum < num)
    {
        sum += pow(2, counter-1);
        counter++;
    }
    return counter-1;
}

int main(){
    int n;
    scanf("%d", &n);
    int group = findGroup(n);
    if(n%2 == 1){
        n = (n-(pow(2, group)))/2;
        n++;
        printf("%d", 4*n-1);
    }
    else{
        n = (n-(pow(2, group)))/2;
        n++;
        printf("%d", 4*n-3);
    }
       
    
    return 0;
}
