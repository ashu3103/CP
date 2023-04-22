#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;

    vector<ll> time(n);
    ll sum = 0;
    for(ll i=0;i<n;i++){
        cin>>time[i];
        sum += time[i];
    }

    sort(time.begin(), time.end());

    cout << max(sum, (ll)time[n-1]*2) << endl;

    return 0;
}