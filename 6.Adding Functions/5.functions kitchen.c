#include <stdio.h>
#include <stdbool.h>

int nokhod, sibzamini, goosht;   // F: Nokhod S: Sib   D: goosht
bool isAshpaz[3];

void garson(int money, char food){
    bool done = false;
    switch (food)
    {
        case 'f':
            if(money < 6000)
            {
                printf("No enough money\n");
                done = true;
            }
            break;
        
        case 's':
            if(money < 18000)
            {
                printf("No enough money\n");
                done = true;
            }
            break;

        case 'd':
            if(money < 30000)
            {
                printf("No enough money\n");
                done = true;
            }
            break;
    }

    if(!done)
        monshi(food);
}

void monshi(char food){
    switch (food)
    {
        case 'f':
            if(!isAshpaz[0])
                printf("Not a chef\n");
            else
                ashpaz(food);
            break;
        
        case 's':
            if(!isAshpaz[1])
                printf("Not a chef\n");
            else
                ashpaz(food);
            break;

        case 'd':
            if(!isAshpaz[2])
                printf("Not a chef\n");
            else
                ashpaz(food);
            break;
    }
}

void ashpaz(char food){
    switch (food)
    {
        case 'f':
            if(nokhod)
            {
                printf("Food is ready\n");
                nokhod--;
            }
            else
                printf("Material is not enough\n");
            break;
        
        case 's':
            if(sibzamini)
            {
                printf("Food is ready\n");
                sibzamini--;
            }
            else
                printf("Material is not enough\n");
            break;

        case 'd':
            if(goosht)
            {
                printf("Food is ready\n");
                goosht--;
            }
            else
                printf("Material is not enough\n");
            break;
    }
}

int main() {
    scanf("%d%d%d", &nokhod, &sibzamini, &goosht);

    getchar();
    char c[3];
    scanf("%c", &c[0]);
    getchar();
    scanf("%c", &c[1]);
    getchar();
    scanf("%c", &c[2]);
    for (int i = 0; i < 3; i++)
        switch (c[i])
        {
            case 'p':
                isAshpaz[i] = true;
                break;

            case 'a':
                isAshpaz[i] = false;
                break;
        }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int money;
        char food;
        scanf("%d", &money);
        getchar();
        food = getchar();
        garson(money, food);
    }
}
