#include<bits/stdc++.h>
using namespace std;


int main(){

    int n, t;
    cin>>n>>t;
    multimap<int,int> M;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
        M.insert({A[i], i+1});
    }

    sort(A.begin(), A.end());

    int s=0;
    int e=n-1;

    while(s<e){
        if(A[s]+A[e] == t){
            if(A[s] == A[e]){
                // cout << "Execute" << endl;
                auto it = M.find(A[s]);
                // for(auto i: M){
                //     cout << i.first << " " << i.second << endl;
                // }
                // cout << "Break" << endl;
                int a = it->second;
                M.erase(it);
                // for(auto i: M){
                //     cout << i.first << " " << i.second << endl;
                // }
                it = M.find(A[s]);
                int b = it->second;
                cout << a << " " << b << endl;
            }else{
                cout << M.find(A[s])->second << " " << M.find(A[e])->second << endl;
            }
            return 0;
        }else if(A[s]+A[e] < t){
            s++;
        }else{
            e--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;

}