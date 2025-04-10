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

// Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=691

typedef struct action_count {
    ll hoof;
    ll paper;
    ll scissor;
    ll max_action;
} action_count;


// O(n) solution with one loop
int main()
{
    int n;
    cin >> n;

    vector<char> action(n);
    vector<action_count> start(n+1);

    // iterate forward
    for (int i=0;i<n;i++){
        cin >> action[i];
        if (action[i] == 'P') {
            start[i+1].paper = start[i].paper + 1;
            start[i+1].hoof = start[i].hoof;
            start[i+1].scissor = start[i].scissor;
        } else if (action[i] == 'H') {
            start[i+1].paper = start[i].paper;
            start[i+1].hoof = start[i].hoof + 1;
            start[i+1].scissor = start[i].scissor;
        } else {
            start[i+1].paper = start[i].paper;
            start[i+1].hoof = start[i].hoof;
            start[i+1].scissor = start[i].scissor + 1;
        }
        start[i].max_action = max(max(start[i].paper, start[i].scissor), start[i].hoof);
    }

    // iterate backwards
    // for (int i=n-1;i>=0;i--){
    //     if (action[i] == 'P') {
    //         end[i].paper = end[i+1].paper + 1;
    //         end[i].hoof = end[i+1].hoof;
    //         end[i].scissor = end[i+1].scissor;
    //     } else if (action[i] == 'H') {
    //         end[i].paper = end[i+1].paper;
    //         end[i].hoof = end[i+1].hoof + 1;
    //         end[i].scissor = end[i+1].scissor;
    //     } else {
    //         end[i].paper = end[i+1].paper;
    //         end[i].hoof = end[i+1].hoof;
    //         end[i].scissor = end[i+1].scissor + 1;
    //     }
    //     end[i].max_action = max(max(end[i].paper, end[i].scissor), end[i].hoof);
    // }

    ll max_wins = 0;
    for (int i=0;i<=n;i++) {
        ll after_wins = max({start[n].hoof - start[i].hoof, start[n].scissor - start[i].scissor, start[n].paper - start[i].paper});
        max_wins = max(max_wins, start[i].max_action + after_wins);
    }

    cout << max_wins << endl;
    return 0;
}