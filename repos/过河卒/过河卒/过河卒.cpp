#include<iostream>
#include<string.h>
using namespace std;

long long way[25][25];//这个数组中，way[x][y]代表的是到达x，y这个坐标有多少种走法

//输入坐标x，y；在函数中实际上参与运算的是x+2和y+2
long long ways(int x, int y)
{
	long long int left, up;
	if (way[x + 2][y + 2] >= 0)
		return way[x + 2][y + 2];
	else
	{
		if ((x != 0) && (y != 0))
		{
			way[x + 1][y + 2] = ways(x - 1, y);
			way[x + 2][y + 1] = ways(x, y - 1);
			return way[x + 1][y + 2] + way[x + 2][y + 1];
		}
		else if (x == 0)
		{
			way[x + 2][y + 1] = ways(x, y - 1);
			return way[x + 2][y + 1];
		}
		else if (y == 0)
		{
			way[x + 1][y + 2] = ways(x - 1, y);
			return way[x + 1][y + 2];
		}
	}
}

int main()
{
	int flag = 0;
	memset(way, -1, sizeof(long long) * 625);
	int x, y, knx, kny;
	cin >> x >> y >> knx >> kny;
	// sides: 1
	for (int i = 0; i <= x; i++)
		way[i + 2][2] = 1;
	for (int i = 0; i <= y; i++)
		way[2][i + 2] = 1;
	way[knx + 2][kny + 2] = 0;
	//把马的管辖区域全部赋值为0
	for (int i = 1; i <= 2; i++)
	{
		way[knx - i + 2][kny - (3 - i) + 2] = 0;
		way[knx + i + 2][kny - (3 - i) + 2] = 0;
		way[knx - i + 2][kny + (3 - i) + 2] = 0;
		way[knx + i + 2][kny + (3 - i) + 2] = 0;
	}
	for (int i = 0; i <= x; i++)
	{
		if (flag == 1)
		{
			way[i + 2][2] = 0;
			continue;
		}
		if (way[i + 2][2] == 0)
		{
			flag = 1;
		}
		
	}
	flag = 0;
	for (int i = 0; i <= y; i++)
	{
		if (flag == 1)
		{
			way[2][i + 2] = 0;
			continue;
		}
		if (way[2][i+2] == 0)
		{
			flag = 1;
		}
	}
	long long int result = ways(x, y);
	cout << result;
	return 0;
}