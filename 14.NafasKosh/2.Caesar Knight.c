#include <stdio.h>
#include <string.h>

char decrypt(char c, int key)
{
    c -= key;
    if (c < 'a')
        c = 'z' - (('a' - c) - 1);
    return c;
}

int main()
{
    char enText[5000] = {};
    fgets(enText, 5000, stdin);
    enText[strlen(enText) - 1] = '\0';
    char deText[5000] = {};
    int j;
    for (j = 1; j <= 27; j++)
    {
        for (int i = 0; i < strlen(enText); i++)
        {
            if(enText[i] != ' ')
                deText[i] = decrypt(enText[i], j);
            else
                deText[i] = ' ';
        }
        if(strstr(deText, "zozagtoor"))
        {
            break;
        }
    }
    printf("%s", deText);
}
