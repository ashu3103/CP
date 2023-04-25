#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> nums(n);
    map<int, int> M;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    for(int i=0;i<n;i++){
        int num = nums[i];
        auto it = M.lower_bound(num);
        if(it == M.begin()){
            cout << 0 << " ";
        }else{
            auto tmp = it;
            tmp--;
            cout << (*tmp).second+1 << " ";
        }
        M.erase(it, M.end());
        M[num] = i;
    }
    cout << "\n";
    return 0;
}