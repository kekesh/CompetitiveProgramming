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
const ld PI = 4 * atan((ld)1);

ll N;

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N;
		vector<pi> A(N);
		F0R(i, N) cin >> A[i].f >> A[i].s;

		int ans = 1;
		if (N > 1) ans++;

		for (int i = 1; i < N - 1; i++) {
				int left = A[i - 1].f;
				int right = A[i + 1].f;

				// drop to left
				if (A[i].f - A[i].s > left) {
						ans++;
				} else if (A[i].f + A[i].s < right) {
						// drop tree i to the right.
						ans++;
						A[i].f = A[i].f + A[i].s;
				}
		}
		cout << ans << endl;
}
