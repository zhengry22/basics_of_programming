#include<iostream>
using namespace std;

int max(long long a, long long b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int min(long long a, long long b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    long long n, * steps, place = 0, cnt = 0;
    cin >> n;
    steps = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> steps[i];
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    else
    {
        while (place + steps[place] < n - 1)
        {
            long long m = 0, flag = 0;
            for (int i = 1; i <= min(steps[place], n - 1 - place); i++)
            {
                if (place + i + steps[place + i] > m)
                {
                    m = place + i + steps[place + i];
                    flag = place + i;
                }
                //cout << m << endl;
            }
            cnt++;
            place = flag;
            //cout << place << endl;
        }
        cout << cnt+1;
        delete[] steps;

        return 0;
    }
}