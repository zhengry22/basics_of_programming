#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

struct student {
	char name[10];
	int age;
	double grade;
};

int main()
{	
	//student stds[3] = { {"alice",18,99.09},{"bob",19,97.44},{"carol",17,100} };
	//ofstream fout;
	//fout.open("testfile.txt");//, ios_base::out | ios_base::binary);
	//fout.write((char*)stds, sizeof(student) * 3);
	//fout.close();


	//student stds2[3];
	//ifstream fin("testfile.txt");// , ios_base::in | ios_base::binary);
	////fin.read((char*)stds2, sizeof(student) * 3);
	//for (int i = 0; i < 3; i++)
	//{
	//	fin >> stds2[i].name >> stds2[i].age >> stds2[i].grade;
	//}
	//for (auto e : stds2) {
	//	cout.width(10);
	//	cout << e.name;
	//	cout.width(10);
	//	cout << hex <<e.age;
	//	cout.width(10);
	//	cout << e.grade << endl;
	//}
	//

	

	//istringstream iss("alice 20 19.99\n alice 2\n 0 19.\n 99");
	//char tmp[100];
	////read from iss
	//iss.getline(tmp, strlen(tmp));
	//ofstream fout("testfile3.txt");
	//fout.write((char*)tmp, sizeof(char) * strlen(tmp));
	//fout.close();

	/*char array[10];
	for (int i=0;i<10;i++)
	{
		array[i] = i*10;
	}
	istringstream iss2;
	for(int i=0;i<10;i++)
	{
		iss2 >> array[i]; 
	}
	ofstream off("testfile3.txt");
	for (int i = 0; i < 10; i++)
		off << array[i];*/
	return 0;
}
//二进制存储vs文本存储：
//二进制存储直接将内存中的内容原封不动地照搬到文件当中，不涉及类型转换的工序；而文本存储则是需要一个类型转换的过程，消耗时间