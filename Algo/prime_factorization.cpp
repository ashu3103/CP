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

    int num;
    cin >> num;
    set<int> prime_factors;

    while(num > 1){
        int factor = hi[num];
        while(num%factor == 0){
            num /= factor;
            prime_factors.insert(factor);
        }
    }

    for(auto i: prime_factors){
        cout << i << " ";
    }

    cout << "\n";
    return 0;
}