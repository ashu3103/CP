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
    Question: You are given a playlist of a radio station since its establishment. 
    The playlist has a total of n songs.
    What is the longest sequence of successive songs where each song is unique?

    Approach: Maintain a map and iterate through the songs, now at any point if the current song is
    already on the map, we change the window of unique songs
    f.ex.
    1 2 1 3 2
    Iteration-1
    1 2 1 3 2
    ^
    Iteration-2
    1 2 1 3 2
    ^ ^
    Iteration-3
    1 2 1 3 2
      ^ ^
    Since 1 was already on map we take everything after the 1 (in map) as our new sequence and update the
    map
*/

void approach_1()
{
    int n;
    cin >> n;
    vi songs(n);
    fo(0,n) {
        cin >> songs[i];
    }

    map<int, int> song_playlist_pos;
    int s = 0;

    int max_sequence_length = 1;
    song_playlist_pos[songs[0]] = (0 + 1);
    fo(1, n) {
        if(song_playlist_pos[songs[i]]) {
            s = max(s, song_playlist_pos[songs[i]]);
        }
        max_sequence_length = max(max_sequence_length, (i - s + 1));
        song_playlist_pos[songs[i]] = i+1;
    }

    pi(max_sequence_length);
}

int main()
{
    approach_1();
    return 0;
}