#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
  #define dbg(args...) { err("[dbg] ", args); }
#else
  #define dbg(args...)
#endif

void err() { cerr << endl; }
template<typename T, typename... Args>
void err(T a, Args... args) { cerr << a; err(args...); }

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 50;
const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;

int n, r, k;

int tc;
int dp[2][2][MAXN][MAXN];

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    // ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  for(tc = 1; scanf("%d %d %d", &n, &r, &k) == 3; ) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][r] = 1;
    for(int x = 0; x < 2*n; ++x) {
      for(int y = 0; y < 2*n; ++y) {
        for(int dy = 0; dy < 2; ++dy) {
          for(int p = 0; p <= r; ++p) {
            int& cur = dp[x&1][dy][y][p];
            if(cur == 0) continue;
            dp[!(x&1)][1][y+1][p] += cur;
            bool is_peak = (y == k && dy == 1);
            if(y-1 >= 0 && p-is_peak >= 0)
              dp[!(x&1)][0][y-1][p-is_peak] += cur;
            cur = 0;
          }
        }
      }
    }
    printf("%d\n", dp[0][0][0][0]);
  }

  return 0;
}