#include<iostream>
#include<string>
#include<cstring>
using namespace std;

typedef struct info
{
	char name[20];
	int month;
	int date;
}personinfo;

//typedef struct info personinfo;

int main()
{
	int n;
	personinfo* person;
	cin >> n;
	person = new(personinfo[n]);
	for (int i = 0; i < n; i++)
	{
		person[i].name[0] = 'a' + i;
		person[i].name[1] = 'b' + i;
		person[i].name[2] = '\0';
		person[i].month = i%12;
		person[i].date = i % 30;
	}
	for (int i = 0; i < n; i++)
	{
		cout << person[i].name << endl;
		cout << person[i].month << endl;
		cout << person[i].date << endl;
	}
	delete person;
	return 0;
}
