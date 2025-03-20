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
    Question: In a movie festival n movies will be shown. You know the starting and ending time of 
    each movie. What is the maximum number of movies you can watch entirely?

    Approach: Sort the end time in asc order, while iterating, check if the end time of last watched movie
    is less than equal to start time of the current movie (watch it babe!)
 */

int sort_ending_comparator(pii a, pii b)
{
    if (b.S == a.S) return b.F >= a.F;
    return b.S >= a.S;
}

// O(nlog(n)), but TLE
void approach_1_impl_1 ()
{
    int n;
    cin >> n;

    vpii start_end_map(n);
    fo(0, n) {
        cin >> start_end_map[i].F >> start_end_map[i].S;
    }

    sort(start_end_map.begin(), start_end_map.end(), sort_ending_comparator);

    int last_movie_end_time = 0;
    int total_movie_watched = 0;
    fo (0, n)
    {
        if (start_end_map[i].F >= last_movie_end_time) {
            total_movie_watched++;
            last_movie_end_time = start_end_map[i].S;
        }
    }
    pi(total_movie_watched);
}

// O(nlogn)
void approach_1_impl_2 ()
{
    int n;
    cin>>n;
 
    multimap<int,int> M;
 
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        M.insert({b,a});
    }
    int cnt = 0;
    int prev = 0;
    for(auto m: M){
        if(m.second >= prev){
            cnt++;
            prev = m.first;
        }
    }
    cout << cnt << endl;
}

int main(int argc, char* argv[])
{
    approach_1_impl_2();
    return 0;
}