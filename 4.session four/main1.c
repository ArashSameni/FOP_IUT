#include <stdio.h>
#include <math.h>

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = -10; i <= m; i++)
        for (int j = 1; j <= n; j++)
            sum += (int)(pow((i+j), 3)/pow(j, 2));
    printf("%d", sum);
}
