#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Solved using ordered set

struct range{
    int left;
    int right;
    int index;

    bool operator < (struct range &other){
        if(left==other.left){
            return right > other.right;
        }
        return left < other.left;
    }
};

int main(){
    int n;
    cin>>n;
    vector<range> intervals(n);

    vector<int> contained(n, 0);
    vector<int> contains(n, 0);
    set<int> set;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        struct range x;
        x.left = s;
        x.right = e;
        x.index = i;
        intervals[i] = x;
    }   

    sort(intervals.begin(), intervals.end());

    // int maxend = INT_MIN;
    set.insert(INT_MIN);

    for(int i=0;i<n;i++){
        auto it = set.lower_bound(intervals[i].right);
        if(it!=set.end() && set.size()>1){
            contained[intervals[i].index]++;
        }
        // maxend = max(maxend, intervals[i].right);
        set.insert(intervals[i].right);
    }

    set.clear();

    set.insert(INT_MAX);

    for(int i=n-1;i>=0;i--){
        auto it = set.upper_bound(intervals[i].right);
        // 
    }

    for(int i=0;i<n;i++){
        cout << contained[i] << " ";
    }
    cout << "\n";

    return 0;
}