#include <stdio.h>

int digits(char* num){
    char* p = num;
    int counter = 0;
    while(*p)
    {
        p++;
        counter++;
    }
    return counter;
}

int power(int n, int pow){
    int ans = 1;
    for (int i = 0; i < pow; i++)
        ans *= n;
    return ans;
}

int main(){
    char num[100];
    scanf("%s", num);
    int digs = digits(num);
    int count = 0;
    
    for (int i = 0; i < digs; i++)
    {
        if(num[i] > '1')
        {
            for (int j = i; j < digs; j++)
            {
                num[j] = '1';
            }
            break;
        }
    }

    int x = 0;
    for (int i = digs-1; i >= 0; i--)
    {
        if(num[i] > '0')
        {
            count += power(2, x);
        }
        x++;
    }

    printf("%d", count);
    return 0;
}
