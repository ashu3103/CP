#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;
    vector<ll> songs(n);
    for(ll i=0;i<n;i++){
        cin >> songs[i];
    }

    map<ll, ll> M;
    ll i=0, j=0;
    ll ans = 0;
    while(j<n){
        if(M[songs[j]] == 0){
            M[songs[j]]++;
            j++;
        }else{
            ans = max(ans, j-i);
            while(i<j){
                if(M[songs[j]] != 0){
                    M[songs[i]]--;
                    i++;
                }else{
                    break;
                }
            }
        }
    }
    ans = max(ans, j-i);
    cout << ans << endl;
    return 0;
}

// 1 2 1 3 2 7 4 2