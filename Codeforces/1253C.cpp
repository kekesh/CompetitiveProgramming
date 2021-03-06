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

ll N, M;
ll dp[200005];

int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		cin >> N >> M;
		vector<ll> a(N);
		F0R(i, N) cin >> a[i];

		sort(a.begin(), a.end());
		ll sumsofar = 0;
		F0R(i, M) {
				if (i - 1 >= 0) dp[i] = dp[i - 1];
				dp[i] += a[i];
				sumsofar += a[i];
				cout << dp[i] << " ";
		}

		for (int i = M; i < N; i++) {
				sumsofar += a[i];
				dp[i] = dp[i - M] + sumsofar;
				cout << dp[i] << " ";
		}
		cout << endl;


}
