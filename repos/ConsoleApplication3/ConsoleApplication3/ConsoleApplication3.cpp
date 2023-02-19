#include<iostream>
using namespace std;

int a[10];
int i = 0;

void push(int b)
{
    a[i] = b;
    i++;
}

int pop()
{
    int m=a[i - 1];
    i--;
    return m;
}

int main()
{
    for (int j = 0; j < 10; j++)
    {
        push(j * j);
    }
    for (int j = 0; j < 10; j++)
    {
        cout<<pop()<<endl;
    }
   
    return 0;
}


