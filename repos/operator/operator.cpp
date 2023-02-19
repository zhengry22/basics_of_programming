#include<iostream>
using namespace std;

class complex {
public:
	complex(double real, double imag):re(real), im(imag)
	{
		
	}
	complex operator+(const complex& c2)const {
		return complex(re + c2.re, im + c2.im);
	}
	complex operator-(const complex& c2)const {
		return complex(re - c2.re, im - c2.im);
	}
	void show()
	{
		cout << re << ' ' << im << endl;
	}

private:
	double re, im;
};

class 

int main()
{
	complex c1(1, 2);
	complex c2(3, 5);
	complex c3(c1 + c2);
	complex c4(c1 - c2);
	c3.show();
	c4.show();
	return 0;
}