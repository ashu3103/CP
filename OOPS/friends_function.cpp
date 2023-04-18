#include<bits/stdc++.h>
using namespace std;

class Complex{
private:
    int a;
    int b;
public:
    void setNumber(int a1,int b1){
        a = a1;
        b = b1;
    }
    void printNumber(){
        cout << a << "+" << b << "i" << endl;
    }
    friend Complex sumComplex(Complex o1, Complex o2); // make sumComplex friend of Complex class so that it can access private data members
};

// normal functions can't access private data members
Complex sumComplex(Complex o1, Complex o2){
    Complex sum;
    sum.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return sum;
}


int main(){
    Complex x,y,sum;
    x.setNumber(1,4);
    x.printNumber();

    y.setNumber(2,3);
    y.printNumber();

    sum = sumComplex(x, y);
    sum.printNumber();
    return 0;
}