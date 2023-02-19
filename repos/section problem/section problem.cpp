#include<iostream>
using namespace std;

struct segment {
	int st;
	int ed;
};

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

void swap(segment* a, segment* b)
{
	segment temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(segment *p, int n)
{
	for (int i=n-2; i>=0; i--)
	{
		int flag = 0;
		for (int j = 0; j <= i; j++)
		{
			if (p[j].st > p[j + 1].st)
			{
				flag = 1;
				swap(&p[j], &p[j + 1]);
			}
		}
		if (flag == 0)
			break;
	}
}

void merge_sort(segment* p, int l, int r)
{
	int mid = (l + r) >> 1;
	segment* tmp;
	//finish
	if (l >= r)
		return;
	//recursion
	merge_sort(p, l, mid);
	merge_sort(p, mid + 1, r);
	//put the sorted numbers in tmp
	tmp = new segment[r - l + 1];
	int x = l, y = mid+1, z = 0;
	while (x <= mid && y <= r)
	{
		if (p[x].st <= p[y].st)
			tmp[z++] = p[x++];
		else
			tmp[z++] = p[y++];
	}
	//there might be some left in the left or right side
	while (x <= mid)
	{
		tmp[z] = p[x];
		z++, x++;
	}
	while (y <= r)
	{
		tmp[z] = p[y];
		z++, y++;
	}
	//now numbers in tmp is in correct order
	for (int i = 0, j = l; j <= r; i++, j++)
	{
		p[j] = tmp[i];
	}
	delete[] tmp;
}


void quick_sort(segment* p, int l, int r)
{
	
	int x = p[(l + r) >> 1].st;//as a standard for comparison
	int i = l, j = r;
	if (l >= r)
		return;
	while (i < j)
	{   /*do {
			i++;
		} while ((p[i].st <= x) && (i < j));*/
		/*		do {
			j--;
		} while ((p[j].st > x) && (j > i));*/
		while ((p[i].st <= x) && (i < j))
		{
			i++;
		}
		while ((p[j].st > x) && (j > i))
		{
			j--;
		}
		if (i < j)
			swap(&p[i], &p[j]);
		else if(i==j)
		{
			i--;
			break;
		}
	}
	
	quick_sort(p, l, i);
	quick_sort(p, i + 1, r);
}



int main()
{
	int cnt = 0, end = 1, maxi=1;
	segment* seg;
	int n, m;
	n = 6;
	m = 100;
	//cin >> n >> m;
	seg = new segment[n];
	for (int i = 0; i < n; i++)
	{
		seg[i].st = rand();//cin>>seg[i].st >> seg[i].ed;
	}
		


	//sort segments in terms of st
	quick_sort(seg, 0, n-1);

	for (int i = 0; i < n; i++)
		cout << seg[i].st << endl;

	/*if (seg[0].st != 1)
	{
		cout << -1;
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (seg[i].st <= end)
			{
				maxi = max(maxi, seg[i].ed);
				if (seg[i].ed >= m)
				{
					cnt++;
					break;
				}
			}	
			else if (seg[i].st > end)
			{
				cnt++;
				end = maxi;
				maxi = max(end, seg[i].ed);
				if (seg[i].st > end)
				{
					cout << -1;
					return 0;
				}
				else if ((seg[i].st <= end) && (seg[i].ed >= m))
				{
					cnt++;
					break;
				}
			}
		}
	}
	cout << cnt;*/
	
	return 0;
}