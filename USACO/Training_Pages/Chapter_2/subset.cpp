/*
  ID: ekfrmd1
  LANG: C++11
  TASK: subset
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
ll solve(ll sum, ll start, ll end);

ifstream fin("subset.in");
ofstream fout("subset.out");

ll N;
ll target;
ll nums[41];

// dp[i][j] represents state at ith sum and jth start. max sum is 39*40/2 = 780.
ll dp[800][41];

inline void init() { fin >> N; }

int main() {
  setIO();
  init();
  if (((N * (N + 1)) / 2) & 1) {
    fout << "0" << endl;
    exit(0);
  }
  target = N * (N + 1) / 4;
  FOR(i, 1, N + 1) { nums[i - 1] = i; }
  memset(dp, -1, sizeof(dp));
  fout << solve(0, 0, N) << endl;
  return 0;
}

ll solve(ll sum, ll start, ll end) {
  if (start >= end) {
    return 0;
  }
  if (dp[sum][start] != -1) {
    return dp[sum][start];
  }

  if (sum == target) {
    return 1;
  }

  return dp[sum][start] = solve(sum, start + 1, end) +
                          solve(sum + nums[start], start + 1, end);
}

/* Fast I/O */
void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}
