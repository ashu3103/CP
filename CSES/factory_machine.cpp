#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isOk(vector<ll> &A, ll mid, ll k){
    ll work = 0;
    for(ll i=0;i<A.size();i++){
        if(A[i]<=mid){
            work += min(mid/A[i], (ll)1e9);
        }
    }
    if(work>=k){
        return true;
    }
    return false;
}

int main(){
    ll n,k;
    cin>>n>>k;

    vector<ll> time(n);
    for(int i=0;i<n;i++){
        cin >> time[i];
    }

    ll low = 0;
    ll high = k*(*max_element(time.begin(), time.end()));
    ll res = high;
    while(low<=high){
        ll mid = (low+high)/2;
        if(isOk(time, mid, k)){
            res = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << res << endl;
    return 0;
}