#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n, maxCost;
    cin>>n>>maxCost;

    vector<int> price(n);
    vector<int> no_of_pages(n);

    for(int i=0;i<n;i++){
        cin>>price[i];
    }

    for(int i=0;i<n;i++){
        cin>>no_of_pages[i];
    }

    vector<vector<int>> dp(2, vector<int>(maxCost+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=maxCost;j++){
            dp[1][j] = dp[0][j];
            if(j >= price[i-1]){
                dp[1][j] = max(dp[1][j], no_of_pages[i-1] + dp[0][j-price[i-1]]);
            }
        }
        dp[0] = dp[1];
    }

    cout << dp[1][maxCost] << endl;

    return 0;
}