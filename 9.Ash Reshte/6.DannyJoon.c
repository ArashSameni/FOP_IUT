#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

//ye moshkel ke age 5 ta char check kard char 6 yeki nabod baiad 5 ta bargarde aghab baz
char* mystrstr(char* mainstr,char* str){
    int pos = 0;
	int finding = 0;
    int count = 0;
    char* first;
    for (int i = 0; i < strlen(mainstr); i++)
    {
        if(mainstr[i] == str[pos])
        {
			if(finding)
            {
                pos++;
                if(pos == strlen(str))
                    return first;
            }
			else
			{
                pos = 1;
                first = &mainstr[i];
            }
			finding = 1;
		}else
		{
            if(finding)
                i--;
            finding = 0;
            pos = 0;
        }
    }
	return 0;
}

int main(){
	int countOfOrders = 0, mizanKhobi = 0;
	char text[MAX];
	scanf("%s", text);

	char inp[MAX];
	do{
		scanf("%s", inp);
		if(strcmp(inp, "copy") == 0){
			countOfOrders++;
			char cpText[MAX];
			scanf("%s", cpText);
			int cpCount;
			scanf("%d", &cpCount);
			int cpTextLen = strlen(cpText);
			for (int i = cpTextLen; i < cpCount * cpTextLen; i++)
				cpText[i] = cpText[i % cpTextLen];
			strncpy(text, cpText, cpCount * cpTextLen);
		}
		else if(strcmp(inp, "compare") == 0){
			countOfOrders++;
			char cmpText[MAX];
			scanf("%s", cmpText);
			if(strcmp(cmpText, text) == 0)
				mizanKhobi++;
		}
		else if(strcmp(inp, "substr") == 0){
			countOfOrders++;
			char subText[MAX];
			scanf("%s", subText);
			int subCount;
			scanf("%d", &subCount);
			int counter = 0;
			char *temp = (char *)malloc(sizeof(char) * MAX);
			strcpy(temp, text);
			
			while(mystrstr(temp, subText)){
				counter++;
				temp = mystrstr(temp, subText) + 1;
			}
			if(counter == subCount)
				mizanKhobi++;
		}
		else if(strcmp(inp, "attach") == 0){
			countOfOrders++;
			char atText[MAX];
			scanf("%s", atText);
			int atCount;
			scanf("%d", &atCount);
			char str[MAX];
			scanf("%s", str);
			strcat(atText, str);

			int counter = 0;
			char *temp = (char *)malloc(sizeof(char) * MAX);
			strcpy(temp, text);
			
			while(mystrstr(temp, atText)){
				counter++;
				temp = mystrstr(temp, atText) + 1;
			}
			if(counter == atCount)
				mizanKhobi++;
		}
		else if(strcmp(inp, "length") == 0){
			countOfOrders++;
			int len;
			scanf("%d", &len);
			if(strlen(text) == len)
				mizanKhobi++;
		}
	}while(strcmp(inp, "Is"));
	if(mizanKhobi >= (countOfOrders/2))
		printf("Eyval");
	else
		printf("HeifShod");
	return 0;
}
