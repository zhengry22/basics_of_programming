#include<iostream>
using namespace std;

int main()
{
	int a[3],b[3],p=0;
	//����abc������ÿһ��ʳ���Ŀ��ܽ���ö��
	for (a[0] = 0; a[0] <= 2; a[0]++)
	{
		for (a[1] = 0; a[1] <= 2; a[1]++)
		{
			for (a[2] = 0; a[2] <= 2; a[2]++)
			{
				b[0] = ((b > a) + (c == a));//a˵�ԵĻ�����ֵ
				b[1] = ((a > b) + (a > c));//b˵�ԵĻ�����ֵ
				b[2] = ((c > b) + (b > a));//c˵�ԵĻ�����ֵ
				for (int i = 0; i <= 1; i++)
				{
					for (int j = i + 1; j <= 2; j++)
					{
						if (((a[i] - b[i]) * (a[j] - b[j])) < 0 || ((a[i] == a[j]) + (b[i] == b[j])) == 2)
						p++;
					}
				}
				if (p == 3)
				{
					
				}

			}
		}
	}
}