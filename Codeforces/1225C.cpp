#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

 
using namespace std;
 
typedef string str;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;

#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto &a : x)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"
 
const int MOD = 998244353; // 1000000007;  // 998244353
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		ll N, P;
		cin >> N >> P;
		// try 1...31

		for (int x = 1; x <= 31; x++) {
				ll num = N - P*x;
				if (num <= 0) break;
				if (__builtin_popcount(num) <= x && x <= num) {
						cout << x << endl;
						return 0;
				}
		}
		cout << -1 << endl;
		return 0;
}
