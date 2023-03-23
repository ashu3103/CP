#include<bits/stdc++.h>
using namespace std;

int lowerSearch(vector<int>&A, int t){
        int s = 0;
        int e = A.size()-1;

        while(s<e){
            int mid = (s+e)/2;
            if(A[mid] == t){
                e = mid;
            }else if(A[mid] > t){
                e = mid-1;
            }else{
                s = mid+1;
            }   
        }

        if(e>=0 && A[e] == t){
            return e;
        }

        return -1;
    }

int upperSearch(vector<int>&A, int t){
    int s = 0;
    int e = A.size()-1;

    while(s<=e){
        int mid = (s+e)/2;
        if(A[mid] == t){
            s = mid+1;
        }else if(A[mid] > t){
            e = mid-1;
        }else{
            s = mid+1;
        }   
    }

    if(e>=0 && A[e] == t){
        return e;
    }

    return -1;
}

int main(){

    vector<int> A = {1};
    // cout << search(A) << endl;
    int n;
    cin>>n;
    cout << lowerSearch(A, n) << endl; 
    cout << upperSearch(A, n) << endl;
    return 0;
}