#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
 
ll help(vector<ll>&C, ll wt, vector<ll>&dp){
    if(wt==0) return 0;
    if(wt<0) return INT_MAX;
 
    if(dp[wt] != -1) return dp[wt];
 
    int n = C.size();
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        if(C[i]<=wt){
            ll out = 1+help(C, wt-C[i], dp);
            if(ans > out){
                ans = out;
            }
        }
    }
    return dp[wt] = ans;
}
 
int main(){
    ll n, wt;
    cin>>n>>wt;
 
    vector<ll> coins(n);
 
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }
 
    vector<ll> dp(wt+1, -1);
 
    ll x = help(coins, wt, dp);

    if(x>=INT_MAX){
        cout << -1 << endl;
        return 0;
    }
    cout << x << endl;
    return 0;
}