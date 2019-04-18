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

const int MAXN = 110;
const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;

int n;
int x[MAXN], y[MAXN];
char label[MAXN];

char at[MAXN][MAXN];

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    // ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  for(int tc = 1; scanf("%d", &n) == 1; ++tc) {
    if(n == 0) break;
    memset(at, 0, sizeof(at));
    for(int i = 0; i < n; ++i) {
      scanf(" %c %d %d", &label[i], &x[i], &y[i]);
      at[x[i]][y[i]] = label[i];
    }
    vector<string> ans;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(i == j || x[j] <= x[i] || y[i] <= y[j]) continue;
        if(at[x[j]][y[i]] && at[x[i]][y[j]]) {
          ans.push_back(string(1, label[i]) + string(1, at[x[j]][y[i]]) + string(1, label[j]) + string(1, at[x[i]][y[j]]));
        }
      }
    }
    sort(ans.begin(), ans.end());
    printf("Point set %d:", tc);
    if(ans.empty()) {
      printf(" No rectangles\n");
    } else {
      printf("\n");
      for(int i = 0; i < ans.size(); i += 10) {
        for(int j = 0; j < 10 && i+j < ans.size(); ++j)
          printf(" %s", ans[i+j].c_str());
        printf("\n");
      }
    }
  }

  return 0;
}