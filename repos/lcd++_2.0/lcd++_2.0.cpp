#include<iostream>
using namespace std;

long long tests[11], numbers[11][3000];

void swap(long long* a, long long* b) {
    long long tmp = *a;
    *a = *b;
    *b = tmp;
}

long long lcd(long long a, long long b, long long maximum) {
    if (a < b) swap(&a, &b);
    if (maximum >= a) return 0;
    while (b != 0) {
        a = a % b;
        return lcd(a, b, maximum);
    }
    return a;
}

void merge_sort(long long* num, long long l, long long r)
{
    long long middle = (l + r) / 2, * tmp, lp = l, rp = middle + 1;
    //when to return 
    if (l == r)
        return;
    //first, merge the left and right part
    merge_sort(num, l, middle);
    merge_sort(num, middle + 1, r);
    //create a new array to dispose number
    tmp = new long long[r - l + 1];
    long long flag = 0;
    while ((lp <= middle) && (rp <= r))
    {
        if (num[lp] <= num[rp])
        {
            tmp[flag] = num[lp];
            lp++;
        }
        else
        {
            tmp[flag] = num[rp];
            rp++;
        }
        flag++;
    }
    if (lp <= middle)
    {
        for (long long i = lp; i <= middle; i++)
        {
            tmp[flag] = num[i];
            flag++;
        }
    }
    if (rp <= r)
    {
        for (long long i = rp; i <= r; i++)
        {
            tmp[flag] = num[i];
            flag++;
        }
    }
    //put the numbers in tmp into num
    for (long long i = 0, j = l; i < r - l + 1; i++, j++)
    {
        num[j] = tmp[i];
    }
    delete[] tmp;
}

int main() {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> tests[i];
        for (long long j = 1; j <= tests[i]; j++) {
            cin >> numbers[i][j];
        }
    }
    for (long long i = 1; i <= n; i++) {
        merge_sort(numbers[i], 1, tests[i]);
    }
    for (long long i = 1; i <= n; i++) {
        long long maximum = 0;
        for (long long j = tests[i]; j > 1; j--) {
            if (numbers[i][j] <= maximum) break;
            for (long long k = j - 1; k >= 1; k--) {
                long long tmp = lcd(numbers[i][j], numbers[i][k], maximum);
                maximum = tmp > maximum ? tmp : maximum;
            }
        }
        if (i < n)cout << maximum << endl;
        else if (i == n) cout << maximum;
    }
    return 0;
}