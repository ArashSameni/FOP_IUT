#include <stdio.h>

int main(){
	int num;
    scanf("%d", &num);

    int stars = 1;

    while(stars <= num){
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < num; i++)
                    if(i < (num-stars)/2 || i >= num - ((num-stars)/2))
                        printf(" ");
                    else
                        printf("*");
        printf("\n");
        stars += 2;
    }
    stars -= 4;
    while(stars > 0){
        for (int j = 0; j < 2; j++)
            for (int i = 0; i < num; i++)
                if(i < (num-stars)/2 || i >= num - ((num-stars)/2))
                    printf(" ");
                else
                    printf("*");
        printf("\n");
        stars -= 2;
    }
}
