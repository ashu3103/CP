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
    int n;
    cin>>n;
    if(n==1){
        cout << 1 << endl;
    }
    else if(n<=3){
        cout << "NO SOLUTION" << endl;
    }else{
        for(int i=n;i>0;i--){
            if(i%2){
                cout << i << " ";
            }
        }
        for(int i=n;i>0;i--){
            if(i%2 == 0){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}