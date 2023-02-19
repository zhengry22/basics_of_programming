#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;

class herb{
public:
	herb(int n): num(n) {
		time_tab.resize(n + 1);
		price_tab.resize(n + 1);
		memset(val, -1, sizeof(int) * 1001 * 101);
	}
	herb() :num(0)
	{
		time_tab.resize(0);
		price_tab.resize(0);
		memset(val, -1, sizeof(int) * 1001 * 101);
	}
	int value(int k, int t);
	void set_time_price(int t, int p, int i) {
		time_tab[i] = t;
		price_tab[i] = p;
	}
	herb(const herb& h) : time(h.time), num(h.num)
	{

	}
	friend istream& operator >> (istream& in, herb &med);
	int get_time()
	{
		return time;
	}
	int get_num()
	{
		return num;
	}
	//friend ostream& operator << (ostream& out, herb &med);
	friend ostream & operator << (ostream& out, herb& med);

private:
	vector<int> time_tab;
	vector<int> price_tab;
	int time;
	int num;
	int val[1001][101];
	int result;
};

 int herb::value(int k, int t)
{
	int tmp1, tmp2;
	if (k == 0 || t <= 0)
		return 0;
	if (val[t][k] != -1)
		return val[t][k];
	else
	{
		tmp1 = val[t][k-1] = value(k-1, t);

		if (t - time_tab[k] < 0)
		{
			return val[t][k-1];
		}
		else
		{
			val[t - time_tab[k]][k-1] = value(k - 1, t - time_tab[k]);
			tmp2 = val[t - time_tab[k]][k - 1] + price_tab[k];
			return tmp1 > tmp2 ? tmp1 : tmp2;
		}
	}


}

 istream & operator >> (istream & in, herb & med) {
	 in >> med.time>>med.num;
	 med.time_tab.resize(med.num + 1);
	 med.price_tab.resize(med.num + 1);
	 for (int i = 1; i <= med.num; i++)
	 {
		 in >> med.time_tab[i]>> med.price_tab[i];
	 }
	 med.result=med.value(med.get_num(), med.get_time());
	 return in;
 }
 
 ostream & operator << (ostream & out, herb & med) {
	 out << med.result;
	 return out;
 }


int main()
{
	ifstream fin("Herb.txt");
	ofstream fout("Herb_result.txt");
	if (!fin)
	{
		cout << "fail to read" << endl;
		return 1;
	}
	herb med;
	fin >> med;
	if (!fout)
	{
		cout << "fail to write" << endl;
		return 1;
	}
	fout << med;
	return 0;
}//注意二维数组的行列含义 不要写反了