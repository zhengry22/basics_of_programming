#include<iostream>
#include<vector>
#include<io.h>
#include<cstring>
#include<fstream>
using namespace std;

class file_info {
public:
	void sort(file_info arr[]);
	file_info(bool tp, int lv) :type(tp), lev(lv) {
	}
	file_info() :type(0), lev(0) {
	}

	file_info(const file_info& f) :type(f.type), lev(f.lev), name(f.name) {
	}
	void set_fileinfo(bool tp, int lv, string nm)
	{
		type = tp;
		lev = lv;
		name = nm;
	}
	void get_name()
	{
		cout << name;//<<endl;
	}
	bool type;//file is 0, folder is 1
	string name;
	int lev;
private:

};

int min(int a, int b)
{
	return (a <= b) ? a : b;
}

void swap(file_info& a, file_info& b)
{
	file_info tmp(a);
	a.set_fileinfo(b.type, b.lev, b.name);
	b.set_fileinfo(tmp.type, tmp.lev, tmp.name);
}

bool left_small(string a, string b)
{
	for (int i = 0; i < min(a.size(), b.size()); i++)
	{
		if (a[i] < b[i])
			return true;
		if (a[i] > b[i])
			return false;
	}
	if (a.size() < b.size())
		return true;
	else
		return false;
}

bool dic_sort(file_info a, file_info b)
{
	return (a.type && !b.type) || ((a.type == b.type) && left_small(a.name, b.name));
}

bool (*sort_rule)(file_info a, file_info b);

void file_sort(vector<file_info> &array, bool (* rule)(file_info a, file_info b))
{
	for (int i = array.size() - 2; i >= 0; i--)
	{
		int flag = 0;
		for (int j = 0; j <= i; j++)
		{
			if (rule(array[j],array[j+1]))
			{
				flag = 1;
				swap(array[j], array[j + 1]);
			}				
		}
		if (flag == 0)
			break;
	}
}




void file_tree_create(string sign,int lev,bool type,string fname)
{
	if (fname != "."&&fname!="..")
	{
		for (int i = 1; i <= lev; i++)
		{
			cout << "  ";
		}
		cout << "|-" << fname << endl;
	}
	
	if (type==false)
		return;
	
	_finddata_t fileinfo;
	int k;
	intptr_t handle;
	string name;
	file_info info;
	vector<file_info> container;
	k=handle= _findfirst((sign + "*").c_str(), &fileinfo);
	name= fileinfo.name;

	while (k != -1)
	{
		if ((name != ".") && (name != ".."))
		{
			/*for (int i = 1; i <= lev; i++)
			{
				cout << "  ";
			}
			cout << "|-" << fileinfo.name << endl;*/
			if ((fileinfo.attrib & _A_SUBDIR) == _A_SUBDIR)//is dir
			{
				info.set_fileinfo(1, lev, name);
				container.push_back(info);
				//file_tree_create(sign+name + "/",lev+1);
				k = _findnext(handle, &fileinfo);
				name = fileinfo.name;
			}
			else //is file
			{
				info.set_fileinfo(0, lev, name);
				container.push_back(info);
				k = _findnext(handle, &fileinfo);
				name = fileinfo.name;
			}

		}
		else
		{
			//cout << "|-" << fileinfo.name << endl;
			k = _findnext(handle, &fileinfo);
			name = fileinfo.name;
		}
	}
	file_sort(container, sort_rule);
	for (auto e : container)
	{
		file_tree_create(sign+e.name + "/",lev+1,e.type,e.name);	
	}
	
	_findclose(handle);

}

int main()
{
	sort_rule = dic_sort;
	file_tree_create("./",0,1,".");
	return 0;
}