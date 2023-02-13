#include<bits/stdc++.h>
using namespace std;
#define ll long long

int MOD = 1e9+7;

int main(){
    ll ans = 1;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ans = ((ans*2)%MOD);
    }
    cout << ans << endl;
    return 0;
}