#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll combi(ll i, ll j){
    return (j-i+1);
}

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> nums(n);
    map<ll,ll> M;
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }
    ll i=0, j=0;
    ll cnt = 0;
    ll ans = 0;

    while(j<n){
        if(M[nums[j]] == 0){
            cnt++;
        }
        M[nums[j]]++;

        while(cnt>k && i<j){
            M[nums[i]]--;
            if(M[nums[i]]==0){
                cnt--;
            }
            i++;
        }

        ans+=combi(i, j);
        j++;
    }
    
    cout << ans << endl;
    return 0;
}

// 1 2 3 1 1