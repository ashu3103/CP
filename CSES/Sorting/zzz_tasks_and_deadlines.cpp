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
    Question: You have to process n tasks. Each task has a duration and a deadline, and you will process the tasks in some order one after another. 
    Your reward for a task is d-f where d is its deadline and f is your finishing time. (The starting time is 0, and you have to process all tasks even if a task would yield negative reward.)
    What is your maximum reward if you act optimally?

    Approach: We have to observe one thing
    since we have to find sum of (d-f) of all the tasks, we can say that we have to minimize f or maximize d
    but because the summation of d is always constant we have to somehow reduce the effrcts of f.
    Now f is simply (summation of duration of previous tasks + duration of current task) so we can say that we have to minimize the summation of duration of previous tasks
    so we can sort the tasks in decreasing order of their duration and then we can simply add the 
    duration of the tasks to the previous duration and then we can find the sum of (d-f) of all the 
    tasks.
*/


void approach_1()
{
    int n;
    cin >> n;

    vpii tasks(n);
    fo(0, n) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    sortall(tasks);
    ll ans = 0;
    ll prev = 0;
    fo(0, n) {
        prev += tasks[i].first;
        ans += tasks[i].second - prev;
    }
    cout << ans << endl;
}

int main()
{
    approach_1();
    return 0;
}