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

int main(){
    int n;
    scanf("%d", &n);
    int capsLock = 0;
    for (int i = 0; i < n; i++)
    {
        char inp[5];
        scanf("%s", inp);
        if(inp[0] == 'C')
            capsLock = !capsLock;
        else if(!capsLock)
            printf("%c", tolower(inp[0]));
        else
            printf("%c", toupper(inp[0]));
    }
    
    return 0;
}
