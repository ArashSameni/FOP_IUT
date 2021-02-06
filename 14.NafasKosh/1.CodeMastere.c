#include <stdio.h>
#include <string.h>

int isPrime(int n)
{
    if (n == 0 || n == 1)
        return 0;
    else if (n == 2 || n == 3)
        return 1;
    else
    {
        if (n % 2 == 0 || n % 3 == 0)
            return 0;
        int i = 5;
        while (i * i <= n)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return 0;
            i += 6;
        }
        return 1;
    }
}

double power(double number, int pow)
{
    double ans = 1;
    for (int i = 0; i < pow; ans *= number, i++)
        ;
}

int changeMabna(int number, int mabna)
{
    char answer[50] = {};
    int pos = -1;
    while (number > 0)
    {
        pos++;
        answer[pos] = number % mabna;
        number /= mabna;
    }

    for (int i = pos; i > pos / 2; i--)
    {
        if (answer[i] != answer[pos - i])
            return 0;
    }
    return 1;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int khafans = 0;
    int num = 2;
    while (khafans < n)
    {
        if (changeMabna(num, k))
            if (isPrime(num))
                khafans++;
        if (khafans != n)
        {
            if (num == 2)
                num++;
            else
                num += 2;
        }
    }
    printf("%d", num);
}
