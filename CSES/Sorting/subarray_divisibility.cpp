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
    Question: Given an array of n integers, your task is to count the number of subarrays where the 
    sum of values is divisible by n.

    Approach: We have to understand a simple concept that if x = y (mod n) then n | (x-y)
    Now, sum till xth index - sum till yth index = sum from yth to xth index and our requirement is that
    this sum must be divisible by n so if we compare this to above equation we can say that if 
    gcd(sum till xth index, n) = gcd(sum till yth index, n) then n | sum from yth index to xth index.
    So just maintain a map to track the gcd of prefix sum as we iterate through the array.
*/

void approach_1() {
    int n;
    cin >> n;
    vector<ll> nums(n);
    map<ll, ll> M;

    ll ans = 0;
    fo(0, n) {
        int x;
        cin >> x;
        if (i == 0) {
            nums[i] = x;
        } else {
            nums[i] = nums[i-1] + x;
        }

        int mod_val = (nums[i]%n) < 0 ? n + nums[i]%n : nums[i]%n;

        if (mod_val == 0) {
            ans++;
        }
        if (M[mod_val]) {
            ans+=M[mod_val];
        }

        M[mod_val]++;
    }

    cout << ans << endl;
}

int main() {
    approach_1();
    return 0;
}