#include <iostream>
#include<cstdlib>
#include<time.h>
#define A 10
#define LEFT 1
#define RIGHT 10
using namespace std;


//�������������
void genseeds()
{
    srand(time(0));
}

//���������
//minnum��Сֵ
//maxnum���ֵ
//num����
//numperlineÿ�м�����
void genrandnumber(int minnum, int maxnum, int num, int numperline = 10)
{
    genseeds();
    for (int i = 0; i < num; i++)
    {
        int a = rand() % (maxnum - minnum + 1) + minnum;
        cout << a << (((i + 1) % numperline == 0) ? '\n' : ' ');
        //cout << a+rand() % (maxnum - minnum + 1) + minnum << endl;
    }
       
}


int main()
{
    cout <<A<<' '<< A << endl;
    genrandnumber(LEFT, RIGHT, A, A);
    //std::cout << "Hello World!\n";
}