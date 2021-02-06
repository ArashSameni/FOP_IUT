#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100010

void removeSpaces(char* text){
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if(text[i] == ' ' || text[i] == '.' || text[i] == '?' || text[i] == ';' || text[i] == '!' || text[i] == '"' || text[i] == 'ØŒ' || text[i] == '\''){
            for (int j = i+1; j < len; j++)
                text[j - 1] = text[j];
            text[len - 1] = '\0';
            len--;
            i--;
        }
    }
}

int IsPalindrome(char* text, int pos){
    int len = strlen(text);
    if(pos == (len / 2))
        return 1;
    if(tolower(text[pos]) != tolower(text[len - pos -1]))
        return 0;
    else
        return IsPalindrome(text, pos+1);
}

int main(){
    char str[MAX] = {};
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    removeSpaces(str);
    if(IsPalindrome(str, 0))
        printf("YES");
    else
        printf("NO");
    return 0;
}
