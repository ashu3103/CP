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
    Question: A factory has n machines which can be used to make products. Your goal is to make a 
    total of t products.
    For each machine, you know the number of seconds it needs to make a single product. 
    The machines can work simultaneously, and you can freely decide their schedule.
    What is the shortest time needed to make t products?

    Approach: Binary Search, Observation: The higher bound is the toatl time required to make desired number
    of products when only 1 machine (with lowest time) is present
*/

ll count_number_of_products(ll time, vector<int>&arr) {
    ll prods = 0;
    fo (0, arr.size()) {
        prods += (time/arr[i]);
    }
    return prods;
}

void approach_1()
{
    int n, number_of_products;
    cin >> n >> number_of_products;
    vi machine_times(n);
    fo (0, n) {
        cin >> machine_times[i];
    }

    ll s = 0, e = 1LL*number_of_products*(*max_element(machine_times.begin(), machine_times.end()));
    ll total_time = e;
    while(s<=e) {
        total_time = s + (e-s)/2;
        ll prods = count_number_of_products(total_time, machine_times);
        if (prods >= number_of_products){
            total_time = e;
            e = total_time - 1;
        }
        else {
            s = total_time + 1;
        }
    }

    cout << total_time << endl;
}

int main()
{
    approach_1();
    return 0;
}