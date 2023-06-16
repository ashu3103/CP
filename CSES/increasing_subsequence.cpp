#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

// TC: O(n^2), SC: O(n)
void increasingSubsequenceMethod1(){
    ll n;
    cin>>n;
    vector<ll> nums(n);

    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }

    vector<ll> dp(n, 1);
    ll ans = 1;
    for(ll i=1;i<n;i++){
        for(ll j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

// TC: O(nlogn), SC: O(n) using binary search
void increasingSubsequenceMethod2(){
    ll n;
    cin>>n;
    vector<ll> nums(n);

    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }

    ll ptr = 0;
    for(ll i=1;i<n;i++){
        if(nums[i] > nums[ptr]){
            ptr++;
            nums[ptr] = nums[i];
        }else{
            auto it = lower_bound(nums.begin(), nums.begin()+ptr, nums[i]);
            nums[it - nums.begin()] = nums[i];
        }
    }
    
    cout << ptr+1 << endl;
}


int main(){
    increasingSubsequenceMethod2();
    return 0;
}

// 1 7 8 4 5 6 -1 9    
