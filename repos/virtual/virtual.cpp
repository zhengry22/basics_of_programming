#include <iostream>
using namespace std;
class Base {
public:
   virtual ~Base(); //不是虚函数
};
Base::~Base() {
    cout << "Base destructor" << endl;
}
class Derived : public Base {
public:
    Derived();
    virtual ~Derived(); //不是虚函数
private:
    int* p;
};

Derived::Derived()
{
    p = new int(0);
}
Derived::~Derived()
{
    
    cout << "Derived destructor" << endl;
}

int main()
{
    Base* b = new Derived();
    delete b;
    return 0;
}


