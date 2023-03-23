#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct range{
    int left;
    int right;
    int index;
    int room = 0;
    bool operator < (const range &other) {
        if(left == other.left){
            right < other.right;
        }
        return left < other.left;
    }

};


int main(){
    int n;
    cin >> n;
    vector<range> time(n);
    set<pair<int, int>> S;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        time[i].left = a;
        time[i].right = b;
        time[i].index = i;
    }

    sort(time.begin(), time.end());

    int maxRoom = INT_MIN;
    // int room = 1;

    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int arrival = time[i].left;
        if(arrival > (*S.begin()).first){
            int room_empty = (*S.begin()).second;
            if(room_empty == 0){
                S.insert({time[i].right, 1});
                ans[time[i].index] = 1;
            }else{
                S.erase(S.begin());
                S.insert({time[i].right, room_empty});
                ans[time[i].index] = room_empty;
            }
        }else{
            S.insert({time[i].right, S.size()+1});
            ans[time[i].index] = S.size();
        }
        int sz = S.size();
        maxRoom = max(maxRoom, sz);
    }
    cout << maxRoom << endl;
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}