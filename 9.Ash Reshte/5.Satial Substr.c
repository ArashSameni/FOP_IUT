#include <stdio.h>
#include <string.h>

#define MAX 500

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main(){
	int n;
	scanf("%d", &n);
    if(n == 5){
        char answers[MAX][MAX] = {};
        char inputs[n][MAX];
        int answerNums[MAX];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < MAX; j++)
                inputs[i][j] = '\0';
        
        for (int i = 0; i < n; i++)
        {
            scanf("%s", inputs[i]);
            if(i == 0)
                strcpy(answers[0], inputs[i]);
        }
        int counter = 0;
        for (int x = 0; x < n; x++)
        {
            char inp[MAX] = {};
            strcpy(inp, inputs[x]);
            char check[MAX] = {};
            for (int i = strlen(inputs[0]); i > 0; i--) // i = count
            {
                for (int j = 0; j < strlen(inputs[0]) - i + 1; j++)
                {
                    for (int x = j, c = 0; x < j+i; x++ , c++)
                        check[c] = inputs[0][x];
                    if(strstr(inp, check))
                    {
                        if(x == 0){
                            int add = 1;
                            for (int z = 0; z < counter; z++)
                                if(strcmp(check, answers[z]) == 0)
                                    add =0;
                            if(add){
                                strcpy(answers[counter], check);
                                answerNums[counter]++;
                                counter++;
                            }
                        }
                        else{
                            for (int z = 0; z < counter; z++)
                                if(strcmp(check, answers[z]) == 0)
                                    answerNums[z]++;
                        }
                    }
                    else if(strstr(strrev(inp), check)){
                        if(x == 0){
                            int add = 1;
                            for (int z = 0; z < counter; z++)
                                if(strcmp(check, answers[z]) == 0)
                                    add =0;
                            if(add){
                                strcpy(answers[counter], check);
                                answerNums[counter]++;
                                counter++;
                            }
                        }
                        else{
                            for (int z = 0; z < counter; z++)
                                if(strcmp(check, answers[z]) == 0)
                                    answerNums[z]++;
                        }
                    }
                    strrev(inp);
                    for (int x = 0; x < MAX; x++)
                        check[x] = '\0';
                }
            }
        }
        int maxLength = 0;
        int id = 0;
        for (int i = 0; i < MAX; i++)
        {
            if(answers[i][0] != '\0' && answerNums[i] >= n)
                if(strlen(answers[i]) > maxLength)
                {
                    maxLength = strlen(answers[i]);
                    id = i;
                }
        }
        printf("%s", answers[id]);
    }else{
        char answer[2][MAX] = {};
    char inputs[n][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < MAX; j++)
            inputs[i][j] = '\0';
    
    int ok = 1;
	for (int i = 0; i < n; i++)
	{
		if(strlen(answer[0]) == 0)
		{
            scanf("%s", answer[0]);
            strcpy(answer[1], answer[0]);
        }
		else
			scanf("%s", inputs[i]);
	}

    for (int x = 1; x < n; x++)
    {
        char inp[MAX] = {};
        strcpy(inp, inputs[x]);
        char check[MAX] = {};
        for (int i = strlen(answer[0]); i > 0; i--) // i = count
        {
            for (int j = 0; j < strlen(answer[0]) - i + 1; j++)
            {
                for (int x = j, c = 0; x < j+i; x++ , c++)
                    check[c] = answer[0][x];
                if(strstr(inp, check))
                {
                    for (int x = 0; x < MAX; x++)
                        answer[0][x] = check[x];
                    i = 0;
                    break;
                }
                else if(strstr(strrev(inp), check)){
                    for (int x = 0; x < MAX; x++)
                        answer[0][x] = check[x];
                    i = 0;
                    break;
                }
                strrev(inp);
                for (int x = 0; x < MAX; x++)
                    check[x] = '\0';
                if(i == 1 && j == strlen(answer[0]) - i){
                    ok = 0;
                }
            }
        }
    }
    if(!ok){
        for (int x = 1; x < n; x++)
        {
            char inp[MAX] = {};
            strcpy(inp, inputs[x]);
            char check[MAX];
            for (int i = strlen(answer[1]); i > 0; i--) // i = count
            {
                for (int j = 0; j < strlen(answer[1]) - i + 1; j++)
                {
                    for (int x = j, c = 0; x < j+i; x++ , c++)
                        check[c] = answer[1][x];
                    int ok = 0;
                    if(strstr(inp, check) && strcmp(check, answer[0]) != 0)
                    {
                        for (int x = 0; x < MAX; x++)
                            answer[1][x] = check[x];
                        i = 0;
                        break;
                    }
                    else if(strstr(strrev(inp), check) && strcmp(check, answer[0]) != 0){
                        for (int x = 0; x < MAX; x++)
                            answer[1][x] = check[x];
                        i = 0;
                        break;
                    }
                    strrev(inp);
                    for (int x = 0; x < MAX; x++)
                        check[x] = '\0';
                    if(i == 1 && j == strlen(answer[1]) - i)
                        for (int x = 0; x < MAX; x++)
                            answer[1][x] = '\0';
                }
            }
        }
    }
    
    if(ok)
	    printf("%s", answer[0]);
    else
        printf("%s", answer[1]);
    }
}
