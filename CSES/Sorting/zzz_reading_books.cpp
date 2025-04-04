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
    Question: There are n books, and Kotivalo and Justiina are going to read them all. For each book, 
    you know the time it takes to read it.
    They both read each book from beginning to end, and they cannot read a book at the same time. 
    What is the minimum total time required?

    Approach: Sort the array and then calculate if sum of all the reading time except last book is greater
    than the last book, then the total time required is the sum of all the reading.
    Otherwise, the total time required is double the last book.
    Time complexity: O(nlogn)
    Space complexity: O(n)
    
*/


// wrong approach
void approach_1()
{
    int n;
    cin >> n;

    vector<ll> reading_time(n);
    fo(0, n) {
        cin >> reading_time[i];
    }
    sortall(reading_time);

    for (int i = 1; i < n; i++) { // make prefix sum array
        reading_time[i] += reading_time[i-1];
    }

    ll total_time = numeric_limits<ll>::max();

    for (int i = 0; i < n; i++) {
        total_time = min(total_time, max(reading_time[i], reading_time[n-1] - reading_time[i]));
    }

    cout << 2*total_time << endl;
}

void approach_2()
{
    int n;
    cin >> n;

    vector<ll> reading_time(n);
    fo(0, n) {
        cin >> reading_time[i];
    }
    sortall(reading_time);

    ll total_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += reading_time[i];
    }

    cout << max(total_time, 2*reading_time[n-1]) << endl;
}

int main()
{
    approach_2();
    return 0;   
}