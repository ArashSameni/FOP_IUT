#include <stdio.h>
#include <string.h>

int sortStrings(char* str1, char* str2){
    char t1 = *str1;
    char t2 = *str2;
    if(t1 >= 97)
        t1 -= 32;
    if(t2 >= 97)
        t2 -= 32; 
    if((t1 > t2) || (t1 == t2 && *(str1) > *(str2)))
    {
        char temp[1001];
        strcpy(temp, str1);
        strcpy(str1, str2);
        strcpy(str2, temp);
        return 1;
    }else if(*(str1) == *(str2)){
        t1 = *(str1+1);
        t2 = *(str2+1);
        if(t1 >= 97)
            t1 -= 32;
        if(t2 >= 97)
            t2 -= 32;
        if((t1 > t2) || (t1 == t2 && *(str1+1) > *(str2+1)))
        {
            char temp[1001];
            strcpy(temp, str1);
            strcpy(str1, str2);
            strcpy(str2, temp);
            return 1;
        }
    }
    return 0;
}

int main() {
    char names[1000][1001] = {};
    int i;
    for (i = 0; i < 1000; i++)
    {
        scanf("%s", names[i]);
        if(names[i][0] == '0' && strlen(names[i]) == 1)
        {
            names[i][0] = '\0';
            break;
        }
    }
    int swapped = 0;
    do{
        swapped = 0;
        for (int z = 0; z < i-1; z++)
        {
            int temp = sortStrings(names[z], names[z+1]);
            if(temp)
                swapped++;
        }
    }
    while(swapped);

    for (int j = 0; j < i; j++)
        printf("%s ", names[j]);
    
    return 0;
}
