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

int n;
int x[MAXN], y[MAXN];

bool can(int* x, int* y, bool reversed) {
  if(reversed) {
    reverse(x, x+n);
    reverse(y, y+n);
  }
  int fr = -oo, to = oo;
  for(int i = 0; i < n; ++i) {
    int j = (i+1)%n;
    if(x[i] == x[j]) {
      if(y[i] < y[j]) {
        fr = max(fr, x[i]);
      } else {
        to = min(to, x[i]);
      }
    }
  }
  return fr <= to;
} 

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
    for(int i = 0; i < n; ++i) {
      scanf("%d %d", x+i, y+i);
    }
    printf("Floor #%d\n", tc);
    if(can(x, y, false) && can(y, x, true)) {
      printf("Surveillance is possible.\n");
    } else {
      printf("Surveillance is impossible.\n");
    }
    printf("\n");
  }

  return 0;
}