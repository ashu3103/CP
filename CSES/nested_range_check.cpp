#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

    vector<bool> contained(n, false);
    vector<bool> contains(n, false);

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

    int maxend = INT_MIN;
    for(int i=0;i<n;i++){
        // calculating contained
        if(intervals[i].right <= maxend){
            contained[intervals[i].index] = true;
        }
        maxend = max(maxend, intervals[i].right);
    }

    int minend = INT_MAX;

    for(int i=n-1;i>=0;i--){
        // calculating contains
        if(intervals[i].right >= minend){
            contains[intervals[i].index] = true;
        }
        minend = min(minend, intervals[i].right);
    }

    for(int i=0;i<n;i++){
        cout << contains[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << contained[i] << " ";
    }

    return 0;
}