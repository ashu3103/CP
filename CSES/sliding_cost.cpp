#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    ll n,k;
    cin>>n>>k;

    vector<ll> nums(n);

    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }

    if(k==1){
        for(ll i=0;i<n;i++){
            cout << 0 << " ";
        }
        cout << endl;
        return 0;
    }

    set<pair<ll, ll>> left;
    set<pair<ll, ll>> right;
    ll sum_left = 0;
    ll sum_right = 0;

    // initialize sets
    for(ll i=0;i<k;i++){
        right.insert({nums[i], i});
        sum_right+=nums[i];
    }
    for(ll i=0;i<=(k-1)/2;i++){
        auto pr = *right.begin();
        right.erase(right.begin());
        left.insert(pr);
        sum_right-=(pr.first);
        sum_left+=(pr.first);
    }
    cout << ((left.size()*((*left.rbegin()).first))-sum_left) + (sum_right - (right.size()*((*left.rbegin()).first))) << " ";
    for(ll i=k;i<n;i++){
        ll remove_ind = i-k;
        auto it = left.find({nums[remove_ind], remove_ind});
        if(it != left.end()){
            // its in left
            sum_left-=(it->first);
            left.erase(it);
            if(nums[i] < right.begin()->first){
                left.insert({nums[i], i});
                sum_left+=nums[i];
            }else{
                auto pr = *right.begin();
                sum_right-=(right.begin()->first);
                right.erase(right.begin());
                right.insert({nums[i], i});
                sum_right+=nums[i];
                left.insert(pr);
                sum_left+=(pr.first);
            }
        }else{
            // its in right
            it = right.find({nums[remove_ind], remove_ind});
            sum_right-=(it->first);
            right.erase(it);
            if(nums[i] >= prev(left.end())->first){
                right.insert({nums[i], i});
                sum_right+=nums[i];
            }else{
                auto pr = *(prev(left.end()));
                sum_left-=(prev(left.end())->first);
                left.erase(prev(left.end()));
                left.insert({nums[i], i});
                sum_left+=nums[i];
                right.insert(pr);
                sum_right+=(pr.first);
            }
        }

        cout << ((left.size()*((*left.rbegin()).first))-sum_left) + (sum_right - (right.size()*((*left.rbegin()).first))) << " ";
    }
    cout << endl;
    return 0;
}

/*

-    8 3
-    2 4 3 5 8 1 2 1

3 4 5 5 2 1 
3 4 5 5 2 2 

*/