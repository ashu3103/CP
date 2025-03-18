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
void ipgraph(int n, int m);
void dfs(int u, int par);

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

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}


/*
 Question: You are given a list of n integers, and your task is to calculate the 
 number of distinct values in the list.
*/


/*
  Approach: I can think of two solutions for this problem
  1) Sort all the elements of the array and then use two pointers to eliminate the duplicates.
  The time complexity of this approach is O(nlogn) while space complexity is O(1)

  2) Make a frequency map of all the elements while iterating through the list, if an element is
  already present (map[ele] != 0), then we say that its a duplicate (ignore the element and continue)
  Finally we will return the length of the frequency map.
  The time complexity is O(n) while the space complexity is O(n) in worst case.
*/

// TC:O(nlogn)
void approach_1 ()
{
    int n;
    cin >> n;
    vi list(n);
    fo(0, n) {
        cin >> list[i];
    }
    
    sortall(list);
    int distinct_count = 1;

    // Apply two pointers
    int left = 0;
    fo(1, n) {
        if (list[left] != list[i])
        {
            left = i;
            distinct_count++;
        }
    }

    pi(distinct_count);
}

// TC:O(n)
void approach_2 ()
{
    int n;
    cin >> n;
    vi list(n);
    fo(0, n) {
        cin >> list[i];
    }

    mii frequency_table;
    fo(0, n) {
        frequency_table[list[i]]++;
    }

    pi(sz(frequency_table));
}

int main(int argc, char *argv[])
{
    approach_2();
    return 0;
}