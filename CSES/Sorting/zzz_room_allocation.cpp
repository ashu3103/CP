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
    Question: There is a large hotel, and n customers will arrive soon. Each customer wants to have a 
    single room.
    You know each customer's arrival and departure day. Two customers can stay in the same room if the 
    departure day of the first customer is earlier than the arrival day of the second customer.
    What is the minimum number of rooms that are needed to accommodate all customers? And how can 
    the rooms be allocated?

    Approach: Similar to restaurant_customer.cpp
*/

typedef struct tripair {
    int time;
    int idx;
    int type;
} tripair;

int comp_tripair(tripair a, tripair b) {
    if (a.time == b.time) return (a.type < b.type);
    return a.time < b.time;
}

void approach_1()
{
    int n;
    cin >> n;
    vector<tripair> timings(2*n);
    for (int i=0;i<n;i++) {
        int x, y;   
        cin >> x >> y;
        timings[2*i] = {x, i, 0};
        timings[2*i + 1] = {y, i, 1};
    }

    sort(timings.begin(), timings.end(), comp_tripair);

    int current_rooms = 0;
    vi room(n); queue<int> free_rooms;
    for (int i=0;i<2*n;i++) {
        if (timings[i].type == 0) {
            if (!free_rooms.empty()) {
                room[timings[i].idx] = free_rooms.front();
                free_rooms.pop();
            } else {
                current_rooms++;
                room[timings[i].idx] = current_rooms;
            }
        } else {
            free_rooms.push(room[timings[i].idx]);
        }
    }
    pi(current_rooms);
    fo(0, n) {
        cout << room[i] << " ";
    }
}

int main(){
    approach_1();
    return 0;
}