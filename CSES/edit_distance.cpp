#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;

int helper(string &A, string &B, int i, int j, vector<vector<int>>&dp){
    if(i==A.size() && j==B.size()){
        return 0;
    }
    if(i>=A.size()){
        return B.size() - j;
    }
    if(j>=B.size()){
        return A.size() - i;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(A[i]==B[j]){
        return dp[i][j] = helper(A, B, i+1, j+1,dp);
    }
    return dp[i][j] = 1 + min(helper(A,B,i+1,j,dp), min(helper(A,B,i,j+1,dp), helper(A,B,i+1,j+1,dp)));
}

int main(){
    string n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n.size(), vector<int>(m.size(), -1));
    cout << helper(n,m,0,0,dp) << endl;
    return 0;
}