#include<bits/stdc++.h>
using namespace std;

class Number{
    int val;
    public:
        Number(){
            val = 0;
        }
        Number(int a){
            val = a;
        }
        // Copy Constructor (overloaded)
        Number(Number &obj){
            cout << "Copy Constructor Called!!" << endl;
            val = obj.val;
        }
        void display(){
            cout << val << endl;
        }
};

int main(){
    Number x,y,z(45);
    x.display();
    y.display();
    z.display();
    Number z1(x);
    z1.display();

    Number z2 = z; // Copy constructor will be invoked here also
    z2.display();
    return 0;
}