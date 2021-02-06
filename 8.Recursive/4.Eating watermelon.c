#include <stdio.h>

int n;

int removeHendoone(int weight[], int i, int j){ // Vali bazam tabe khodameeeeeee :D
    if(j == n)
        if(weight[i] <= weight[j])
            return j;
        else
            return i;
        
    if(weight[i] <= weight[j])
        return removeHendoone(weight, j, j+1);
    else
        return removeHendoone(weight, i, j+1);
    
}

int main(){
    scanf("%d", &n);
    int weight[n+1];
    for (int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    printf("%d", removeHendoone(weight, 1, 2));
    return 0;
}
