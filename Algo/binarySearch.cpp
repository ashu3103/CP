#include<bits/stdc++.h>
using namespace std;

int binarySearch(int s, int e, vector<int>&A, int t){
    while(s<=e){
        int mid = (s+e)/2;

        if(A[mid] == t){
            return mid;
        }else if(A[mid] > t){   
            e = mid-1;
        }else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){

    int n, t;
    cin>>n>>t;
    vector<int> num(n);

    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    cout << binarySearch(0, n-1, num, t) << endl;
    return 0;
}