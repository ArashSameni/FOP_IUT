#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mystrstr(char* mainstr,char* str){
    while(*mainstr){
        if (tolower(*mainstr) == tolower(*str))
        {
            str++;
            if(!*str)
                return 1;
        }
        mainstr++;
    }
  return 0;
}

int main(){
    char sub[500];
    scanf("%s", sub);
    int n;
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        char inp[500];
        scanf("%s", inp);
        if(mystrstr(inp, sub))
            count++;
    }
    printf("%d", count);
    return 0;
}
