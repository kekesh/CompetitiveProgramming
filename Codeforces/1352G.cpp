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
 
const int MOD = /* 998244353; */ 1000000007;
const ll INF = 1e18;
const ld PI = 4 * atan((ld)1);
const int INFTY = 1e7;

int main() {
		ios::sync_with_stdio(0);
		cin.tie(NULL);
		cout.tie(NULL);

		ll t;
		cin >> t;
		while (t--) {
				ll n;
				cin >> n;
				if (n <= 3) {
						cout << -1 << endl;
						continue;
				}

				deque<int> d = {3, 1, 4, 2};
				n -= 4;
				int next = 5;
				while (n--) {
						if (abs(d.front() - next) >= 2 && abs(d.front() - next) <= 4) {
								d.push_front(next++);
						} else {
								d.push_back(next++);
						}
				}

				for (int i = 0; i < (int) d.size(); i++) {
						cout << d[i] << " ";
				}
				cout << endl;
		}
}
