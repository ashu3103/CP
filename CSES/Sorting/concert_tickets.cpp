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
typedef multiset<int> msi;
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
    Question: There are n concert tickets available, each with a certain price. Then, m 
    customers arrive, one after another.
    Each customer announces the maximum price they are willing to pay for a ticket, and 
    after this, they will get a ticket with the nearest possible price such that it does not 
    exceed the maximum price.
*/


/*
    Approach: Here we can use multiset to store the price of each ticket then as a demand arise
    we supply the ticket which is just less than the max demanded price in the ticket price list
    Time Complexity: O(nlogn)
*/

void approach_1 ()
{
    int n,m;
    cin >> n >> m;

    msi concert_tickets;
    fo (0, n) {
        int x;
        cin >> x;
        concert_tickets.insert(x);
    }

    vi customer_demand_price(m);
    fo (0, m) {
        cin >> customer_demand_price[i];
        auto it = concert_tickets.lower_bound(customer_demand_price[i]);
        if (it != concert_tickets.end() && *it == customer_demand_price[i])
        {
            pi(*it);
            concert_tickets.erase(it);
        } 
        else if (it != concert_tickets.begin())
        {
            pi(*prev(it));
            concert_tickets.erase(prev(it));
        }
        else
        {
            pi(-1);
        }
    }

    
}

int main(int argc, char* argv[])
{
    approach_1();
    return 0;
}