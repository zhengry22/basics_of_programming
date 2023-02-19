#include<iostream>
#include<cstring>
using namespace std;

struct point {
	int x;
	int y;
};

struct circle {
	int x;
	int y;
	int r;
};

int main()
{
	int n, m, *result;
	point* pnt;
	circle* ccl;
	cin >> n;
	pnt = new point[n];
	for (int i = 0; i < n; i++)
		cin >> pnt[i].x >> pnt[i].y;
	cin >> m;
	ccl = new circle[m];
	result = new int[m];
	memset(result, 0, sizeof(int) * m);
	for (int i = 0; i < m; i++)
		cin >> ccl[i].x >> ccl[i].y >> ccl[i].r;

	for (int i = 0; i < m; i++)
	{
		//for each circle
		for (int j = 0; j < n; j++)
		{
			if ((pnt[j].x - ccl[i].x) * (pnt[j].x - ccl[i].x) + (pnt[j].y - ccl[i].y) * (pnt[j].y - ccl[i].y) <= (ccl[i].r * ccl[i].r))
			{
				result[i]++;
			}
		}
	}

	for (int i = 0; i < m; i++)
		cout << result[i] << ' ';
	return 0;
}