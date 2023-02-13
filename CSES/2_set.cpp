#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll sum_f(ll n){   
    return (n*(n+1))/2;
}

int main(){
    ll n;
    cin>>n;
    ll s = sum_f(n);
    if(s%2 == 0){
        cout << "YES" << endl;
        ll break_sum = s/2;
        vector<ll> set1;
        vector<ll> set2;
        ll flag = -1;
        for(ll i=n; i>0; i--){
            if(break_sum >= i){
                set1.push_back(i);
                break_sum-=i;
            }else{
                set2.push_back(i);
            }
        }

        cout << set1.size() << endl;
        for(ll i=0;i<set1.size();i++){
            cout << set1[i] << " ";
        }
        cout << endl;
        cout << set2.size() << endl;
        for(ll i=0;i<set2.size();i++){
            cout << set2[i] << " ";
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}