#include<bits/stdc++.h>
using namespace std;
#define ll long long


int comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}


int main(){

    int n;
    cin>>n;
    vector<pair<int, int>> timing(n);

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        timing[i] = {a, b};
    }

    sort(timing.begin(), timing.end(), comp);

    int ans = 1;
    int last = timing[0].second;
    for(int i=1;i<n;i++){
        if(timing[i].first >= last){
            ans++;
            last = timing[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}

// 3 5
// 5 8
// 4 9