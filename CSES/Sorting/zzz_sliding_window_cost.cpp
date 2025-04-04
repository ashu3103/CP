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
    Question: You are given an array of n integers. Your task is to calculate for each window of 
    k elements, from left to right, the minimum total cost of making all elements equal.
    You can increase or decrease each element with cost x where x is the difference between the 
    new and the original value. The total cost is the sum of such costs.

    Approach: Similar to sliding window median, for each window the cost can be minimum if we try
    to make all the elements to the median of the window.
*/

int main() {

   int n,k;
   cin >> n >> k;

   vector<ll> nums(n);
   fo(0, n) {
       cin >> nums[i];
   }

   multiset<int> low;
   multiset<int> high;

   ll low_sum = 0;
   ll high_sum = 0;
   //initialize the sets
   for (int i=0;i<k;i++) {
       if (low.size() == high.size()) { // place in low
           auto it = high.begin();
           if (!high.empty() && nums[i] > *it) // replace first element of high
           {
               low.insert(*it);
               low_sum+=(*it);
               high.erase(it);
               high_sum-=(*it);
               high.insert(nums[i]);
               high_sum+=nums[i];
           } else {
               low.insert(nums[i]);
               low_sum+=nums[i];
           }
       } else { // place in high
           auto it = low.end();
           if (!low.empty() && nums[i] < *(--it)) {  // replace the last element of low
               high.insert(*it);
               high_sum+=(*it);
               low.erase(it);
               low_sum-=(*it);
               low.insert(nums[i]);
               low_sum+=nums[i];
           } else {
               high.insert(nums[i]);
               high_sum+=nums[i];
           }
       }
   }

   int prev_median = *(low.rbegin());
   cout << (1LL*prev_median*low.size() - low_sum) + (high_sum - 1LL*prev_median*high.size()) << " ";

   for (int i=k;i<n;i++) {
       if (nums[i-k] <= prev_median) { // remove from low and then insert in low
           low.erase(low.find(nums[i-k]));
           low_sum-=(nums[i-k]);
           auto it = high.begin();
           if (!high.empty() && nums[i] > *it) // replace first element of high
           {
               low.insert(*it);
               low_sum+=(*it);
               high.erase(it);
               high_sum-=(*it);
               high.insert(nums[i]);
               high_sum+=(nums[i]);
           } else {
               low.insert(nums[i]);
               low_sum+=(nums[i]);
           }
       } else {   // remove from high and then insert in high
           high.erase(high.find(nums[i-k]));
           high_sum-=(nums[i-k]);
           auto it = low.end();
           if (!low.empty() && nums[i] < *(--it)) {  // replace the last element of low
               high.insert(*it);
               high_sum+=(*it);
               low.erase(it);
               low_sum-=(*it);
               low.insert(nums[i]);
               low_sum+=(nums[i]);
           } else {
               high.insert(nums[i]);
               high_sum+=(nums[i]);
           }
       }
       prev_median = *(low.rbegin());
       cout << (1LL*prev_median*low.size() - low_sum) + (high_sum - 1LL*prev_median*high.size()) << " ";
   }

   cout << endl;
   return 0;
}