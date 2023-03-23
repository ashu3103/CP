#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;
    cin>>n;

    int p = 1;
    int ans = 0;
    int power = 0;
    while(n > power){
        power = pow(5, p++);
        ans+=(n/power);
    }
    cout << ans << endl;
    return 0;
}