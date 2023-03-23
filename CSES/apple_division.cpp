#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll help(vector<ll> A, ll t, ll ind){
    if(ind>=A.size()){
        return t;
    }
    if(A[ind] <= t){
        return min(help(A, t-A[ind], ind+1), help(A, t, ind+1));
    }
    return help(A, t, ind+1);
}

int main(){
    ll n;
    cin>>n;
    vector<ll> A(n);
    ll sumation = 0;
    for(ll i=0;i<n;i++){
        cin >> A[i];
        sumation += A[i];
    }
    ll sumation_break = sumation/2;
    ll gap = help(A, sumation_break, 0);
    cout << sumation - 2*(sumation_break - gap) << endl;
    return 0;
}