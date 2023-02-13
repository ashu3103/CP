#include <bits/stdc++.h>
using namespace std;
#define ll long long

static bool cmp(vector<int> &a,vector<int> &b)
{
    if(a[1] != b[1]){
       return a[1]<b[1];
    }
    return a[0]>b[0];
}

int setIntersection(vector<vector<int> > &A) 
{  
    sort(A.begin(),A.end(),cmp);
    for(int i=0;i<A.size();i++){
        cout << A[i][0] << " " << A[i][1] << endl;
    }
   int cnt = 2; 
   int n = A.size();
   pair<int,int> p;
   p.first = A[0][1]-1; p.second = A[0][1];
   for(int i = 1; i<n; i++){
      if(p.second < A[i][0]){
          cnt = cnt+2;
          p.second = A[i][1];
          p.first = p.second - 1;
      }
      else if(p.second == A[i][0]){
          cnt++;
          p.first = p.second;
          p.second = A[i][1];
      }
      else if(p.first < A[i][0]){
          cnt++;
         if(p.second == A[i][1]){
            p.first = p.second - 1;
         }
         else{
            p.first = p.second;
            p.second = A[i][1];
         }
      }
   }
   return cnt;
}


int main(int argc, char *argv[]){
    vector<vector<int>> A = {{1,3}, {1,4}, {2,5}, {3,5}};
    int ans = setIntersection(A);

    return 0;
}