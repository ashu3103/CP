#include<bits/stdc++.h>
using namespace std;

// Base Class
class Employee{
    public:
        int id;
        float salary;
        Employee(){}

        Employee(int inpId){
            id = inpId;
            salary = 34.0;
        }
};

// Derived Class
class Programmer: Employee{
    public:
        int languageCode = 9;
        Programmer(int inpId){
            id = inpId;
        }
};

int main(){
    Programmer pr(1);
    cout << pr.languageCode << endl;
    return 0;
}