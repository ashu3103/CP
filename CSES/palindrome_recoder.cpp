#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    string s;
    cin>>s;
    map<char, int> M;
    for(int i=0;i<s.size();i++){
        M[s[i]]++;
    }
    int odd = 0;
    char odd_c = '@';
    for(auto i: M){
        if(i.second % 2){
            odd++;
            odd_c = i.first;
        }
    }
    if(odd>1){
        cout << "NO SOLUTION" << endl;
    }else{
        string ans = "";
        if(odd_c != '@'){
            M[odd_c]--;
            ans = ans + odd_c;
        }
        // string ans = to_string(odd_c);
        for(auto i: M){
            int freq = i.second;
            while(freq){
                ans = i.first + ans + i.first;
                freq-=2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}