#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout << #x << ": " << x << endl
#define _rep(i, l, r) for(int i = (l); i <= (r); i++)
#define _for(i, l, r) for(int i = (l); i < (r); i++)

template<typename T> inline void read(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
    x *= f;
}

int Xor(int n){
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = ans ^ i;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> A(n-1);
    int b = 0;
    for(int i=0;i<n-1;i++){
        cin>>A[i];
        b = b^A[i];
    } 
    int a = Xor(n);
    cout << (a^b) << endl;
    // Problem solving code here
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1; // cin >> testCases;
    for (int tc = 1; tc <= testCases; tc++) {
        solve();
    }
    return 0;
}
