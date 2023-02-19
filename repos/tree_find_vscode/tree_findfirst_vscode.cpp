#include<iostream>
#include<io.h>
#include<fstream>
using namespace std;

_finddata_t fileinfo;

void file_tree_create()
{
	//first find a file
	int k;
	long handle;
	k=handle= _findfirst(".\\*", &fileinfo);
	while (k != 1)
	{
		cout << fileinfo.name << endl;
		k = _findnext(handle, &fileinfo);
	}
}

int main()
{
	file_tree_create();
	return 0;
}