#include <iostream>
using namespace std;
class A {
public:
    virtual ~A() { }

    virtual void print() const {
        std::cout << "In A" << std::endl;
    }
};

class B : public A {
public:
    B() { }
    virtual ~B() { }

    virtual void print() const {
        std::cout << "In B" << std::endl;
    }
};

void doSomething(A* a) {
    a->print();
    cout << "dst1 called" << endl;
}

void doSomething(const B &a) {
    a.print();
    cout << "dst2 called" << endl;
}

int main()
{
    //A* a = new B();
    //doSomething(a);
    //a->print();
    B b;
    doSomething(B());
    doSomething(b);
    return 0;
}
