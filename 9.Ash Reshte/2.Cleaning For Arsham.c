#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[n+1];
    scanf("%s", str);

    int start, end;
    scanf("%d%d",&start,&end);
    if(start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }
    int countOfH[n+1];
    for (int i = 0; i < n; i++)
        countOfH[i] = 0;
    
    int x = 0;
    for (int i = start; i < end-1; i++)
        if(str[i] == 'H')
            countOfH[x]++;
        else
            x++;
            
    int countOfTries = 0;
    for (int i = 0; i <= x; i++)
    {
        while(countOfH[i] > 0){
            countOfH[i] -= (int)pow(2, (int)(log(countOfH[i]) / log(2)));
            countOfTries++;
        }
    }
    
    printf("%d", countOfTries);
    return 0;
}
