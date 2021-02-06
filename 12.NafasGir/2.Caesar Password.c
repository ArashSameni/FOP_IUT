#include <stdio.h> 
#include <string.h> 

char decrypt(char c, int key){ 
    c -= key;
    if(c < 'a')
        c = 'z' - (('a' - c) - 1);
    return c;
}

int main() 
{
    char cin, cout;
    scanf("%c", &cin);
    while(cin == '\n' || cin == ' ')
        scanf("%c", &cin);

    scanf("%c", &cout);
    while(cout == '\n' || cout == ' ')
        scanf("%c", &cout);

    char encrypted[100] = {};
    scanf("%s", encrypted);

    int key = cout - cin;
    if(key < 0)
        key = key + 26;

    for (int i = 0; i < strlen(encrypted); i++)
        encrypted[i] = decrypt(encrypted[i], key);
    
    printf("%s", encrypted);
}
