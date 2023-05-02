#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int help(vector<ll>&C, ll wt, vector<ll>&dp){
    if(wt==0) return 1;
    if(wt<0) return 0;

    if(dp[wt] != -1) return dp[wt];

    ll n = C.size();
    ll ans = 0;


    for(int i=0;i<n;i++){
        ans = (ans%mod + help(C, wt-C[i], dp)%mod)%mod;
    }

    return dp[wt] = ans%mod;
}

int main(){

    ll n, wt;
    cin>>n>>wt;

    vector<ll> coins(n);
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<ll> dp(wt+1, -1);

    cout << help(coins, wt, dp) << endl;

    return 0;
}