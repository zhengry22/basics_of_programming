#pragma warning(disable:4996)
#include<stdio.h>

long long int stone[10000005];

void swap(long long int* a, long long int* b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}


void quick_sort(long long int* p, long long int n)
{
    if (n <= 1)
        return;
    long long int t = p[n - 1], l = 0, r = n - 2;
    do {
        for (; r >= l; l++)
            if (p[l] > t)
                break;
        for (; r >= l; r--)
            if (p[r] < t)
                break;
        if (r >= l)
            swap(&p[l], &p[r]);
    } while (r >= l);
    swap(&p[l], &p[n - 1]);
    quick_sort(&p[0], l);
    quick_sort(&p[l + 1], n - l - 1);
}


int main()
{
    long long int n;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &stone[i]);
    long long int t = stone[n - 1], l = 0, r = n - 2;
    do {
        for (; r >= l; l++)
            if (stone[l] > t)
                break;
        for (; r >= l; r--)
            if (stone[r] < t)
                break;
        if (r >= l)
            swap(&stone[l], &stone[r]);
    } while (r >= l);
    swap(&stone[l], &stone[n - 1]);
    //比较p[l]与stone[n/2]的地址
    if (&stone[l] > &stone[n / 2])
        quick_sort(&stone[0], l);
    else if (&stone[l] < &stone[n / 2])
        quick_sort(&stone[l + 1], n - l - 1);
    int p = n / 2;
    long long int sum1 = 0, sum2 = 0;
    for (int i = 0; i < p; i++)
    {
        sum1 = sum1 + stone[i];
    }
    for (int i = p; i < n; i++)
    {
        sum2 = sum2 + stone[i];
    }
    printf("%lld", sum2 - sum1);
    return 0;
}