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

/*
   Question: There is a street of length x whose positions are numbered 0,1,...,x. 
   Initially there are no traffic lights, but n sets of traffic lights are added to the street 
   one after another.
   Your task is to calculate the length of the longest passage without traffic lights after each 
   addition.

   Approach: 
   1) Maintain a multiset for lengths and a set for positions, initialize the set with 0 and x
   Now, iterate each element one by one and insert in the respective poistion in the set, take the length
   that it cuts and remove that value from multiset with addition of new values.

   2) Start backwards, install all the street lights and find the max gap, now remove each light in
   backward fashion and go on finding the next max
*/



// O(nlogn)
// Verdict: TLE
void approach_1()
{
   int x , n;
   cin>>x>>n;
   set<int> position;
   multiset<int> length;
   //now putting the initial lengths in the position set
   position.insert(0);
   position.insert(x);
   //and now substitutinh the lengths difference into the length array
   length.insert(x - 0); 
   //scanning each value
   for(int i = 0; i<n; i++){
       int no;
       cin>>no;
       position.insert(no);
       //finding the iterator of the current element added
       auto it = position.find(no);
       //now using prev to fing the previous iterator
       //also finding the next value
       int previousVal = *prev(it);
       int nextVal = *next(it);
       //erasing the previous length by finding it
       length.erase(length.find(nextVal - previousVal));
       //inserting the new length we got
       length.insert(no - previousVal);
       length.insert(nextVal - no);
       //now printing out the biggest element of the set
       cout<<*length.rbegin()<<" ";
   }
}

// O(nlogn)
void approach_2()
{
   int x , n;
   cin>>x>>n;
   set<int> position;
   position.insert(0);
   position.insert(x);

   vi lights(n);
   fo(0, n)
   {
      cin >> lights[i];
      position.insert(lights[i]);
   }

   // find the max gap
   int prev_l = 0;
	int max_gap = 0;
   vi gaps(n);
	// Find the longest passage once all the streetlights are added
	for (int p : position) {
		max_gap = std::max(max_gap, p - prev_l);
		prev_l = p;
	}
   gaps[n-1] = max_gap;

   for (int i=n-1;i>0;i--){
      auto it = position.find(lights[i]);
      max_gap = max(max_gap, *(next(it)) - *(prev(it)));
      position.erase(it);
      gaps[i-1] = max_gap;
   }

   fo(0, n)
   {
      cout << gaps[i] << " ";
   }
   cout << endl;
}

int main()
{
   approach_2();
   return 0;
}