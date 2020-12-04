#include <stdio.h>
#include <math.h>

int main(void) {
    int count = 0;
    scanf("%d", &count);

    float num;
    scanf("%f", &num);

    float max = num;
    float min = num;
    float sum = num;
    for (int i = 0; i < count-1; i++)
    {
        num;
        scanf("%f", &num);
        sum += num;
        if(num > max)
            max = num;
        if(num < min)
            min = num;
    }
    printf("Max: %.3f\n", max);
    printf("Min: %.3f\n", min);
    printf("Avg: %.3f", sum/count);
}
