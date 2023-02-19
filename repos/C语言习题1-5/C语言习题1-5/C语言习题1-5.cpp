#include <stdio.h>
#include <iostream>
using namespace std;
void print(int k, char c)
{
    for (int i = 0; i < k; i++)
    {
        cout << c;
    }
}
int main()
{
    /*char a[100];
    int r,i,j,k,m;
    cin >> r;
    a[0] = a[1] = ' ';
    for (i = 2; i <= 6; i++)
    {
        a[i] = '*';
    }
    cout << r << endl;
    for (j = 1; j <= r; j++)
    {
        for (k = 2; k<= 6 + 2 * (j - 1); k++)
        {
           printf("%c", a[k]);
        }
        for (int m = 2; m<=100; m++)
        {
           a[m] = a[m - 2];
        }

    }
    */
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        print(i * 2, ' ');
        print(5, '*');
        cout << endl;
    }

    return 0;
}


