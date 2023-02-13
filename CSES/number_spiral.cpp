#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define debug(x) cout << #x << ": " << x << endl
#define _rep(i, l, r) for(int i = (l); i <= (r); i++)
#define _for(i, l, r) for(int i = (l); i < (r); i++)
#define _repd(i, l, r) for(int i = (l); i >= (r); i--)
#define _ford(i, l, r) for(int i = (l); i > (r); i--)
#define _repit(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define _forit(it, a) for(auto it = a.rbegin(); it != a.rend(); it++)

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        if(x==y){
            ll offset = (x-1)*(x-1);
            cout << (offset + x) << endl;
        }
        else if(x>y){
            ll offset = (x-1)*(x-1);
            if(offset%2){
                cout << (offset + (x-1) + (x-y)) + 1 << endl;
            }else{
                cout << (offset + y) << endl;
            }
        }else{
            ll offset = (y-1)*(y-1);
            if(offset%2){
                cout << (offset + x) << endl;
            }else{
                cout << (offset + (y-1) + (y-x)) + 1 << endl;
            }
        }
    }
    return 0;
}