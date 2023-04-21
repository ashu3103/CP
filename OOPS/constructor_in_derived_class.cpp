#include<bits/stdc++.h>
using namespace std;

/*
    Case1:
    class B: public A{
        // order of execution of contructor -> first A() then B()
    }

    Case2:
    class C: public A, public B{
        // order of execution of constructor -> A() then B() then C()
    }

    Case3:
    class C: public A, virtual public B{
        // order of execution of constructor -> B() then A() then C()
    }
*/

class Base1{
    int data1;
    public:
        Base1(int i){
            data1 = i;
            cout << "Base1 constructor called" << endl;
        }
        void print_data(){
            cout << "Data1: "<< data1 << endl;
        }
};

class Base2{
    int data2;
    public:
        Base2(int i){
            data2 = i;
            cout << "Base2 constructor called" << endl;
        }
        void print_data(){
            cout << "Data2: " << data2 << endl;
        }
};

class Derived: public Base1, public Base2{
    int der1, der2;
    public: 
        Derived(int a,int b,int c,int d): Base1(a), Base2(b){
            der1 = c;
            der2 = d;
            cout << "Derived Class constructor called" << endl;
        }
        void print_data(){
            Base1::print_data();
            Base2::print_data();
        }
};

int main(){
    Derived de(1,2,3,4);
    de.print_data();
    return 0;
}