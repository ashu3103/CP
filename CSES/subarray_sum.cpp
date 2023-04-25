#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n, k;
    cin>>n>>k;

    vector<ll> nums(n);
    map<ll, ll> M;

    ll cnt = 0;

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(i==0){
            nums[i] = x;
        }else{
            nums[i] = nums[i-1] + x;
        }
        if(nums[i] == k){
            cnt++;
        }
        if(M[nums[i] - k]){
            cnt += M[nums[i] - k];
        }
        M[nums[i]]++;
    }

    cout << cnt << endl;
    return 0;
}