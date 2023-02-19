#include<iostream>
using namespace std;

//pre_quote_claim A
class B;
class A {
public:
	A(int aa1, int aa2)
	{
		cout << "call constructor A" << endl;
		a1 = aa1;
		a2 = aa2;
	}
	A(A& a) :a1(a.a1), a2(a.a2)
	{
		cout << "call copy constructor A" << endl;
	}
	void function1(B &b);//ֻ����������bΪ�����ĺ��������ǲ�û������b������ǺϷ�����
	//{
	//	//b.para_add_b();
	//}
	void para_add_a()
	{
		a1++;
		a2++;
		cout << a1 << ' ' << a2 << endl;
	}
private:
	int a1, a2;
};

class B {
public:
	B(int bb1, int bb2)
	{
		cout << "call constructor B" << endl;
		b1 = bb1;
		b2 = bb2;
	}
	B(B& b) :b1(b.b1), b2(b.b2)
	{
		cout << "call copy constructor B" << endl;
	}
	void function2(A &a);
	/*{
		a.para_add_a();
	}*/
	void para_add_b()
	{
		b1++;
		b2++;
		cout << b1 << ' ' << b2 << endl;
	}
private:
	int b1, b2;
};

void A::function1(B &b)
{
	b.para_add_b();
}

void B::function2(A &a)
{
	a.para_add_a();
}
//Ϊʲô��������д��������벻����
int main()
{
	A tsta(1,1);
	B tstb(2, 2);
	tsta.para_add_a();//22a
	tsta.function1(tstb);//tstbֻ�ǲ�����������һ�����������Ҹö�������tstb�ĳ�ʼֵ��2��2��
	tstb.para_add_b();//
	tstb.function2(tsta);
	
}
