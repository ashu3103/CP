#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    if(k==1){
        for(int i=0;i<n;i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        return 0;
    }

    set<pair<int, int>> left;
    set<pair<int, int>> right;

    // initialize sets
    for(int i=0;i<k;i++){
        right.insert({nums[i], i});
    }
    for(int i=0;i<=(k-1)/2;i++){
        auto pr = *right.begin();
        right.erase(right.begin());
        left.insert(pr);
    }
    cout << (*left.rbegin()).first << " ";
    for(int i=k;i<n;i++){
        int remove_ind = i-k;
        auto it = left.find({nums[remove_ind], remove_ind});
        if(it != left.end()){
            // its in left
            left.erase(it);
            if(nums[i] < right.begin()->first){
                left.insert({nums[i], i});
            }else{
                auto pr = *right.begin();
                right.erase(right.begin());
                right.insert({nums[i], i});
                left.insert(pr);
            }
        }else{
            // its in right
            it = right.find({nums[remove_ind], remove_ind});
            right.erase(it);
            if(nums[i] >= prev(left.end())->first){
                right.insert({nums[i], i});
            }else{
                auto pr = *(prev(left.end()));
                left.erase(prev(left.end()));
                left.insert({nums[i], i});
                right.insert(pr);
            }
        }

        cout << (*left.rbegin()).first << " ";
    }
    cout << endl;
    return 0;
}

/*

-    8 3
-    2 4 3 5 8 1 2 1

3 4 5 5 2 1 
3 4 5 5 2 2 

*/