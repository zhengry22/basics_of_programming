#include<iostream>
using namespace std;

int main()
{
	int n;
	int d, h;
	cin >> n;
	//判断n是否满足取值范围
	if (n < 1 || n>10000)
	{
		cout << "unvalid n";
	}
	else
	{
		d = n / 1440;//用分钟除以1440得到天数
		n = n%1440;//得到除了整数天数之外剩下还有多少分钟
		h = n / 60;//得到小时
		n = n % 60;//得到除了整小时外还有多少分钟
		cout << d << ' ' << h << ' ' << n << endl;
	}
	return 0;
}