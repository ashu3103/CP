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
    Question: There are n children who want to go to a Ferris wheel, and your task is to find 
    a gondola for each child.
    Each gondola may have one or two children in it, and in addition, the total weight in 
    a gondola may not exceed x. You know the weight of every child.
    What is the minimum number of gondolas needed for the children?
*/

/*
    Approach: sort the weights of all children and then use two pointers (one pointer at start
    and one at end), now check if cumalative weight of both the children comes within the allowed
    weight if yes allocate a gandola if not allocate a gandola to the child of larger weight
    among the two and move to next child from back

    Time complexity: O(nlogn) + O(n)
*/


void approach_1 ()
{
    int n, allowed_weight;
    cin >> n >> allowed_weight;

    vi children_weight(n);
    fo (0, n) {
        cin >> children_weight[i];
    }

    sortall(children_weight);
    int number_of_gandolas = 0;

    int st = 0, end = n-1;
    while(st <= end) {
        if (st == end) {
            st++;
            end--;
        }

        if (children_weight[st] +  children_weight[end] <= allowed_weight) {
            st++;
            end--;
        } else {
            end--;
        }
        number_of_gandolas++;
    }

    pi(number_of_gandolas);
}

int main(int argc, char* argv[])
{
    approach_1();
    return 0;
}