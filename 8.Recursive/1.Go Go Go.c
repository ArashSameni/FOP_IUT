#include <stdio.h>

int TaabeKhodameeeee(int n){
    static int count = 0;
    if(n >= 5){
        TaabeKhodameeeee(n-5);
        TaabeKhodameeeee(n-2);
        TaabeKhodameeeee(n-1);
        return count;
    }
    else if(n >= 2)
    {
        TaabeKhodameeeee(n-1);
        TaabeKhodameeeee(n-2);
        return count;
    }
    else if(n == 0 || n == 1){
        count += 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d",TaabeKhodameeeee(n));
    return 0;
}
