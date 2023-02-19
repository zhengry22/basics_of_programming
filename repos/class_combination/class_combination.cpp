#include<iostream>
#include<cmath>
using namespace std;

class Point {
public:
	Point(int xx = 0, int yy = 0)//构造函数
	{
		cout << "calling constructor of point" << endl;
		x = xx;
		y = yy;
	}
	Point(Point& p):x(p.x),y(p.y)//点的拷贝构造函数
	{
		cout << "calling the copy constructor of point" << endl;
	}
	int getx() {
		return x;
	}
	int gety() {
		return y;
	}//由于x，y是private的，因此不能够直接进行访问，需要这两个函数进行访问来获取x，y
	void alter_x()
	{
		x++;
	}
	void alter_y()
	{
		y++;
	}

private:
	int x, y;
};

class Line {
public:
	Line(Point xp1, Point xp2)//线段的构造函数
	{
		cout << "calling constructor of line" << endl;
		p1 = xp1;
		p2 = xp2;
		double x = (p1.getx() - p2.getx());
		double y = (p1.gety() - p2.gety());
		len = sqrt(x * x + y * y);
	}
	Line(Line& l) :p1(l.p1), p2(l.p2), len(l.len)//线段的拷贝构造函数
	{
		cout << "calling the copy constructor of line" << endl;
	}
	double getlen()
	{
		return len;
	}
	void alter_leftpoint_plus1()
	{
		p1.alter_x();
		p1.alter_y();
	}
	void calc_len()
	{
		double x = (p1.getx() - p2.getx());
		double y = (p1.gety() - p2.gety());
		len = sqrt(x * x + y * y);
	}
private:
	Point p1, p2;
	double len;
};

int main()
{
	Point point1(1, 1), point2(4, 5);
	Line line1(point1, point2);//放在后面的参数先传进来(why)
	Line line2(line1);

	cout << "the length of line1 is" << line1.getlen() << endl;
	cout << "the length of line2 is" << line2.getlen() << endl;
	line2.alter_leftpoint_plus1();//只是改变了某一个端点的值，并没有影响到line2的length,因为那需要调用构造函数
	line2.calc_len();
	cout << "the length of line2 is" << line2.getlen() << endl;

	return 0;
}