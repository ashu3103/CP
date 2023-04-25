#include<bits/stdc++.h>
using namespace std;
#define ll long long

int comp(pair<ll, ll> a, pair<ll, ll> b){
    if((a.first == b.first) && (a.second < b.second)) return 1;
    if(a.first < b.first) return 1;
    return -1;
}

int main(){
    ll n, k;
    cin>>n>>k;

    vector<pair<ll, ll>> nums(n);

    for(ll i=0;i<n;i++){
        cin>>nums[i].first;
        nums[i].second = i;
    }

    sort(nums.begin(), nums.end());

    bool isPoss = false;
    ll num1, num2, num3;
    for(ll i=0;i<n;i++){
        ll nu = nums[i].first;
        ll ptr1 = i+1;
        ll ptr2 = n-1;
        ll effective_sum = k - nu;
        while(ptr1<ptr2){
            if(nums[ptr1].first + nums[ptr2].first == effective_sum) {
                num1 = nums[i].second;
                num2 = nums[ptr1].second;
                num3 = nums[ptr2].second;
                isPoss = true;
                break;
            } else if(nums[ptr1].first + nums[ptr2].first > effective_sum) {
                ptr2--;
            } else {
                ptr1++;
            }
        }
        if(isPoss) break;
    }
    if(isPoss){
        cout << num1+1 << " " << num2+1 << " " << num3+1 << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

