#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> wt(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    sort(wt.begin(), wt.end());

    int s=0;
    int e=n-1;
    int count = 0;
    while(s<=e){
        if(s==e){
            count++;
            break;
        }else if(wt[s]+wt[e] <= k){
            count++;
            s++;
            e--;
        }else{
            count++;
            e--;
        }
    }
    cout << count << endl;
    return 0;
}

// 4 10
// 2 3 7 9