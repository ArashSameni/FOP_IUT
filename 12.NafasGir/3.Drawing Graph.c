#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return (*(int*)a - *(int*)b);
}

int main() 
{
    int n;
    scanf("%d", &n);
    int rasnum[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &rasnum[i]);
    int count = 0;
    qsort(rasnum, n, sizeof(int), cmpfunc);

    for (int i = 0; i < n; i++)
    {
        int c = 0;
        int n = 1;
        int m = 1;
        while(rasnum[i+n] == rasnum[i])
        {
            n++;
            m++;
        }
        i += m - 1;
        n = 1;
        while(rasnum[i+n] == rasnum[i] + 1)
        {
            c++;
            n++;
        }
        c *= m;
        count += c;
    }
    printf("%d", count);
}
