#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    
    vector<int> A = {1,1,1,1,1,2,2,2,2,2,2,5,5,6,6,6,6,6,6,7,7,8,8,8,9,9,9,10,10,10};
    int B = 4;

    int n = A.size();
    vector<int> ans = {-1,-1};

    auto ind1 = lower_bound(A.begin(), A.end(), B);
    cout << ind1 - A.begin() << endl;
    if(*ind1 == B){
        ans[0] = ind1 - A.begin();
    }
    
    auto ind2 = upper_bound(A.begin(), A.end(), B);
    cout << ind2 - A.begin() << endl;
    if(ind2 != A.begin()){
        ind2--;
        if(*ind2 == B){
            ans[1] = ind2 - A.begin();
        }
    }
    
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}