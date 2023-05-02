#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,a,b;

    cin>>n>>a>>b;
    vector<ll> nums(n+1);

    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }

    for(int i=1;i<=n;i++){
        nums[i]+=nums[i-1];
    }
    set<pair<ll, int>> R;

    for(int i=a;i<=b;i++){
        R.insert({nums[i], i});
    }

    ll maxsum = -1e18;
    for(int i=1;i<=n-a+1;i++){
        maxsum = max(maxsum, R.rbegin()->first - nums[i-1]);
        R.erase({nums[i+a-1], i+a-1});
        if(i+b <= n)
            R.insert({nums[i+b], i+b});
    }
    cout << maxsum << endl;
    return 0;
}