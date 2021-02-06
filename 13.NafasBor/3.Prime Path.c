#include <stdio.h>
#include <stdlib.h>

int isPrime(int number)
{
    if (number == 1)
        return 0;
    else if (number == 2)
        return 1;
    else
    {
        int dCounts = 0;
        for (int i = 2; i < (number / 2) + 1; i++)
        {
            if (number % i == 0)
            {
                dCounts++;
                break;
            }
        }
        if (dCounts)
            return 0;
        else
            return 1;
    }
}

long absl(long num)
{
    if (num < 0)
        return num * -1;
    return num;
}

int numExist(int **arr, int count, int i, int j)
{
    for (int z = 0; z < count; z++)
        if (arr[z][0] == i && arr[z][1] == j)
        {
            return 1;
        }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (t; t > 0; t--)
    {

        int n;
        scanf("%d", &n);
        char **arr = (char **)malloc(sizeof(char *) * n); //bool nagerftam alaki ye library ezafe nashe, not good but faster?
        for (int i = 0; i < n; i++)
            arr[i] = (char *)malloc(sizeof(char) * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int num;
                scanf("%d", &num);
                if (isPrime(num))
                    arr[i][j] = 1;
                else
                    arr[i][j] = 0;
            }
        }

        int *count = (int *)malloc(sizeof(int) * n * n);
        for (int i = 0; i < n * n; count[i] = 0, i++)
            ;

        int ***masir = (int ***)malloc(sizeof(int **) * n * n);
        for (int i = 0; i < n * n; i++)
        {
            masir[i] = (int **)malloc(sizeof(int *) * n);
            for (int j = 0; j < n; j++)
                masir[i][j] = (int *)malloc(sizeof(int) * 2);
        }

        int end[2];
        scanf("%d %d", &masir[0][0][0], &masir[0][0][1]);
        count[0]++;
        scanf("%d %d", &end[0], &end[1]);
        int j = 0;
        int resid = 0;
        for (j = 0; j < n * n - 1 && !resid; j++)
        {
            int checked = 0;
            for (int i = 0; i < count[j]; i++)
            {
                int y = masir[j][i][0];
                int x = masir[j][i][1];
                if (y < n - 1 && arr[y + 1][x] == 1) // age akharin satr nabood va satr paaini prime bood
                {
                    if (y + 1 == end[0] && x == end[1])
                    {
                        resid = 1;
                        masir[j + 1][count[j + 1]][0] = y + 1;
                        masir[j + 1][count[j + 1]][1] = x;
                        for (int b = 0; b < count[j + 1]; b++)
                        {
                            masir[j + 1][b][0] = y + 1;
                            masir[j + 1][b][1] = x;
                        }
                        count[j + 1]++;
                        break;
                    }
                    int check = 1;
                    for (int z = j + 1; z >= 0; z--)
                    {
                        if (numExist(masir[z], count[z], y + 1, x))
                        {
                            check = 0;
                            break;
                        }
                    }
                    if (check)
                    {
                        checked = 1;
                        masir[j + 1][count[j + 1]][0] = y + 1;
                        masir[j + 1][count[j + 1]][1] = x;
                        count[j + 1]++;
                    }
                }
                if (y > 0 && arr[y - 1][x] == 1)
                {
                    if (y - 1 == end[0] && x == end[1])
                    {
                        resid = 1;
                        masir[j + 1][count[j + 1]][0] = y - 1;
                        masir[j + 1][count[j + 1]][1] = x;
                        for (int b = 0; b < count[j + 1]; b++)
                        {
                            masir[j + 1][b][0] = y - 1;
                            masir[j + 1][b][1] = x;
                        }
                        count[j + 1]++;
                        break;
                    }
                    int check = 1;
                    for (int z = j + 1; z >= 0; z--)
                    {
                        if (numExist(masir[z], count[z], y - 1, x))
                        {
                            check = 0;
                            break;
                        }
                    }
                    if (check)
                    {
                        checked = 1;
                        masir[j + 1][count[j + 1]][0] = y - 1;
                        masir[j + 1][count[j + 1]][1] = x;
                        count[j + 1]++;
                    }
                }
                if (x < n - 1 && arr[y][x + 1] == 1)
                {
                    if (y == end[0] && x + 1 == end[1])
                    {
                        resid = 1;
                        masir[j + 1][count[j + 1]][0] = y;
                        masir[j + 1][count[j + 1]][1] = x + 1;
                        for (int b = 0; b < count[j + 1]; b++)
                        {
                            masir[j + 1][b][0] = y;
                            masir[j + 1][b][1] = x + 1;
                        }
                        count[j + 1]++;
                        break;
                    }
                    int check = 1;
                    for (int z = j + 1; z >= 0; z--)
                    {
                        if (numExist(masir[z], count[z], y, x + 1))
                        {
                            check = 0;
                            break;
                        }
                    }
                    if (check)
                    {
                        checked = 1;
                        masir[j + 1][count[j + 1]][0] = y;
                        masir[j + 1][count[j + 1]][1] = x + 1;
                        count[j + 1]++;
                    }
                }
                if (x > 0 && arr[y][x - 1] == 1)
                {
                    if (y == end[0] && x - 1 == end[1])
                    {
                        resid = 1;
                        masir[j + 1][count[j + 1]][0] = y;
                        masir[j + 1][count[j + 1]][1] = x - 1;
                        for (int b = 0; b < count[j + 1]; b++)
                        {
                            masir[j + 1][b][0] = y;
                            masir[j + 1][b][1] = x - 1;
                        }
                        count[j + 1]++;
                        break;
                    }
                    int check = 1;
                    for (int z = j + 1; z >= 0; z--)
                    {
                        if (numExist(masir[z], count[z], y, x - 1))
                        {
                            check = 0;
                            break;
                        }
                    }
                    if (check)
                    {
                        checked = 1;
                        masir[j + 1][count[j + 1]][0] = y;
                        masir[j + 1][count[j + 1]][1] = x - 1;
                        count[j + 1]++;
                    }
                }
            }
            if (!checked)
                break;
        }
        if (resid)
        {
            int tekrar = 1;
            for (int t = 0; t < tekrar; t++)
                for (int i = 1; i < j; i++)
                {
                    for (int d = 0; d < count[i]; d++)
                    {
                        int delete = 1;
                        if (masir[i][d][0] < 0)
                            break;
                        if (count[i] > 0)
                        {
                            for (int x = 0; x < count[i + 1]; x++)
                            {
                                int y1 = masir[i][d][0];
                                int x1 = masir[i][d][1];
                                int y2 = masir[i + 1][x][0];
                                int x2 = masir[i + 1][x][1];
                                if ((absl(y1 - y2) == 1 && x1 == x2) || (absl(x1 - x2) == 1 && y1 == y2))
                                {
                                    delete = 0;
                                    break;
                                }
                            }
                            if (delete)
                            {
                                masir[i][d][0] = -1;
                                masir[i][d][1] = -1;
                                tekrar++;
                            }
                        }
                    }
                }
            int ghabli = 0;
            for (int i = 1; i <= j + 1; i++)
            {
                // for (int x = 0; x < count[i]; x++)
                // {
                //     printf("%d,%d ", masir[i][x][0], masir[i][x][1]);
                // }
                // printf("\n");
                int pos = 0;
                while (masir[i][pos][0] < 0)
                    pos++;
                if (masir[i][pos][0] - masir[i - 1][ghabli][0] == 1)
                    printf("D");
                else if (masir[i][pos][0] - masir[i - 1][ghabli][0] == -1)
                    printf("U");
                else if (masir[i][pos][1] - masir[i - 1][ghabli][1] == 1)
                    printf("R");
                else if (masir[i][pos][1] - masir[i - 1][ghabli][1] == -1)
                    printf("L");
                ghabli = pos;
            }
        }
        else
            printf("No Monaseb Masir!");
        printf("\n");
        free(arr);
        free(masir);
        free(count);
    }
    return 0;
}
