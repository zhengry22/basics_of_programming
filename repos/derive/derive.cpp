#include<iostream>
using namespace std;

class base {
	
protected:

	base(int aa, int bb) :a(aa), b(bb) {
		cout << "base constructor called" << endl;
	}
	base():a(0),b(0)
	{
		cout << "base default constructor called" << endl;
	}
	/*base(base& obj) :a(obj.a), b(obj.b)
	{
		cout << "base copy construtor called" << endl;
	}*/
	~base()
	{
		cout << "destructor called" << endl;
	}
	int a, b;
};

class derive : public base {
public:
	derive(int cc, int dd, int bb, int aa) :c(cc), d(dd), base(bb, aa)
	{
		cout << "derive constructor called" << endl;
	}
	derive() :c(0), d(0)
	{
		cout << "derive default constructor called" << endl;
	}
    int geta()
	{
		return a;
	}
	int getb()
	{
		return b;
	}
	int c, d;
};



int main()
{
	derive obj1(4, 5, 3, 2);
	cout << obj1.c << obj1.d << obj1.geta() << obj1.getb() << endl;
	derive obj2(obj1);
	cout << obj2.c << obj2.d << obj2.geta() << obj2.getb() << endl;
	return 0;
}