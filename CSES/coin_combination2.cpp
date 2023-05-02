#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

ll help(vector<ll>&C, ll wt, ll ind, vector<vector<ll>>&dp){
    if(wt==0) return 1;
    if(wt<0 || ind>=C.size()) return 0;

    if(dp[ind][wt] != -1) return dp[ind][wt];

    if(C[ind]<=wt){
        return dp[ind][wt] = (help(C, wt-C[ind], ind, dp) + help(C, wt, ind+1, dp));
    }

    return dp[ind][wt] = help(C, wt, ind+1, dp);
}

int main(){
    ll n,wt;
    cin>>n>>wt;

    vector<ll> coins(n);
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }

    int dp[n+1][wt+1];

    for(int i=0;i<n;i++)
        for(int j=0;j<=wt;j++)
            dp[i][j] = 0;

    dp[0][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=wt;j++){
            dp[i][j] = dp[i-1][j];
            if(coins[i-1] <= j){
                (dp[i][j] += dp[i][j-coins[i-1]])%=mod;
            }
        }
    }

    cout << dp[n][wt] << endl;
    return 0;
}