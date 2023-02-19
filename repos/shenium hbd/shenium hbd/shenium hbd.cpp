#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a, b;
	int month = 10;
	int day = 11;
	struct name
	{
		int age;
		string school;
		string affiliation;
	};
	struct name shenium = { 18,"清华附中","G1911"};
	cout << "shenium" << endl;
	getchar();
	cout << "year:" << endl;
	cin >> a;
	while (a == 2021)
	{
		cout << "age:" << ' '<<shenium.age << endl;
		cout << "school:" << ' '<<shenium.school << endl;
		cout << "class:" << ' '<<shenium.affiliation << endl;
		break;
	}
	getchar();
	getchar();
	cout << "year:" << endl;
	cin >> b;
	while (b == 2022)
	{
		shenium.age++;
		shenium.school = "清华大学";
		shenium.affiliation = "计21";
		cout << "on" << ' ' << month << '.' << day << endl;
		cout << "age:" << ' ' << shenium.age << endl;
		cout << "school:" << ' ' << shenium.school << endl;
		cout << "class:" << ' ' << shenium.affiliation << endl;
		cout << "happy birthday!" << endl;
		break;
	}
	return 0;
}