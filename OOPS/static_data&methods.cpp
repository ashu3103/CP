#include<bits/stdc++.h>
using namespace std;

class Employee{
private:
    int id;
    static int count;
public:
    void setData(){
        cout << "Enter the id: " << endl;
        cin>>id;
        count++;
    }
    void getData(){
        cout << "ID: " << id << endl;
        cout << "Employee Number: " << count << endl;
    }
};

int Employee:: count = 0; // Reference of static variable count

int main(){

    Employee ashu, sass;
    ashu.setData();
    ashu.getData();

    sass.setData();
    sass.getData();

    return 0;
}