#include<bits/stdc++.h>
using namespace std;

class Complex{
    int real;
    int imaginary;
    public:
    void setData(int r, int i){
        real = r;
        imaginary = i;
    }

    void getData(){
        cout << "Real Part - " << real << "\nImaginary Part - " << imaginary << endl;
    }
};

int main(){

    Complex* ptr = new Complex[4]; // Array of objects
    Complex* ptrTmp = ptr;
    int p,q;
    for(int i=0;i<4;i++){
        cin>>p>>q;
        ptr->setData(p, q);
        ptr++;
    }
    ptr = ptrTmp;
    for(int i=0;i<4;i++){
        ptr->getData();
        ptr++;
    }
    return 0;
}
