#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    set<int> S;
    for(int i=0;i<n;i++){
        cin>>A[i];
        S.insert(A[i]);
    }
    cout << S.size() << endl;
    return 0;
}