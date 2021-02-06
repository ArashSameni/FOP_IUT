#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sortString(char* str){
    char temp;
    for (int i = 0; i < strlen(str)-1; i++) {
        for (int j = i+1; j < strlen(str); j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
    char code[102] = {};
    scanf("%s", code);
    char keys[102] = {};
    int pos = 0;
    for (int i = 0; i < strlen(code); i++)
        if(!(strchr(keys, code[i])))
        {
            keys[pos] = code[i];
            pos++;
        }
    sortString(keys);

    for (int z = 0; z < n; z++)
    {
        char temp[102] = {};
        scanf("%s", temp);
        pos = 0;
        char tempKey[102] = {};

        for (int i = 0; i < strlen(temp); i++)
        if(!(strchr(tempKey, temp[i])))
        {
            tempKey[pos] = temp[i];
            pos++;
        }
        sortString(tempKey);
        if(strcmp(keys, tempKey) == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    
}
