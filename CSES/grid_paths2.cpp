#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

ll helper(vector<vector<char>> &grid, ll ind,ll jnd,ll &n, vector<vector<int>>&dp){
    if(ind==n-1 && jnd==n-1 && grid[ind][jnd]!='*'){
        return 1;
    }
    if(ind>=n || jnd>=n || grid[ind][jnd]=='*'){
        return 0;
    }
    if(dp[ind][jnd] != -1){
        return dp[ind][jnd];
    }

    return dp[ind][jnd] = (helper(grid, ind+1, jnd, n, dp)%mod + helper(grid, ind, jnd+1, n, dp)%mod)%mod;
}


int main(){

    ll n;
    cin>>n;

    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    cout << helper(grid, 0, 0, n, dp) << endl;

    return 0;
}