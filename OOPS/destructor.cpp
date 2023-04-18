#include<bits/stdc++.h>
using namespace std;

class num{
    static int count;
    public:
    num(){
        count++;
        cout << "Object created " << count << endl;
    }
    ~num(){
        cout << "Object destroyed " << count << endl;
        count--;
    }
};

int num :: count = 0;

int main(){
    cout << "We are inside our main function" << endl;
    cout << "Creating first object n1" << endl;
    num n1;
    {
        cout << "Entering this block" << endl;
        num n2, n3;
        cout << "Exiting this block" << endl;
    }
    cout << "Back to main" << endl;
    return 0;
}