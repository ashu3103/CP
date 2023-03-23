#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> isPrime(N, 1);
// Time Complexity :- O(n * sqrt(n))

int main(){
    int n;
    cin>>n;

    vector<vector<int>> divisors(n+1);

    for(int i=2;i<=n;i++){
        for(int j=i; j<=n;j+=i){
            divisors[j].push_back(i);
        }

    }

    

    return 0;
}