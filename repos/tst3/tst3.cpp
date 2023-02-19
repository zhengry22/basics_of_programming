#include<iostream>
using namespace std;

char c[4];

struct answer {
	char name;
	bool go;
};

int logic(bool x, bool y, bool z, bool q)
{
	bool a[4];
	int truenum = 0;
	a[0] = x;
	a[1] = !y;
	a[2] = z;
	a[3] = !q;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == true)
			truenum++;
	}
	return truenum;

}

void testlogic()
{
	
	char testc[4] = { 'a','b','c','d' };
	for (int i = 0; i < 4; i++)
	{

		//cin >> c[i];
		c[i] = tolower(c[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		if (logic(testc[i] == c[0], testc[i] == c[1], testc[i] == c[2], testc[i] == c[3]) == 2)
			cout << (char)toupper(testc[i]);
	}
}


int main() {
	answer stu[4];
	for (int i = 0; i < 4; i++) {
		cin >> stu[i].name;
		c[i] = stu[i].name;
	}
	stu[0].go = true; stu[2].go = true; stu[1].go = false; stu[3].go = false;
	for (int i = 'A'; i <= 'D'; i++) {
		//i代表了假设中的去了紫荆园的学生，现在可以确定哪些命题是真的，那些命题是假的了
		int real = 0;
		for (int j = 0; j < 4; j++) {
			if ((stu[j].name == i && stu[j].go) || (stu[j].name != i && !stu[j].go))
				real++;
		}
		if (real == 2)cout << (char)i;
	}
	cout << endl;
	testlogic();
	return 0;
}