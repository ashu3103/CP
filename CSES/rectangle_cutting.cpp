#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int helper(int l,int w, vector<vector<int>>&dp){
    if(l==w){
        return 0;
    }
    if(dp[l][w]!=-1) return dp[l][w];
    int ans = INT_MAX;
    for(int i=1;i<=l/2;i++){
        ans = min(ans, 1+helper(max(i,w),min(i,w),dp)+helper(max(l-i,w),min(l-i,w),dp));
    }
    for(int i=1;i<=w/2;i++){
        ans = min(ans, 1+helper(max(i,l),min(i,l),dp)+helper(max(w-i,l),min(w-i,l),dp));
    }
    return dp[l][w] = ans;
}

int main(){
    int l,w;
    cin>>l>>w;
    vector<vector<int>> dp(max(l,w)+1, vector<int> (max(l,w)+1,-1));
    cout << helper(max(l,w), min(l,w), dp) << endl;
    return 0;
}