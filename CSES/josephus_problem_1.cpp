#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    queue<int> st;

    for(int i=0;i<n;i++){
        st.push(i+1);
    }

    while(!st.empty()){
        int first = st.front();
        st.pop();
        st.push(first);
        int second = st.front();
        st.pop();
        cout << second << " ";
    }

    return 0;
}
