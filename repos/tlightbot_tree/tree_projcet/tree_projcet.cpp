#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>

using namespace std;
using namespace std::filesystem;

int length,flag=0;

class fileinfo {
public:
    void sort(fileinfo arr[]);
    fileinfo(bool tp, int lv) :type(tp), lev(lv){   
    }
    fileinfo() :type(0), lev(0){
    }

    fileinfo(const fileinfo& f) :type(f.type),lev(f.lev),name(f.name){
    }
    void set_fileinfo(bool tp, int lv, wstring nm)
    {
        type = tp;
        lev = lv;
        name = nm;
    }
    void get_name()
    {
        wcout << name;//<<endl;
    }
    bool type;//file is 0, folder is 1
    wstring name;
    int lev;
private:
   
};

void swap(fileinfo &a, fileinfo &b)
{
    fileinfo tmp(a);
    a.set_fileinfo(b.type, b.lev, b.name);
    b.set_fileinfo(tmp.type, tmp.lev, tmp.name);
}

void file_sort(vector<fileinfo> array)
{
    //
}

void enumdir(path& directory,int lev)
{
    //int flag_main = , flag_save = 0;
    file_status s;
    path p;
    wstring str;
    vector<fileinfo> container;
    fileinfo middle;
    for (auto it = directory_iterator(directory); it != directory_iterator(); ++it)
    {  
        char* pdir;  
        s = it->symlink_status();
        switch (s.type())
        {
        case file_type::regular://files
            p = *it;
            str = p.filename();           
           /* for (int i = 1; i <= lev; i++)
            {
               wcout << "    ";
            }
            wcout << "|-";
            wcout << str.c_str() << endl;*/
            middle.set_fileinfo(0, lev, str);
            container.push_back(middle);
            break;
        case file_type::directory://folder
            p = *it;
            str = p.filename();
            /*for (int i = 1; i <= lev; i++)
            {
                wcout << "    ";
            }
            wcout << "|-";
            wcout << str.c_str() << endl;*/
            middle.set_fileinfo(1, lev, str);
            container.push_back(middle);
            enumdir(p, lev + 1);
            break;          
        }  
    }
    file_sort(container);
    for (auto e : container)
    {
        for (int i = 1; i <= e.lev; i++)
        {
            cout << "  ";
        }
        wcout << "|-" << e.name << endl;
    }
}

int main()
{
    path  dir = ".";
    vector<fileinfo> array;
    enumdir(dir,1);

    getchar();
}


