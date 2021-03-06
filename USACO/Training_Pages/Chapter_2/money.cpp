/*
  ID: ekfrmd1
  LANG: C++11
  TASK: money
*/

#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"

void setIO();
inline void init();
ll solve(ll target);

ifstream fin("money.in");
ofstream fout("money.out");

ll V, N;
ll dp[10005][26];
ll coins[26];

inline void init() {
  fin >> V >> N;
  F0R(i, V) { fin >> coins[i]; }
}

int main() {
  setIO();
  init();
  
  F0R(i, V + 1) {
    dp[0][i] = 1;
  }
  
  FOR(i, 1, N + 1) {
    FOR(j, 0, V + 1) {
      ll x = (j - 1 >= 0) ? dp[i][j - 1] : 0;
      ll y = (i - coins[j] >= 0) ? dp[i - coins[j]][j] : 0;
      dp[i][j] = x + y;
    }
  }
  
  fout << dp[N][V] << endl;
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}