#include <stdio.h>
#include <string.h>
#include <ctype.h>

int digits(char* str){
    int count = 0;
    while(*str){
        count++;
        str++;
    }
    return count;
}

int mystrstr(char* mainstr,char* str, int n){
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if(*mainstr == str[pos])
            pos++;
        else
            return pos;
        mainstr++;
    }
    return pos;
}

int main(){
    int n1;
    scanf("%d", &n1);
    char inp1[n1+1];
    scanf("%s", inp1);

    int n2;
    scanf("%d", &n2);
    char inp2[n2+1];
    scanf("%s", inp2);

    int deleted = mystrstr(inp1, inp2, n1);

    int count = n1 - deleted;
    count += n2 - deleted;
    printf("%d", count);
    return 0;
}
