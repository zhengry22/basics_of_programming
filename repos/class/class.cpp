#include<iostream>
using namespace std;

class clc {
public:
	clc(int newh, int newm=10, int news=10, int leng=10)
	{
		hour = newh;
		minute = newm;
		second = news;
		length = leng;
		history_ptr = new clc[length];
		//cout << "clc define" << endl;
	}//���Զ�ʵ�ֹ��캯���ĳ�ʼ������

	clc() :hour(1), minute(2), second(3),length(0)
	{	
		history_ptr = nullptr;
		//cout << "clc default" << endl;
	}//�Զ�ʵ�ֹ��캯���ĳ�ʼ�����ܣ�����ʹ�ð��Զ���������ʵ��
	void settime(int h = 0, int m = 0, int s = 0);
	void showtime();
	int hour = 0;
	clc(const clc& c):hour(c.hour),minute(c.minute),second(c.second) {
		//hour = c.hour;
		//minute = c.minute;
		//second = c.second;
		if (c.length != 0)
		{
			history_ptr = new clc[c.length];
			memcpy(history_ptr, c.history_ptr, sizeof(clc) * c.length);
		}
		length = c.length;
		cout << "copy construct" << endl;
	}

	clc(clc&& c) :hour(c.hour), minute(c.minute), second(c.second), length(c.length), history_ptr(c.history_ptr)
	{
		c.history_ptr = nullptr;
		cout << "call move constructor" << endl;
	}

	void copy_clock_2(clc c)
	{
		hour = c.hour;
		minute = c.minute;
		second = c.second;
	//	cout << "copy_clock_2" << endl;
	}//����������ǿ������캯�������ܹ�ʵ�ֺͿ������캯����ͬ�Ĺ��ܣ�ֻ��������Ҫ��Ϊ������������壬������ֱ����clc timer1(myclock)��д��

	~clc()
	{
		/*if (history_ptr != nullptr)
		{
			delete[] history_ptr;
			history_ptr = nullptr;
		}*/
			

	//	cout << "call"<<hour << minute << second << "xg" << endl;
	}

	void set_history(int index, clc c)
	{
		history_ptr[index].hour = c.hour;
		history_ptr[index].minute = c.minute;
		history_ptr[index].second = c.second;
	}

	clc get_history(int index)
	{
		return history_ptr[index];
	}

	int get_history_minute(int index)
	{
		return history_ptr[index].minute;
	}

	int get_history_second(int index)
	{
		return history_ptr[index].second;
	}
	int length;
private:
	void show_private();
	int minute=0, second=0;
	clc* history_ptr;

};

void clc::settime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void clc::show_private()
{
	//cout << "0:0:0";
}

void clc::showtime()
{
	cout << hour << ":" << minute << ":" << second << endl;
	//show_private();
}

clc ret_clock(7, 7, 7);

clc fct()
{
	clc myclock(21, 0, 0);
	//cout << "call fct" << endl;
	return myclock;
}


int main()
{
	//clc myclock(12,12,12);
	////clc timer1(myclock);
	//myclock.showtime();
	////timer1.showtime();
	//clc his(11, 10, 9);
	//myclock.set_history(1, his);
	//cout <<"myclock.history_time"<< myclock.get_history(1).hour << ':' << myclock.get_history_minute(1) << ':' << myclock.get_history_second(1) << endl;

	//clc myclock2(myclock);
	//cout << "myclock2.history_time" << myclock2.get_history(1).hour << ':' << myclock2.get_history_minute(1) << ':' << myclock2.get_history_second(1) << endl;
	//myclock.set_history(1, myclock);
	//cout << "myclock2.history_time" << myclock2.get_history(1).hour << ':' << myclock2.get_history_minute(1) << ':' << myclock2.get_history_second(1) << endl;

	fct();

	//ע��timer1����һ��myclock�����ã����Ǵ�����һ���������ڴ�ռ��С��ڿ������캯������ν��������˵����������¶����ڴ���������ͨ�����ø�ֵ�ķ�ʽ
	//��ȡmyclock�е�����
	//clc timer2;
	////timer2 = myclock;
	//myclock.showtime();
	//timer1.showtime();
	//timer2.showtime();

	/*timer1.settime(1, 1, 1);
	timer2 = myclock;
	timer2.settime(2, 2, 2);
	timer2.showtime();

	fct();
	/*myclock.settime(10, 11, 12);
	myclock.showtime();
	timer1.showtime();*/

	/*
	* clc ccc;
	cout << "ccc start" << endl;
	ccc.copy_clock_2(myclock);
	ccc.showtime();
	*/

	/*myclock.hour = 10;
	myclock.showtime();
	myclock.settime(10);
	myclock.showtime();
	myclock.settime(9,10,11);
	myclock.showtime();*/

	
	
	return 0;
}