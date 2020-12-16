#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *fixString(char *str);

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char str[100];
        scanf("%[^\n]%*c", str); 
        printf("%s\n", fixString(str));
    }
    
}

char *fixString(char *str){
    unsigned char *p = (unsigned char *)str;

    *p = toupper(*p);
    p++;
    while (*p) {
        if(*p != ' ')
            *p = tolower(*p);
        else
        {
            p++;
            *p = toupper(*p);
        }
        p++;
    }

    return str;
}
