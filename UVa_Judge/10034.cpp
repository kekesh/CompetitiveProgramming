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
typedef vector<int> vi;

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
const int INFTY = 2147483643;

// Start of code.

struct UnionFind {
  vector<int> parent;
  vector<int> rank;

  /* A constructor to instantiate the data structure. */
  UnionFind(int size) {
    parent.assign(size, 0);
    rank.assign(size, 0);

    /* Initially, we have N isolated vertices. */
    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }
  }

  /* findSet(u) returns the representative of the set that u belongs to. This method uses path compression so that subsequent calls are sped up.*/
  int findSet(int u) {
    return (parent[u] == u) ? u : (parent[u] = findSet(parent[u]));
  }

  /* inSameSet(u, v) returns true iff u and v are in the same set. */
  bool inSameSet(int u, int v) {
    return findSet(u) == findSet(v);
  }

  /* unionSet(u, v) combines the sets that u and v belong to. This method is optimized with the union by rank heuristic. */
  void unionSet(int u, int v) {
    if (inSameSet(u, v)) return;

    int x = findSet(u), y = findSet(v);

    /* Always add the smaller tree to the larger tree. */
    if (rank[x] > rank[y]) {
      parent[y] = x;
    } else {
      parent[x] = y;
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
 }
};


ll T, N;
double cost;

vector<pair<ld, pair<int, int>>> EdgeList;

void kruskal() {
	sort(EdgeList.begin(), EdgeList.end());

	UnionFind uf(N);
	cost = 0;
	F0R(i, EdgeList.size()) {
		int u = EdgeList[i].second.first;
		int v = EdgeList[i].second.second;

		if (!uf.inSameSet(u, v)) {
			cost += EdgeList[i].first;
			uf.unionSet(u, v);
		}
	}
}

double d(double x1, double y1, double x2, double y2) {
	double d1 = abs(x2 - x1);
	double d2 = abs(y2 - y1);

	return sqrt(d1*d1 + d2*d2);
}

int main() {
	bool fst = true;
	cin >> T;
	while (T--) {
		if (!fst) cout << endl;
		EdgeList.clear();

		fst = false;
		cin >> N;

		vector<pair<double, double>> points;

		F0R(i, N) {
			double x, y;
			cin >> x >> y;
			points.pb(mp(x, y));
		}

		F0R(i, N) {
			FOR(j, i + 1, N) {
				double w = d(points[i].f, points[i].s, points[j].f, points[j].s);
				EdgeList.pb(mp(w, mp(i, j)));
			}
		}

		kruskal();

		printf("%.2f\n", cost);

	}

	return 0;
}
