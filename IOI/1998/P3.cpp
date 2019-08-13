#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
const ll INF = 1e18;

void setIO() {
const int MX = 100001;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/* Code starts here. */

void init();
bool solve(int N, int C);

ll N, C;
vector<int> on;
vector<int> off;

int main() {
  setIO();
  cin >> N >> C;
  init();
  if (!solve(N, C)) {
    printf("IMPOSSIBLE\n");
  }

  return 0;
}

bool solve(int N, int C) {
  set<string> all;

  F0R(switch_one, 2) {
    F0R(switch_two, 2) {
      F0R(switch_three, 2) {
        F0R(switch_four, 2) {
          int parity = switch_one + switch_two + switch_three + switch_four;

          if (parity % 2 != C % 2 || parity > C) {
            continue;
          }

          bool flag = true;
          string ans = "";
          F0R(i, N) { ans += "1"; }

          F0R(i, N) {
            if (switch_one) {
              ans[i] = (ans[i] == '1') ? '0' : '1';
            }

            if (switch_two && (!(i & 1))) {
              ans[i] = (ans[i] == '1') ? '0' : '1';
            }

            if (switch_three && i & 1) {
              ans[i] = (ans[i] == '1') ? '0' : '1';
            }

            if (switch_four && i % 3 == 0) {
              ans[i] = (ans[i] == '1') ? '0' : '1';
            }
          }

          for (int i = 0; i < on.size(); i++) {
            if (ans[on.at(i) - 1] != '1') {
              flag = false;
            }
          }

          for (int i = 0; i < off.size(); i++) {
            if (ans[off.at(i) - 1] != '0') {
              flag = false;
            }
          }

          if (flag) {
            all.insert(ans);
          }
        }
      }
    }
  }

  if (all.size() > 0) {  
    set<string>::iterator itr;
    for (itr = all.begin(); itr != all.end(); itr++) {
      cout << *itr << endl;
    }
    return true;
  }

  return false;
}

void init() {
  int x = 0;
  while (x != -1) {
    cin >> x;
    if (x != -1) {
      on.push_back(x);
    }
  }
  x = 0;
  while (x != -1) {
    cin >> x;
    if (x != -1) {
      off.push_back(x);
    }
  }
} 
