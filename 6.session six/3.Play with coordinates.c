#include <stdio.h>

int* position(int n){
   n -= 1;

    static int pos[2];
    pos[0] = 0;
    pos[1] = 0;

    for(int i = 1;i <= n;i++){
        int steps = 1;
        if(i%2 == 0)
            steps = i/2;
        else
            steps = (i+1)/2;
        
        if(i%4 == 1)
            pos[0] += steps;
        else if(i%4 == 2)
            pos[1] += steps;
        else if(i%4 == 3)
            pos[0] -= steps;
        else
            pos[1] -= steps;
    }
    return pos;
}

int main(void) {
    int n;
    scanf("%d", &n);

    int *p = position(n);
    printf("%d %d", *p, *(p+1));
}
