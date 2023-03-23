#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> A(n);
    vector<int> B(m);
    multiset<int> M;
    for(int i=0;i<n;i++){
        cin>>A[i];
        M.insert(A[i]);
    }
    for(int i=0;i<m;i++){
        cin>>B[i];
    }
    multiset<int>::iterator it;
    for(int i=0;i<m;i++){
        it = M.upper_bound(B[i]);
        if(it == M.begin()){
            cout << -1 << endl;
        }else{
            it--;
            cout << (*it) << endl;
            M.erase(it);
        }
    }

    return 0;
}

// 5 3
// 3 5 5 7 8
// 3 4 8