#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;

    ll total_sum = (n*(n+1))/2;
    if(total_sum%2){
        cout << 0 << endl;
        return 0;
    }

    ll effective_sum = total_sum/2;

    vector<ll> number_space(n);
    for(ll i=0;i<n;i++){
        number_space[i] = i+1;
    }

    vector<vector<ll>> dp(2, vector<ll> (effective_sum+1, 0));
    dp[0][0] = 1;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=effective_sum;j++){
            dp[1][j] = dp[0][j];
            if(j>=number_space[i-1]){
                dp[1][j] = (dp[1][j]%mod + dp[0][j-number_space[i-1]]%mod)%mod;
            }
        }
        dp[0] = dp[1];
    }
    cout << dp[0][effective_sum]%mod << endl;
    return 0;
}

//   0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
// 0 1 0 0 0 0 0 0 0 0 0 0  0  0  0  0 
// 1 
// 2 
// 3
// 4
// 5
// 6
// 7