#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll q;
    cin>>q;
    vector<ll> powers(19, 1);
    for(int i=1;i<19;i++){
        powers[i] = powers[i-1] * 10;
    }
    while(q--){
        ll n;
        cin>>n;

        ll numDig = 0;
        ll digits = 0;
        ll prevDig = 0;

        for(int i=1;i,19;i++){
            digits += (powers[i] - powers[i-1])*i;
            if(digits >= n){
                numDig = i;
                break;
            }
            prevDig = digits;
        }
        ll low = powers[numDig - 1];
        ll high = powers[numDig] - 1;
        ll ans = 0;
        ll startPos = 0;
        while(low <= high){
            ll mid = (low + high)/2;
            ll startpos = (mid - powers[numDig-1])*numDig + prevDig + 1;
            if(startpos <= n ){
                if(mid > ans){
                    ans = mid;
                    startPos = startpos;
                }
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        string number = to_string(ans);
        cout << number[n - startPos] << endl;
    }
    return 0;
}