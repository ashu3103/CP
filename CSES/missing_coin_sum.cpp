#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n;
    cin>>n;
    vector<ll> coins(n);
    for(ll i=0;i<n;i++){
        cin>>coins[i];
    }

    sort(coins.begin(), coins.end());

    ll ans = 1;

    for(ll i=0;i<n;i++){
        if(ans < coins[i]){
            break;
        }else{
            ans+=coins[i];
        }
    }

    cout << ans << endl;

    return 0;
}