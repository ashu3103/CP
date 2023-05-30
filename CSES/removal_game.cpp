#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;


int main(){

    ll n;
    cin>>n;
    vector<ll> nums(n);
    ll sum = 0;
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(ll i=0;i<n;i++){
        cin>>nums[i];
        dp[i][i] = nums[i];
        sum+=nums[i];
    }

    for(ll i=n-1;i>=0;i--){
        for(ll j=i+1;j<n;j++){
            ll a = nums[i] - dp[i+1][j];
            ll b = nums[j] - dp[i][j-1];
            dp[i][j] = max(a,b);
        }
    }

    cout << (sum+dp[0][n-1])/2 << endl;

    return 0;
}