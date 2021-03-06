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
 
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

class UnionFind {
		private:
				vector<int> parent, rank;

		public:
				UnionFind(int n) {
						parent.resize(n, 0);
						rank.resize(n, 0);
						for (int i = 0; i < n; ++i) parent[i] = i;
				}

				int findSet(int u) {
						return (parent[u] == u ? u : parent[u] = findSet(parent[u]));
				}

				bool inSameSet(int u, int v) {
						return findSet(u) == findSet(v);
				}

				void unionSet(int u, int v) {
						int x = findSet(u), y = findSet(v);
						if (x == y) {
								return;
						}

						if (rank[x] > rank[y]) {
								parent[y] = x;
								return;
						}
						parent[x] = y;
						rank[y] += (rank[x] == rank[y]);
				}
};
ll binpow(ll a, ll b) {
		a %= MOD;
		ll res = 1;
		while (b) {
				if (b & 1) {
						res = (res * a) % MOD;
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
		ll n, m, k;
		cin >> n >> m >> k;
		UnionFind uf(n);
		ll can = n;
		for (int start = 0; start <= n - k; start++) {
				for (int front = start, back = start + k - 1; front < back; front++, back--) {
						if (!uf.inSameSet(front, back)) {
								uf.unionSet(front, back);
								can--;
						}
				}
		}
		ll ans = binpow(m, can);
		cout << ans << endl;
}
