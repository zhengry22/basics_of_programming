
#include<iostream>
using namespace std;

long long stones[10000000]; long long n;

void Qsort(long long arr[], long long  low, long long high) {
    if (high <= low) return;
    long long i = low;
    long long j = high;
    long long key = arr[low];
    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[i] <= key)
        {
            i++;
            if (i == high) {
                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[j] >= key)
        {
            j--;
            if (j == low) {
                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        long long temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    arr[low] = arr[j];
    arr[j] = key;
    if (j == n/2) return;
    if(j>n/2) Qsort(arr, low, j - 1);
    if(j<n/2) Qsort(arr, j + 1, high);
}

int main() {
	long long sum1=0, sum2=0; 
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &stones[i]);
	}
    Qsort(stones, 1, n);
	for (long long i = 1; i <= n / 2; i++) {
		sum1 += stones[i];
	}
	for (long long i = n / 2 + 1; i <= n; i++) {
		sum2 += stones[i];
	}
	cout << sum2 - sum1;
	return 0;
}