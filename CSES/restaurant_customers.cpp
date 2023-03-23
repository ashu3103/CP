#include<bits/stdc++.h>
using namespace std;
#define ll long long

int comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    int n;
    cin>>n;
    // vector<pair<int, int>> timings(n);
    map<int, int> M;
    vector<int> arrival;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        // timings[i] = {a,b};
        M[b] = a;
        arrival.push_back(a);
        arrival.push_back(b);
    }

    // sort(timings.begin(), timings.end(), comp);
    sort(arrival.begin(), arrival.end());

    int ans = 0;
    int still_there = 0;
    for(int i=0;i<arrival.size();i++){
        if(M[arrival[i]]==0){
            still_there++;
        }else{
            still_there--;
            M[arrival[i]] = 0;
        }
        ans = max(still_there, ans);
    }


    cout << ans << endl;
    return 0;
}

// 2 3 5
// 4 9 8