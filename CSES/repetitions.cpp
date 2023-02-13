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
    string s;
    cin>>s;
    int n = s.length();
    int ans = 1;
    int j = 0;
    for(int i=1;i<n;i++){
        if(s[i] == s[j]){
            ans = max(ans, i-j+1);
        }else{
            j = i;
        }
    }
    cout << ans << endl;
    return 0;
}

