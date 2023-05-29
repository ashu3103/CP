#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;

    vector<ll> array(n);
    for(ll i=0;i<n;i++){
        cin>>array[i];
    }

    // cout << "Helo" << endl;
    vector<vector<ll>> dp(2, vector<ll>(m+1, 0));

    for(ll i=1;i<=m;i++){
        if(array[0]!=0){
            dp[0][array[0]] = 1;
            break;
        }else{
            dp[0][i] = 1;
        }
    }

    for(ll i=2;i<=n;i++){
        if(array[i-1]!=0){
            dp[1].assign(m+1, 0);
            dp[1][array[i-1]] = (dp[0][array[i-1]]%mod + ((array[i-1]+1)<=m?dp[0][array[i-1]+1]:0)%mod + ((array[i-1]-1)>0?dp[0][array[i-1]-1]:0)%mod)%mod;
        }else{
            for(ll j=1;j<=m;j++){
                if(j==1){
                    dp[1][j] = (dp[0][j]%mod + ((j+1)<=m?dp[0][j+1]:0)%mod)%mod;
                }else{
                    dp[1][j] = (dp[0][j]%mod + ((j+1)<=m?dp[0][j+1]:0) + dp[0][j-1]%mod)%mod;
                }
            }
        }
        dp[0] = dp[1];
    }

    ll no_of_ways = 0;

    for(ll i=1;i<=m;i++){
        no_of_ways = (no_of_ways%mod + dp[0][i]%mod)%mod;
    }

    cout << no_of_ways << endl;
    return 0;
}