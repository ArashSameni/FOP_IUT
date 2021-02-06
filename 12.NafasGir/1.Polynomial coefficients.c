#include <stdio.h>
#include <stdlib.h>

long long int *zarb(long int m, long int n, long long int *zaribs1)
{
    long long int *answer = (long long int *)malloc(sizeof(long long int) * (m * n + 1));
    for (long int i = 0; i <= m * n; answer[i] = 0, i++)
        ;

    long long int tempzaribs2[m * n + 1];
    for (long int i = 0; i <= m; i++)
            tempzaribs2[i] = zaribs1[i];

    long int m2 = m;
    for (long int z = 0; z < n - 1; z++)
    {
        for (long int i = 0; i <= m; i++)
        {
            for (long int j = 0; j <= m2; j++)
            {
                answer[i + j] += zaribs1[i] * tempzaribs2[j];
            }
        }
        for (long int i = 0; i <= m * n; i++)
            tempzaribs2[i] = answer[i];
        if(z != n-2)
            for (long int i = 0; i <= m * n; i++)
                answer[i] = 0;
        m2 += m;
    }
    return answer;
}

int main()
{
    long int m, n;
    scanf("%li %li", &m, &n);
    long long int zaribs[m + 1];
    for (long int i = 0; i <= m; i++)
        scanf("%lli", &zaribs[i]);

    long long int *answer = zarb(m, n, zaribs);
    long int martabe = m * n;
    if(n != 1)
    for (long int i = 0; i <= martabe; i++)
        printf("%lli ", answer[i]);
    else
        for (long int i = 0; i <= martabe; i++)
            printf("%lli ", zaribs[i]);
    return 0;
}
