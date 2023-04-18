#include<bits/stdc++.h>
using namespace std;

// Forward Declaration
// Tell Compiler at line 14 that Complex is present and declared afterwards
class Complex;

class Calculator{
    public:
        int add(int a, int b){
            return a+b;
        }

        int sumRealComplex(Complex o1, Complex o2);
        // Commented becuz will give errors as Complex defined at line 6 doesn't define the data members so Compiler will not be able to understand 'o1.a'
        // int sumRealComplex(Complex o1, Complex o2){
        //     return (o1.a + o2.a);
        // }
};

class Complex{
    private:
        int a;
        int b;
        friend int Calculator :: sumRealComplex(Complex o1, Complex o2);
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

// So sumRealComplex is defined after declaration of Complex class
int Calculator::sumRealComplex(Complex o1, Complex o2){
    return (o1.a + o2.a);
}

int main(){
    
    return 0;
}


// IMPORTANT IMPORTANT IMPORTANT IMPORTANT