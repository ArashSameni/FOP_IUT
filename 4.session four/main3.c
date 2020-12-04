#include <stdio.h>
#include <string.h>

int main(){
	char num[100];
    scanf("%s", num);

   int digits = 0;
   for (int i = 0; i < sizeof(num); i++)
   {
      if(num[i] != '\0')
         digits++;
      else
         break;
   }

    int zerosCount = 3 - (digits%3);
    if(zerosCount == 3)
        zerosCount = 0;

    char strNum[digits + zerosCount];
    for (int i = 0; i < zerosCount; i++)
        strNum[i] = '0';
    strNum[zerosCount] = '\0';
    strncat(strNum, num, digits);
    
    for (int i = 0; i < zerosCount + digits; i += 3)
    {
        char tripleNum[4];
        tripleNum[0] = strNum[i];
        tripleNum[1] = strNum[i+1];
        tripleNum[2] = strNum[i+2];
        tripleNum[3] = '\0';

        if(zerosCount + digits > 3){
            if(!strcmp(tripleNum,"000")){
                strNum[i] = '.';
                strNum[i+1] = '.';
                strNum[i+2] = '.';
            }else{
                break;
            }
        }
        if(i+3 >= zerosCount + digits)
        {
            strNum[i] = '0';
            strNum[i+1] = '0';
            strNum[i+2] = '0';
            strNum[i+3] = '\0';
        }
    }
    

    for (int i = 0; i < zerosCount + digits; i+=3)
    {
        char tripleNum[4];
        tripleNum[0] = strNum[i];
        tripleNum[1] = strNum[i+1];
        tripleNum[2] = strNum[i+2];
        tripleNum[3] = '\0';

        if(!strcmp(tripleNum,"000"))
            printf("%d", 0);
        else if(!strcmp(tripleNum,"001"))
            printf("%d", 1);
        else if(!strcmp(tripleNum, "010"))
            printf("%d", 2);
        else if(!strcmp(tripleNum, "011"))
            printf("%d", 3);
        else if(!strcmp(tripleNum, "100"))
            printf("%d", 4);
        else if(!strcmp(tripleNum, "101"))
            printf("%d", 5);
        else if(!strcmp(tripleNum, "110"))
            printf("%d", 6);
        else if(!strcmp(tripleNum, "111"))
            printf("%d", 7);
    }
    
}
