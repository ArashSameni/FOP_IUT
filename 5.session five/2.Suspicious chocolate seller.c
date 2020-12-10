#include <stdio.h>

int main(){
	int a1, a2, a3;
    scanf("%d%d%d", &a1, &a2, &a3);

    a1 %= 2;
    a2 %= 2;
    a3 %= 2;

    if(a1 == 0 && a2 == 1 && a3 == 1)
        printf("YES ");
    else if(a1 == 1 && a2 == 0 && a3 == 0)
        printf("YES ");
    else
        printf("NO ");

    if(a1 == 1 && a2 == 0 && a3 == 1)
        printf("YES ");
    else if(a1 == 0 && a2 == 1 && a3 == 0)
        printf("YES ");
    else
        printf("NO ");

    if(a1 == 1 && a2 == 1 && a3 == 0)
        printf("YES");
    else if(a1 == 0 && a2 == 0 && a3 == 1)
        printf("YES");
    else
        printf("NO");
}
