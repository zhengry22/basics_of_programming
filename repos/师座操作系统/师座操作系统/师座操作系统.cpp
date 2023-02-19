#include<iostream>
#include<cstring>
#define hn 27
using namespace std;

int opendoc(char name[]);

struct document {
	char docname[21];
	bool doctype;
	char docinfo[21];
};

document create(char name[], char type, char info[]);

document hashdoc[27][1000];

int opendoc(char name[])
{
	int e = 0xffff;
	//e用来判断我们想open的文件在hashdoc表里是否存在
for (int i = 0; i < 1000; i++)
	{
		if (strcmp(hashdoc[name[0]%hn][i].docname, name) == 0)
		{
			e = i;
			if (hashdoc[name[0]%hn][i].doctype == 0)
				cout << hashdoc[name[0]%hn][i].docinfo;
			else if (hashdoc[name[0]%hn][i].doctype == 1)
				opendoc(hashdoc[name[0]%hn][i].docinfo);
		}
		else if (hashdoc[name[0]%hn][i].docname == '\0')
			break;
	}
	return e;
}

document create(char name[], char type, char info[])
{
	//先判断在hashdoc里面是否存在这个文件，如果存在就删除，不存在的话就创建
	int count[27] = { 0 };
	if (opendoc(name) != 0xffff)
	{
		strcpy(hashdoc[name[0]%hn][opendoc(name)].docinfo, info);
	}
	else 
	{
		strcpy(hashdoc[name[0]%hn][count[name[0]%hn]].docname, name);
		count[name[0]%hn]++;
	}
}

int main()
{
	char order[10], name1[20], type1, info1[20];
	int k = 0;
	for (int i = 0; i < 1001; i++)
	{
		cin >> order >> name1 >> type1 >> info1;
		if (strcmp(order,"create")==0)
		{
			create(name1, type1, info1);
		}
		else if (strcmp(order, "open") == 0)
		{
			opendoc(name1);
		}
		else if (strcmp(order, "exit") == 0)
		{
			break;
		}
	}
	return 0;
}