#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    multiset<ll> set;

    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        auto it = set.upper_bound(x);
        if(it == set.end()){
            set.insert(x);
        }else{
            set.erase(it);
            set.insert(x);
        }
    }

    cout << set.size() << endl;

    return 0;
}
// 5
// 3 8 2 1 5