#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> isPrime(N, 1);
vector<int> hi(N);
vector<int> lo(N, 0);
// Time Complexity :- O(n * sqrt(n))

int main(){
    int n;
    cin>>n;
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            hi[i] = lo[i] = i;
            for(int j = i*2; j<=n;j+=i){
                isPrime[j] = 0;
                hi[j] = i;
                if(lo[j]==0){
                    lo[j] = i;
                }
            }
        }
    }

    cout << hi[18] << " " << lo[18] << endl;

    return 0;
}