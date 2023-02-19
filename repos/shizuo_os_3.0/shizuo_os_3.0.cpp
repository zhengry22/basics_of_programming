#include<iostream>
#include<string>
using namespace std;

struct files {
	string filename;
	int filetype;
	string fileinfo;
};

files os[1000]; int flag = 0;

void open(string name) {
	for (int i = 0; i < flag; i++) {
		if (os[i].filename == name) {
			if (os[i].filetype == 0) {
				cout << os[i].fileinfo<<endl;
				return;
			}
			else {
				open(os[i].fileinfo);
			}
		}
	}
}

int main() {
	string order;
	for (int i = 1; i <= 1000; i++)
	{
		cin >> order;
		if (order == "create") {
			string tmp_name; int tmp_type; string tmp_info; int repeat = 0;
			cin >> tmp_name >> tmp_type >> tmp_info;
			for (int i = 0; i < flag; i++) {
				if (os[i].filename == tmp_name) {
					repeat = 1;
					os[i].filetype = tmp_type;
					os[i].fileinfo = tmp_info;
					break;
				}
			}
			if (repeat == 0) {// no repetition
				os[flag] = { tmp_name, tmp_type, tmp_info };
				flag++;
			}
		}
		else if (order == "open") {
			string tmp_name;
			cin >> tmp_name;
			open(tmp_name);
		}
		else if (order == "exit")
			break;
	} 
	return 0;
}