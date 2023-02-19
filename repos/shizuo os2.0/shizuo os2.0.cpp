#pragma warning(disable:4996)
#include<iostream>
#include<cstring>
using namespace std;

struct file {
	string filename;
	int filetype;
	string fileinfo;
};

file doc[1010];
string openfile[1010];
int place = 0, p = 0;

void create(string name, int type, string info, int place1)
{
	//如果一个文件都没有，就创建一个文件，不用替换
	if (place1 == 0)
	{
		doc[place1].filename = name;
		doc[place1].filetype = type;
		doc[place1].fileinfo = info;
		place++;
	}
	//先看看有没有这个文件
	if (place1 >= 1)
	{
		int k = 0;
		for (int i = 0; i < place; i++)
		{
			if (doc[i].filename == name)
			{
				k = 1;
				doc[i].filetype = type;
				doc[i].fileinfo = info;
				break;
			}
		}
		if (k == 0)
		{
			doc[place1].filename = name;
			doc[place1].filetype = type;
			doc[place1].fileinfo = info;
			place++;
		}
	}	
}

void open(string name, int place1,int p1)
{
	string a=name;
	int type1 = 1;
	while (type1 == 1)
	{
		for (int i = 0; i < place1; i++)
		{
			if (doc[i].filename == a)
			{
				type1 = doc[i].filetype;
				a = doc[i].fileinfo;
				break;
			}
		}
	}
	openfile[p1] = a;
	p++;
}

int main()
{
	string order,name,info;
	int type;
	
	for (int i = 0; i < 1000; i++)
	{
		cin >> order;
		if (order == "create")
		{
			cin >> name >> type >> info;
			create(name, type, info, place);
		}
		else if (order == "open")
		{
			cin >> name;
			open(name, place,p);
		}
		else if (order == "exit")
			break;
	}
	for (int i = 0; i < p; i++)
		cout << openfile[i] << endl;
	return 0;
}