#include<bits/stdc++.h>
using namespace std;

class Employee{
private:
    int a,b,c;
public:
    int d,e;
    void setData(int a,int b,int c); // Declaration only
    void getData(){
        cout << "Value of a is "<< a << endl;
        cout << "Value of b is "<< b << endl;
        cout << "Value of c is "<< c << endl;
    }
};

void Employee::setData(int a1,int b1,int c1){
    a = a1;
    b = b1;
    c = c1;
}

int main(){
    Employee ashu;
    ashu.getData();
    ashu.setData(1,2,3);
    ashu.getData();
    return 0;
}