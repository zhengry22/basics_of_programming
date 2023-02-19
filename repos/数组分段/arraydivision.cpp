#include<iostream>
using namespace std;

int num[100000];

long long max(long long int a, long long int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

long long min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int divide(long long int max_num, int n)
{
    long long int sum2 = 0, seg = 0;
    for (int i = 0; i < n; i++)
    {
        if ((sum2 + num[i]) <= max_num)
        {
            sum2 = sum2 + num[i];
            if (i == n - 1)
            {
                seg++;
                return seg;
            }
        }
        else
        {
            seg++;
            sum2 = num[i];
            if (i == n - 1)
            {
                seg++;
                return seg;
            }
        }
    }
}


int main()
{
    int n, m;
    long long int maximum = 0, minimum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    //先从0到n-1遍历，求出最大值以及和
    for (int i = 0; i < n; i++)
    {
        maximum = maximum + num[i];
        minimum = max(minimum, num[i]);
    }
    //cout << minimum << maximum;
   
        long long int low = max(maximum / m, minimum), high = maximum;
        while (low <= high)
        {
            long long int middle = (low + high) / 2;
            if ((divide(middle + 1, n) == m) && (divide(middle, n) > m))
            {
                cout << middle + 1;
                break;
            }
            else if ((divide(middle + 1, n) == m) || (divide(middle + 1, n) < m))
            {
                high = middle;
            }
            else if (divide(middle + 1, n) > m)
            {
                low = middle + 1;
            }
            if (low == high)
            {
                cout << low;
                break;
            }
        }
        return 0;
    
}