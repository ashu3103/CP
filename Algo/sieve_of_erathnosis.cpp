#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> isPrime(N, 1);

// Time Complexity :- O(n * sqrt(n))

int main(){
    int n;
    cin>>n;
    isPrime[0] = isPrime[1] = 0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            for(int j = i*2; j<=n;j+=i){
                isPrime[j] = 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << "Number: " << i << " is " << (isPrime[i]?"prime":"not prime") << endl;
    }

    return 0;
}