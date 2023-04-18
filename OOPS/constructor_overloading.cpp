#include<bits/stdc++.h>
using namespace std;

class Complex{
    int a,b;
    public:
        Complex(int x,int y){
            a = x;
            b = y;
        }
        // Constructor overloading
        Complex(int x){
            a = x;
            b = 0;
        }
        void printNumber(){
            cout << a << "+" << b << "i" << endl;
        }
};

int main(){
    Complex comp1(2,3);
    Complex comp2(2);
    comp1.printNumber();
    comp2.printNumber();
    return 0;
}