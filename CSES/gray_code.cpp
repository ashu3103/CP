#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> help(int n){
    if(n==1){
        vector<string> A = {"0", "1"};
        return A;
    }
    vector<string> A = help(n-1);
    vector<string> ans;
    for(int i=0;i<A.size();i++){
        ans.push_back("0" + A[i]);
    }
    for(int i=A.size()-1; i>=0;i--){
        ans.push_back("1" + A[i]);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> A = help(n);
    for(int i=0;i<A.size();i++){
        cout << A[i] << endl;
    }
    return 0;
}