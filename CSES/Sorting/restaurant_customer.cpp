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
    Question: You are given the arrival and leaving times of n customers in a restaurant.
    What was the maximum number of customers in the restaurant at any time?
*/


/*
    Approach: There can be many ways, one of these which I could think of:-
    1) Look at the restaurant as a closed system, whenever a customer arrives, the number in the
    restaurant increases and whenever a customer leaves the number decreases, as we are only
    concerned with the number we don't care who comes and goes out at what time, so we sort the 
    arrival and departure timeline of all the people -> add 1 if it is an arrive time (doesn't
    matter whose arrival) and subtract 1 if its a departure
    Time complexity: O(2nlog(2n))

    However you can try to bring down the complexity to O(nlogn) but it would require some
    memory (increase space complexity)
*/

void approach_1 ()
{
    int n;
    cin >> n;

    vpii timeline(2 * n);

    fo (0, n) {
        int x, y;
        cin >> x >> y;
        timeline[2*i] = make_pair(x, 0);
        timeline[2*i + 1] = make_pair(y, 1);
    }

    sortall(timeline);

    int max_customers = 0;
    int customers_at_point = 0;
    fo (0, 2*n) {
        if (timeline[i].S == 0) {
            customers_at_point++;
        } else {
            customers_at_point--;
        }

        max_customers = max(max_customers, customers_at_point);
    }

    pi(max_customers);
}

int main(int argc, char* argv[])
{
    approach_1();
    return 0;
}