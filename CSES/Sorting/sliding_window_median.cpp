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
    Question: You are given an array of n integers. Your task is to calculate the median of 
    each window of k elements, from left to right.
    The median is the middle element when the elements are sorted. If the number of elements is 
    even, there are two possible medians and we assume that the median is the smaller of them.

    Approach: Maintain two multisets one lower and one higher, now place the elements in two sets such that lower
    always contain all the small values of the window and higher contains all the higher values, also at any
    time the size of lower >= size of higher.
    Do this and the answer will be max(all elements in loweer set)
*/

int main(){
    int n,k;
    cin >> n >> k;

    vector<ll> nums(n);
    fo(0, n) {
        cin >> nums[i];
    }

    multiset<int> low;
    multiset<int> high;

    //initialize the sets
    for (int i=0;i<k;i++) {
        if (low.size() == high.size()) { // place in low
            auto it = high.begin();
            if (!high.empty() && nums[i] > *it) // replace first element of high
            {
                low.insert(*it);
                high.erase(it);
                high.insert(nums[i]);
            } else {
                low.insert(nums[i]);
            }
        } else { // place in high
            auto it = low.end();
            if (!low.empty() && nums[i] < *(--it)) {  // replace the last element of low
                high.insert(*it);
                low.erase(it);
                low.insert(nums[i]);
            } else {
                high.insert(nums[i]);
            }
        }
    }

    int prev_median = *(low.rbegin());
    cout << prev_median << " ";

    for (int i=k;i<n;i++) {
        if (nums[i-k] <= prev_median) { // remove from low and then insert in low
            low.erase(low.find(nums[i-k]));
            auto it = high.begin();
            if (!high.empty() && nums[i] > *it) // replace first element of high
            {
                low.insert(*it);
                high.erase(it);
                high.insert(nums[i]);
            } else {
                low.insert(nums[i]);
            }
        } else {   // remove from high and then insert in high
            high.erase(high.find(nums[i-k]));
            auto it = low.end();
            if (!low.empty() && nums[i] < *(--it)) {  // replace the last element of low
                high.insert(*it);
                low.erase(it);
                low.insert(nums[i]);
            } else {
                high.insert(nums[i]);
            }
        }
        prev_median = *(low.rbegin());
        cout << prev_median << " ";
    }

    cout << endl;
    return 0;
}