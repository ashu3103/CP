#include<bits/stdc++.h>
using namespace std;

// Polymorphism

class Base{
    public:
        int data = 1;
        void display(){
            cout << "Base display is called" << endl;
            cout << data << endl;
        }
};

class Derived: public Base{
    int data = 2;
    public:
        void display(){
            cout << data << endl;
        }
        void display2(){
            cout << data << endl;
        }
};

class Base2{
    int data = 1;
    public:
    virtual void display(){
        cout << data << endl;
    }
};

class Derived2: public Base2{
    int data = 2;
    public:
        void display(){
            cout << "Derived display is called" << endl;
            cout << data << endl;
        }
};

int main(){
    Base* base = new Derived();
    base->display();     // Since pointer is of Base Class so it will display of base class
    cout << base->data << endl;

    Base2* base2 = new Derived2();
    base2->display();     // display of Derivde Class will be called
    return 0;
}