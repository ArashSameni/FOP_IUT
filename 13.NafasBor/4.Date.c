#include <stdio.h>
#include <stdlib.h>

long absl(long num)
{
    if (num < 0)
        return num * -1;
    return num;
}

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int *arr = (int *)malloc(sizeof(int));

    int ok = 1;
    int pos = 0;
    for (int z = k; z >= 1; z--)
        for (int i = z; i <= n; i += k)
        {
            arr[pos] = i;
            pos++;
            arr = realloc(arr, (pos + 1) * sizeof(int));
        }

    for (int i = 0; i < pos; i++)
        if (absl(arr[i] - arr[i + 1]) < k)
        {
            ok = 0;
            break;
        }

    if (ok)
        for (int i = 0; i < pos; i++)
            printf("%d ", arr[i]);
    else
        printf("Impossible");
    return 0;
}
