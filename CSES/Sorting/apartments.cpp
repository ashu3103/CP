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
    Question: There are n applicants and m free apartments. Your task is to distribute the 
    apartments so that as many applicants as possible will get an apartment.
    Each applicant has a desired apartment size, and they will accept any apartment whose 
    size is close enough to the desired size.
*/

/*
    Approach: 
    1) Sort both the apartment size and person requirement, now while iterating the 
    person requirement list check the lower bound of apartment size for {his requirement} - k
    if such apartment is found check the other condition and allot it to that person.
    Time Complexity: O(nlogn) + O(mlogm) + O(mlogn)

    2) Sort both the apartment size and person requirement, now use two pointers to check 
    the eligibility of a person one by one, if the requirement is satisfied move to next person
    apartment, if requirement is greater than apartment size move to next apartment, else move
    to next person
*/

void approach_1 ()
{
    int n, m, k;
    cin >> n >> m >> k;
    msi apartment_size;
    fo(0, n) {
        int sz;
        cin >> sz;
        apartment_size.insert(sz);
    }
    
    vi person_requirement(m);
    fo (0, m) {
        cin >> person_requirement[i];
    }

    sortall(person_requirement);

    int number_of_allotments = 0;

    fo(0, m) {
        auto it = apartment_size.lower_bound(person_requirement[i] - k);
        // remove if satisfy both conditions
        if (it != apartment_size.end() && *it <= (person_requirement[i] + k))
        {
            number_of_allotments++;
            apartment_size.erase(it);
        }
    }

    pi(number_of_allotments);
}

void approach_2_yt ()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi apartment_size(n);
    fo(0, n) {
        cin >> apartment_size[i];
    }
    
    vi person_requirement(m);
    fo (0, m) {
        cin >> person_requirement[i];
    }

    sortall(apartment_size);
    sortall(person_requirement);

    int number_of_allotments = 0;

    // Use two pointers
    int apartment_ptr = 0, requirement_ptr = 0;
    while (apartment_ptr < n && requirement_ptr < m)
    {
        if (person_requirement[requirement_ptr]+k >= apartment_size[apartment_ptr] && person_requirement[requirement_ptr] <= apartment_size[apartment_ptr])
        {
            apartment_ptr++;
            requirement_ptr++;
            number_of_allotments++;
        }
        else if(person_requirement[requirement_ptr]-k > apartment_size[apartment_ptr])
        {
            apartment_ptr++;
        }
        else
        {
            requirement_ptr++;
        }
    }

    pi(number_of_allotments);
}

int main(int argc, char *argv[])
{
    approach_2_yt();
    return 0;
}