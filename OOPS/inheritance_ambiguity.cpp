#include<bits/stdc++.h>
using namespace std;

class Base1{
    public:
        void greet(){
            cout << "Hello" << endl;
        }
};

class Base2{
    public:
        void greet(){
            cout << "Namaste" << endl;
        }
};

class Derived: public Base1, public Base2 {
    int a;
    public:
        // resolving ambiguity
        void greet(){
            Base1 :: greet(); // calling greet of Base1
        }
};

// but !!!!!!!!!!!!!!!!!!!

class B{
    public:
        void say(){
            cout << "Namaste" << endl;
        }
};

class D : public B{
    public:
        // no ambiguity as say of derived class will run
        void say(){
            cout << "Hello" << endl;
        }
};

int main(){
    Derived der;
    der.greet(); // Base1 greet will run

    return 0;
}