#include <iostream>
#include <algorithm>
using namespace std;
int numcnt;
int number[2001];
int datastore[2001];

int logic(bool x, bool y, bool z, bool q)
{
	bool a[4];
	int truenum = 0;
	a[0] = x;
	a[1] = !y;
	a[2] = z;
	a[3] = !q;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] == true)
			truenum++;
	}
	return truenum;

}

void testlogic()
{
	char c[4];
	char testc[4] = { 'a','b','c','d' };
	for (int i = 0; i < 4; i++)
	{

		cin >> c[i];
		c[i] = tolower(c[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		if (logic(testc[i] == c[0], testc[i] == c[1], testc[i] == c[2], testc[i] == c[3]) == 2)
			cout << testc[i];
	}
}


int maxnum(int pos)
{
	int i;
	bool found = false;
	int retval = -0x7fffff;
	int maxval = -200000;
	if (datastore[pos] != 0xffffffff)
		return datastore[pos];
	if (pos == numcnt - 1)
		return number[pos];
	for (i = pos + 1; i < numcnt; i++)
	{
		if (number[i] > number[pos])
		{
			//datastore[i+1][number[i]]=
			datastore[i] = retval = maxnum(i);
			if (retval > maxval)
				maxval = retval;
		}
	}
	return max(maxval + number[pos], number[pos]);

}
int main()
{
	int retval;
	int maxval = -200000;
	//testlogic();
	//getchar();
	//getchar();
	//return 0;
	memset(datastore, 0xff, sizeof(datastore));
	cin >> numcnt;
	for (int i = 0; i < numcnt; i++)
		cin >> number[i];
	for (int i = 0; i < numcnt; i++)
	{
		retval = maxnum(i);
		if (retval > maxval)
			maxval = retval;
	}
	cout << maxval;
	return 0;
}
