#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    cin>>n;

    vector<ll> nums(n);
    map<ll, ll> M;

    ll cnt = 0;

    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(i==0){
            nums[i] = x;
        }else{
            nums[i] = nums[i-1] + x;
        }
        if((nums[i]%n+n)%n==0){
            cnt++;
        }
        if(M[(nums[i]%n + n)%n]){
            cnt+=M[(nums[i]%n + n)%n];
        }
        M[(nums[i]%n + n)%n]++;
    }

    cout << cnt << endl;

    return 0;
}

/*
4
5 -65 -67 -67

5 -60 -127 -194

sudo fdisk -l
 1870  sudo wipefs --all /dev/sda
 1871  sudo wipefs -af --all /dev/sda
 1872  sudo fdisk -l
 1873  df -h
 1874  clear
 1875  df -h
 1876  sudo umount /dev/sda
 1877  df -h
 1878  sudo mkfs.vfat -F 32 -n "DRIVE" /dev/sda

*/

