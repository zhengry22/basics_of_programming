#include<iostream>
using namespace std;

int main()
{
	int n;
	int d, h;
	cin >> n;
	//�ж�n�Ƿ�����ȡֵ��Χ
	if (n < 1 || n>10000)
	{
		cout << "unvalid n";
	}
	else
	{
		d = n / 1440;//�÷��ӳ���1440�õ�����
		n = n%1440;//�õ�������������֮��ʣ�»��ж��ٷ���
		h = n / 60;//�õ�Сʱ
		n = n % 60;//�õ�������Сʱ�⻹�ж��ٷ���
		cout << d << ' ' << h << ' ' << n << endl;
	}
	return 0;
}