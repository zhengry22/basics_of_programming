#include<iostream>
#include<cstring>
using namespace std;

int result[19][19];

int answer(int x, int y)
{
	int tmp;
	if (result[x][y] >= 0)
		return result[x][y];
	if (y == 0)
		return 1;
	if (x == 0)
	{
		return answer(x + 1, y - 1);
	}
	else
	{
		result[x-1][y] = answer(x - 1, y);
		result[x+1][y-1] = answer(x + 1, y - 1); 
		//result[x][y]=result[x - 1][y] + result[x + 1][y - 1];
		return result[x - 1][y] + result[x + 1][y - 1];
	}
}

int main()
{
	memset(result, -1, sizeof(int) * 19*19);
	int n;
	cin >> n;
	cout<<answer(0, n);
	return 0;
}