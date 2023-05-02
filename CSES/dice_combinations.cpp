#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

vector<ll> outcome(1e6, -1*1LL);

ll help(ll n, vector<ll>&dp){
    if(n==0) return 1;

    if(dp[n-1] != -1) return dp[n-1];

    ll ans = 0;
    for(ll i=1;i<=6;i++){
        if(i<=n){
            ans = (ans%mod + help(n-i, dp)%mod)%mod;
        }
    }
    return dp[n-1] = ans%mod;
}

int main(){
    ll n;
    cin>>n;
    cout << help(n, outcome) << endl;
    return 0;
}