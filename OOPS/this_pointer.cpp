#include<bits/stdc++.h>
using namespace std;

class A{
    int a;
    public:
        void setData(int a){
            this->a = a;
        }
        void getData(){
            cout << a << endl;
        }
};

/*
    this keyword is a pointer which points to the object which invokes the member function
    Usage :-
        
*/

int main(){
    A a;
    a.setData(1);
    a.getData();
    return 0;
}