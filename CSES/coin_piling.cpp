#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if((x+y)%3==0 && abs(x-y) <= (x+y)/3){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}