#include <stdio.h>

int ShowFibNth(int a, int b){
    if(a == 1)
        return 1;
    printf("%d\n", b-a);
    return ShowFibNth(b-a, a);
}

int main(){
    int a, b;
    scanf("%d%d",&a,&b);
    if(a != 1 && b != 1)
        printf("%d\n", a);
    printf("%d", ShowFibNth(a, b));
}
