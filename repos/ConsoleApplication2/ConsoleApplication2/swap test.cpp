#include<iostream>
using namespace std;
int main()
{
	int m, n, k;
	cin >> n;
	//�ж�n�Ĵ�С�Ƿ񳬹�10000
	if (n > 10000)
	{
		cout << "n is too big!" << endl;
	}
	/*�õȲ�������͹�ʽ�����жϣ����n�ܱ�ʾ�����������������������ĺͣ���
	n=m*(m+k)/2,һ��k+1��������ʼ��m��������m+k*/
	
	else
	{
		for (k = n - 1; k >= 1; k--)
		{
			if ((2 * n) % (k + 1) == 0 && ((2 * n) / (k + 1) - k)%2==0)
			{
				m = (2 * n / (k + 1) - k) / 2;
				if (m > 0)
				{
					cout << m << ' ' << m + k << endl;
				}
			}
		}
	}
	return 0;
}