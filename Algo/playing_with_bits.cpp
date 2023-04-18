#include<bits/stdc++.h>
using namespace std;

// 1 0101010 1
// MSB       LSB

class binaryNum
{
    private:
        int num;
    public:
        binaryNum(int n);
        ~binaryNum();
        void printBinary();
        bool checkithBitSet(int i);
        int unsetBinaryAtithPos(int i);
        int countSetBits();
        string oddEvenCheck();
        int clearithLSB(int i);
        int clearithMSB(int i);
        bool checkPowerOf2();
};

binaryNum::binaryNum(int n)
{
    num = n;
}

binaryNum::~binaryNum()
{
    return;
}

void binaryNum::printBinary(){
    for(int i=31;i>=0;i--){
        cout << ((num>>i)&1);
    }
    cout << endl;
}

bool binaryNum::checkithBitSet(int i){
    return (num & (1<<i));
}

int binaryNum::unsetBinaryAtithPos(int i){
    return (num & (~(1<<i)));
}

int binaryNum::countSetBits(){
    int cnt = 0;
    for(int i=0;i<=31;i++){
        if((num>>i) & 1){
            cnt++;
        }
    }
    return cnt;
}

string binaryNum::oddEvenCheck(){
    if(num&1){
        return "ODD";
    }
    return "EVEN";
}

int binaryNum::clearithLSB(int i){
    return (num & (~((1<<(i+1))-1)));
}

int binaryNum::clearithMSB(int i){
    return (num & ((1<<(i+1))-1));
}

bool binaryNum::checkPowerOf2(){
    return (num & (num-1));
}

int main(){
    int n;
    cin>>n;
    binaryNum* bin = new binaryNum(n);
    bin->printBinary();
    cout << bin->countSetBits() << endl;
    return 0;
}