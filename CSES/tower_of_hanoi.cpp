#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> help(int n){
    // base condition
    if(n==1){
        return {{1, 3}};
    }
    // recursion equation
    vector<vector<int>> ans;
    vector<vector<int>> prev = help(n-1);
    if(n%2){
        vector<int> pos = {1, 3, 2};
        int curr_pos = 0;
        for(int i=0;i<prev.size();i++){
            ans.push_back({pos[curr_pos%3], pos[(curr_pos+1)%3]});
            ans.push_back(prev[i]);
            curr_pos++;
        }
        ans.push_back({pos[curr_pos%3], pos[(curr_pos+1)%3]});
    }else{
        vector<int> pos = {1, 2, 3};
        int curr_pos = 0;
        for(int i=0;i<prev.size();i++){
            ans.push_back({pos[curr_pos%3], pos[(curr_pos+1)%3]});
            ans.push_back(prev[i]);
            curr_pos++;
        }
        ans.push_back({pos[curr_pos%3], pos[(curr_pos+1)%3]});
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> A = help(n);
    cout << A.size() << endl;
    for(int i=0;i<A.size();i++){
        cout << A[i][0] << " " << A[i][1] << endl;
    }
    return 0;
}