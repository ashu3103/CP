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
    Question: You are given an array of n integers, and your task is to find two values 
    (at distinct positions) whose sum is x.

    Approach: 
    1) Sort the list and use two pointer (standard), one pointer at the start and the other at
    the end. Now, if the x is less than the current sum, move the trailing pointer and if sum is more, 
    move the starting pointer.
    Time Complexity: O(nlogn) + O(n)
    2) Iterate over the numbers and maintain a map, now check if target - curr_value is present in map
    print
*/

// TC: O(nlogn), SC: O(n)
void approach_2()
{
    int n, target;
    bool done = false;
    cin >> n >> target;
 
    vector<int> arr(n);
    map<int, int> M;
 
    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
 
    // solve
    for (int i=0;i<n;i++){
        if (M[target - arr[i]])
        {
            cout << M[target - arr[i]] << " " << i+1 << endl;
            done = true;
            break;
        }
        M[arr[i]] = i+1;
    }
 
    if (!done)
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

// Incomplete solution
void approach_1()
{
    int n, x;
    cin >> n >> x;

    vi list_of_numbers(n);
    fo(0, n) {
        cin >> list_of_numbers[i];
    }

    sortall(list_of_numbers);

    int start_ptr = 0, trail_ptr = n-1;
    while(start_ptr < trail_ptr) {
        if (list_of_numbers[start_ptr] + list_of_numbers[trail_ptr] == x) {
            cout << list_of_numbers[start_ptr] << " " << list_of_numbers[trail_ptr] << endl;
            return;
        }
        else if (list_of_numbers[start_ptr] + list_of_numbers[trail_ptr] > x)
        {
            trail_ptr--;
        }
        else
        {
            start_ptr++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    approach_2();
    return 0;
}