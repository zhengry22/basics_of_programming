#include<iostream>
#include<cstring>
using namespace std;

int judge[201][201][6];

//递归的过程
int ways(int n, int max, int k, int dep)
{
    int a,result,sum=0;
    if (dep > k)
        return sum;
    else if ((dep == k) && (n == 0))
    {
        sum++;
        return sum;
    }
    else if ((dep < k) && (n == 0))
        return sum;
    else if (n < 0)
        return sum;
    else if (n != 0)
    {
        if (judge[n][max][dep] >= 0)
        {
            return judge[n][max][dep];
        }

        //if (judge[n][max][k] < 0)
        else
        {
            for (int i = max; i >= 1; i--)
            {
                int dep2 = dep;
                a = n - i;
                if (a < 0)
                    continue;
                else
                {
                    dep2++;
                    result = ways(a, i, k, dep2);
                    sum = sum + result;
                    judge[a][i][dep2] = result;
                }
            }
            return sum;
        }
    }
}

int main()
{
	memset(judge, -1, sizeof(judge));//将judge全都装-1
	int n, k;
	cin >> n >> k;
	cout<<ways(n, n, k,0);//将n分成k份
	return 0;
}