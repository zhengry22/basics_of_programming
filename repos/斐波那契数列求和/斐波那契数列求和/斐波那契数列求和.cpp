#include<iostream>
using namespace std;
#define p 1000000007

int main()
{
    int n;
    cin >> n;
    if (n < 1 || n>1000000)
    {
        cout << "error" << endl;
    }
    else
    {
        int a, b, s;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            int i = 1;
            a = b = s = 1;
            for (i = 1; i <= n - 1; i++)
            {
                if ((s % p) <= (b % p))
                {
                    s = s + b;
                }
                else
                {
                    s = s - b;
                }
                a = a + b;
                int temp;
                temp = a;
                a = b;
                b = temp;
                a = a % p;
                b = b % p;
                s = s % p;
            }
            cout << s << endl;
        }
    }
    return 0;
}