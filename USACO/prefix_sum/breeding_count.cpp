#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <chrono>
#include <random>
#include <functional>
#include <limits>

using namespace std;

#define ll long long
#define gc getchar_unlocked
#define fo(init, n) for (int i = init; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define sz(x) (int)x.size()
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef set<int> si;
typedef map<int, int> mii;
typedef unordered_map<int, int> uii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
   uniform_int_distribution<int> uid(0, lim - 1);
   return uid(rang);
}
int mpow(int base, int exp);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

int mpow(int base, int exp)
{
   base %= mod;
   int result = 1;
   while (exp > 0)
   {
      if (exp & 1)
      result = ((ll)result * base) % mod;
      base = ((ll)base * base) % mod;
      exp >>= 1;
   }
   return result;
}

//Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=572

int main()
{
   int n, m;
   cin >> n >> m;
   vector<int> a(n);
   vector<int> id1(n, 0);
   vector<int> id2(n, 0);
   vector<int> id3(n, 0);
   for (int i = 0; i < n; i++)
   {
      int x;
      cin >> x;
      if(i==0)
      {
         if (x==1){
            id1[i]++;
         }else if (x==2){
            id2[i]++;
         }else{
            id3[i]++;
         }
      }
      else
      {
         if (x==1){
            id1[i] = id1[i-1]+1;
            id2[i] = id2[i-1];
            id3[i] = id3[i-1];
         }else if (x==2){
            id2[i] = id2[i-1]+1;
            id3[i] = id3[i-1];
            id1[i] = id1[i-1];
         }else{
            id3[i] = id3[i-1]+1;
            id1[i] = id1[i-1];
            id2[i] = id2[i-1];
         }
      }
   }

   for (int i=0;i<m;i++){
      int x, y;
      cin >> x >> y;
      cout << id1[y-1] - (x==1 ? 0 : id1[x-2]) <<  " " << id2[y-1] - (x==1 ? 0 : id2[x-2]) << " " << id3[y-1] - (x==1 ? 0 : id3[x-2]) << endl;
   }

   return 0;
}