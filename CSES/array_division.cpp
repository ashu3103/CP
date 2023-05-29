#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Giving TLE           Time Complexity - O(n^2)

// ll help(vector<ll>&A,ll s, ll e, ll k){
//     ll n = A.size();

//     if(k==0){
//         return 0;
//     }

//     if(k==1){
//         return (A[e] - ((s-1)<0?0:A[s-1]));
//     }

//     ll ans = ll_MAX;
//     for(ll i=s;i<=e;i++){
//         ans = min(ans, max(A[i]-((s-1)<0?0:A[s-1]), help(A, i+1, min(e+1, n-1), k-1)));
//     }
//     return ans;
// }

// ll main(){

//     ll n,k;
//     cin>>n>>k;

//     vector<ll> nums(n);

//     for(ll i=0;i<n;i++){
//         ll x;
//         cin>>x;
//         if(i==0){
//             nums[i] = x;
//         }else{
//             nums[i] = nums[i-1] + x;
//         }
//     }

//     cout << help(nums, 0, n-k, k) << endl;

//     return 0;
// }

// Using binary search O(nlogn)

bool isOk(vector<ll>&A, ll mid, ll k){
    ll curr_sum = 0;   
    ll tmp_k = 1;
    ll n = A.size();
    for(ll i=0;i<n;i++){
        if(A[i]+curr_sum <= mid){
            curr_sum += A[i];
        }else{
            tmp_k++;
            curr_sum = A[i];
        }
    }

    if(tmp_k <= k) return true;

    return false;
}

int main(){

    ll n,k;
    cin>>n>>k;
    vector<ll> nums(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }

    ll s = *max_element(nums.begin(), nums.end());
    ll e = sum;

    ll res = e;
    while(s<=e){
        ll mid = (s+e)/2;
        if(isOk(nums, mid, k)){
            res = mid;
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    cout << res << endl;
    return 0;
}