#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll help(string s, int x, int y, int ind){

    if(ind >= s.size()){
        if(x==6 && y==0){
            return 0;
        }
        return -1;
    }

    if(x<0 || y<0 || x>=7 || y>=7){
        return -1;
    }

    if(s[ind] == '?') {
        ll u = help(s, x, y+1, ind+1);
        ll d = help(s, x, y-1, ind+1);
        ll r = help(s, x+1, y, ind+1);
        ll l = help(s, x-1, y, ind+1);

        u = (u<0?0:u+1);
        d = (d<0?0:d+1);
        r = (r<0?0:r+1);
        l = (r<0?0:l+1);

        if(u+d+r+l == 0){
            return -1;
        }
        return (u+d+r+l);

    }else if(s[ind] == 'U'){
        return help(s, x, y+1, ind+1);
    }else if(s[ind] == 'D'){
        return help(s, x, y-1, ind+1);
    }else if(s[ind] == 'R'){
        return help(s, x+1, y, ind+1);
    }else if(s[ind] == 'L'){
        return help(s, x-1, y, ind+1);
    }

    return -1;

}

int main(){
    string s;
    cin >> s;

    ll ans = help(s, 0, 0, 0);

    return 0;
}