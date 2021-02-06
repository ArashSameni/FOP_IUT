#include <stdio.h>
#include <string.h>
#define MAX 5000
char str[MAX] = {};

void shiftRight(int count){
    for (int i = 0; i < count; i++){
        for (int j = strlen(str); j > 0; j--)
            str[j] = str[j-1];
        str[0] = str[strlen(str) - 1];
        str[strlen(str)-1] = '\0';
    }
}

void shiftLeft(int count){
    for (int i = 0; i < count; i++){
        str[strlen(str)] = str[0];
        for (int j = 1; j < strlen(str); j++)
            str[j-1] = str[j];
        str[strlen(str)-2] = str[strlen(str)-1];
        str[strlen(str)-1] = '\0';
    }
}

void extend(int count){
    for (int i = 0; i < count; i++)
        str[strlen(str)] = '*';
}

void shrink(int count){
    for (int i = 0; i < count; i++)
        str[strlen(str) - 1] = '\0';
}

void reverse(){
    char *p1, *p2;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        char p = *p1;
        *p1 = *p2;
        *p2 = p;
    }
}

void put(int l, char c){
    str[l-1] = c;
}

int main() {
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    char order[10];
    do{
        scanf("%s", order);
        if(strcmp(order, "EXIT") == 0)
            break;
        else{
            if(strcmp(order, "PRINT") == 0)
                printf("%s\n", str);
            else if(strcmp(order, "SHIFT-R") == 0){
                int count;
                scanf("%d", &count);
                shiftRight(count);
            }
            else if(strcmp(order, "SHIFT-L") == 0){
                int count;
                scanf("%d", &count);
                shiftLeft(count);
            }
            else if(strcmp(order, "EXTEND") == 0){
                int count;
                scanf("%d", &count);
                extend(count);
            }
            else if(strcmp(order, "SHRINK") == 0){
                int count;
                scanf("%d", &count);
                shrink(count);
            }
            else if(strcmp(order, "REVERSE") == 0)
                reverse();
            else if(strcmp(order, "PUT") == 0){
                int l;
                scanf("%d", &l);
                char c;
                getchar();
                c = getchar();
                put(l, c);
            }
        }
    }while(1);
    return 0;
}
