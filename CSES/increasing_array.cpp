#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout << #x << ": " << x << endl
#define _rep(i, l, r) for(int i = (l); i <= (r); i++)
#define _for(i, l, r) for(int i = (l); i < (r); i++)
#define _repd(i, l, r) for(int i = (l); i >= (r); i--)
#define _ford(i, l, r) for(int i = (l); i > (r); i--)
#define _repit(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define _forit(it, a) for(auto it = a.rbegin(); it != a.rend(); it++)

int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>> A[i];
    }
    ll ans = 0;
    for(int i=1;i<n;i++){
        if(A[i] < A[i-1]){
            ans += (A[i-1] - A[i]);
            A[i] = A[i-1];
        }
    }
    cout << ans << endl;
    return 0;
}