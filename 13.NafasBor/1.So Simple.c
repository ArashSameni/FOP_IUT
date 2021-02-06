#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *ptr = (char *)malloc(1);
    int count = 0;
    int pos = 0;
    while (1)
    {
        scanf("%c", ptr + pos);
        if (ptr[pos] == '\n')
            break;

        if (pos > 0 && ptr[pos - 1] == '(' && ptr[pos] == ')')
        {
            pos -= 1;
            ptr = realloc(ptr, pos + 1);
        }
        else
        {
            pos++;
            ptr = realloc(ptr, pos + 1);
        }
    }
    pos -= 1;

    for (int i = pos; i > 0; i -= 2)
    {
        if(ptr[i-1] == ')'){
            if(ptr[i] == ')')
                count++;
            else if(ptr[i] == '(')
                count += 2;
        }
        else if(ptr[i-1] == '('){
            count++;
        }
        ptr = realloc(ptr, i-1);
    }
    
    printf("%d", count);
    return 0;
}
