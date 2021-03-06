#include <assert.h>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <cctype>
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

bool check(string st) {

	F0R(i, st.size()/2) {
		if (st[i] != st[st.size() - i - 1]) return false;
	}

	return true;

}


int main() {
	string st;

	while (getline(cin, st), st != "DONE") {

		string s = "";
		for (auto &elem : st) {
			if (elem == '!' || elem == '.' || elem == ',' || elem == '?' || elem == ' ') {
				// do nothing
			} else if (isalpha(elem)) {
				s += tolower(elem);
			}
		}
		if (check(s)) {
			cout << "You won't be eaten!" << endl;
		} else {
			cout << "Uh oh.." << endl;
		}
	}
	return 0;
}
