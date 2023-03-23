#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    vector<ll> stick_len(n);
    vector<ll> sum(n+1, 0);

    for(ll i=0;i<n;i++){
        cin>>stick_len[i];
    }

    sort(stick_len.begin(), stick_len.end());
    for(ll i=0;i<n;i++){
        sum[i+1] = stick_len[i] + sum[i];
    }
    ll ans = 1e18;
    for(ll i=0;i<n;i++){
        ll part1 = (n-1-i)*stick_len[i];
        ll part2 = (i)*stick_len[i];
        ll part3 = sum[n] - sum[i+1];
        ll part4 = sum[i];
        ans = min(ans, (part3-part4-part1+part2));
    }

    cout << ans << endl;
    return 0;
}