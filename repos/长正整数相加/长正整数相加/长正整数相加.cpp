#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
using namespace std;

int main()
{	//先把x，y装到两个数组里
		bool t = false;
		cin >> a;
		cin >> b;

		for (int i = 0; i < strlen(a.data()); i++) {
			m[101 - strlen(a.data()) + i] = (a[i] - '0');
		}
		for (int i = 0; i < strlen(b.data()); i++) {
			n[101 - strlen(b.data()) + i] = (b[i] - '0');
		}

		//加法 
		for (int j = 100; j >= 0; j--) {
			c[j] = int(m[j]) + int(n[j]);
		}
		for (int k = 100; k >= 1; k--) {
			if (c[k] >= 10)
			{
				c[k - 1] = c[k - 1] + 1;
				c[k] = c[k] % 10;
			}
		}
		//从第一位不是0的数进行输出
		for (int i = 1; i <= 100; i++) {
			if (c[i] != 0) {
				t = true;
			}
			if (t == true) {
				cout << c[i];
			}
		}
		return 0;
	}
	return 0;
}