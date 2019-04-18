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

const int MAXN = 1e5 + 100;
const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;

int p[MAXN];

int find_set(int x) { return p[x] = (x == p[x] ? x : find_set(p[x])); }
bool union_sets(int x, int y) {
  x = find_set(x); y = find_set(y);
  if(x == y) return false;
  p[y] = x;
  return true;
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    // ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  for(int u, v; scanf("%d %d", &u, &v) == 2; ) {
    iota(p, p+MAXN, 0);
    int ans = !union_sets(u, v);
    while(scanf("%d", &u) == 1) {
      if(u == -1) break;
      scanf("%d", &v);
      ans += !union_sets(u, v);
    }
    printf("%d\n", ans);
  }

  return 0;
}