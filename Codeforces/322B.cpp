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
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<ld> vld;
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
 
const int MOD = 998244353;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;


char grid[1001][1001];
ll dp[1001][1001][2];

ll modpow(ll a, ll b) {
		ll res = 1;
		a %= MOD;
		while (b) {
				if (b & 1) {
						res = (a * res) % MOD;
				}
				a = (a * a) % MOD;
				b >>= 1;
		}
		return res;
}

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);
		vl a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		ll ans = -INF;
		ll bd = MIN(a[0], 2);
		for (int taking = 0; taking <= bd; taking++) {
				ll candidate = taking + (a[0] - taking)/3 + (a[1] - taking)/3 + (a[2] - taking)/3;
				ans = MAX(candidate, ans);
		}
		cout << ans << endl;
}
