#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desired_size(n);
    vector<int> actual_size(m);
    for(int i=0;i<n;i++){
        cin >> desired_size[i];
    }
    for(int i=0;i<m;i++){
        cin >> actual_size[i];
    }

    sort(desired_size.begin(), desired_size.end());
    sort(actual_size.begin(), actual_size.end());

    int j = 0;
    int i=0;
    int count = 0;
    while(i<n && j<m){
        if(actual_size[j]<=(desired_size[i]+k) && actual_size[j]>=(desired_size[i]-k)){
            j++;
            i++;
            count++;
        }else if(desired_size[i]-k > actual_size[j]){
            j++;
        }else{
            i++;
        }
    }
    cout << count << endl;
    return 0;
}

// 10 10 10
// 20 21 31 35 39 41 49 74 86 90
// 4 7 14 24 24 60 82 82 85 95
