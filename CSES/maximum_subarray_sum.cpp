#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long> A(n);
    for(long long i=0;i<n;i++){
        cin>>A[i];
    }

    if(n==1){
        cout << A[0] << endl;
        return 0;
    }
    vector<long long> dp(n, 0);

    if(A[0] < 0){
        dp[0] = 0;
    }else{
        dp[0] = A[0];
    }
    long long ans = dp[0];
    long long num_neg = 0;
    long long neg_max = -1*(1e18);
    for(long long i=1;i<n;i++){
        if(A[i] >= 0){
            dp[i] = dp[i-1] + A[i];
        }else{
            num_neg++;
            neg_max = max(neg_max, A[i]);
            if(dp[i-1]+A[i] > 0){
                dp[i] = dp[i-1]+A[i];
            }else{
                dp[i] = 0;
            }
            // dp[i] = max(dp[i-1]+A[i], 0);
        }
        ans = max(ans, dp[i]);
    }
    if(num_neg == n-1){
        cout << neg_max << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}