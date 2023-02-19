#include<iostream>
#include<cstring>
using namespace std;

void f1(int,bool,string)
{
}

class trial {
public:
	trial(int x1, int x2)
	{
		a = x1;
		b = x2;
	}
	void f2(int x1, int x2)const;
	
private:
	int a, b;
};

void trial::f2(int x1, int x2)
{
	cout << x1 << x2;
}

int main()
{
	int a = 0;
	//f1(a);
	cout << a;
	string c = "ccc",b="ddd";
	cout << c + b;


	return 0;
}