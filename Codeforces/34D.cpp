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
typedef long double ld;
typedef complex<ld> cd;
typedef long long ll;

typedef pair<int, int> pi;
const ll INFTY = 10e8;

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

const int MOD = 1000000007;  // 998244353
const ll INF = 1e18;
const int MX = 35005;
const ld PI = 4 * atan((ld)1);

// Start of code.


int main() {
	ll N, r1, r2;
	vector<vector<ll>> AdjList(50005);
	cin >> N >> r1 >> r2;
	r1--;
	r2--;
	F0R(i, N) {
		if (r1 == i) continue;
		ll nxt;
		cin >> nxt;
		nxt--;
		AdjList[i].pb(nxt);
		AdjList[nxt].pb(i);
	}

	vector<int> predecessor(50005);
	vector<int> d(50005, INFTY);
	queue<int> q;
	q.push(r2);
	d[r2] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		F0R(i, AdjList[u].size()) {
			int v = AdjList[u][i];
			if (d[v] == INFTY) {
				predecessor[v] = u;
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	F0R(i, N) {
		if (i == r2) continue;
		cout << predecessor[i] + 1;
		if (i != N - 1) cout << " ";
	}
	cout << endl;

	return 0;
}
