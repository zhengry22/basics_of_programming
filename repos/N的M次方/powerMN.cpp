#include<iostream>
using namespace std;

int n[100000],m[100000],expo[100000]={0};
double n2[100000];
double basenum;
int expnum;

int last(int n, int m)
{
	int r = 1, base = n%1000;
	while (m!= 0)
	{
		if (m % 2 == 1)
			r = (r * base)%1000;
		base = (base * base)%1000;
		m = m / 2;
	}
	return r;
}

void first(double n, int expo, int m)
{
	double r = 1, base = n;
	int e = expo * m;//�Ȱ�10��ָ���������
	while (m != 0)
	{
		//��ʹ�ÿ����ݼ���ǰ��С�����ֵ���
		if (m % 2 == 1)
		{
			r = r * base;
			if (r >= 10)
			{
				r = r / 10;
				e++;
			}
		}
		base = base * base;
		m = m / 2;
		if (base >= 10)
		{
			e = e + m;
			base = base / 10;
		}
	}
	if (r >= 10)
	{
		r = r / 10;
		e++;
	}
	//���ڣ�r�ǿ�ѧ�������ĵ�����e��10��ָ��
	basenum = r;
	expnum = e;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n[i] >> m[i];
		n2[i] = n[i];
	}

	//ĩ��λ���
	for (int i = 0; i < t; i++)
	{	
		
		while (n2[i] >= 10)
		{
			n2[i] = n2[i] / 10;
			expo[i]++;
		}
		first(n2[i], expo[i], m[i]);
		
		if (expnum == 0)
		{
			cout << 0 << 0 << (int)(basenum) << ' ';
		}
		else if (expnum == 1)
		{
			cout << 0 << (int)(basenum * 10) << ' ';
		}
		else if (expnum >= 2)
		{
			int result = (int)(basenum * 100);
			cout << result << ' ';
		}


		//�������λ
		int a = last(n[i], m[i]);
		if ((a < 10)&&(a>=0))
			cout << 0 << 0 << a<<endl;
		else if ((10<=a)&&(a<100))
			cout << 0 << a<<endl;
		else if (a >= 100)
			cout << a<<endl;
	}
	return 0;
}