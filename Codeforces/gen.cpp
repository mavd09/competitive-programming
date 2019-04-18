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

int main() {
  #ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("input.txt", "w", stdout);
  #else
    // ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  int n = 1000;

  cout << n << endl;

  for(int i = 0; i < n; ++i) {
    int x = 1e6-i;
    cout << x << ' ' << 0 << endl;
  }

  for(int i = 0; i < n; ++i) {
    int x = 2e6-i;
    cout << x << ' ' << 0 << endl;
  }

  return 0;
}