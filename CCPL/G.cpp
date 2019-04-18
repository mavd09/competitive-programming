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
const ll MOD = 10000000000000007LL;
const lf EPS = 1e-9;

ll add(ll a, ll b) { return (a+b) % MOD; }

ll mul(ll a, ll b) {
  a %= MOD; b %= MOD;
  ll r = 0;
  while(b) {
    if(b&1) r = add(r, a);
    a = add(a, a);
    b >>= 1;
  }
  return r;
}

ll fpow(ll b, ll e) {
  ll r = 1;
  while(e) {
    if(e&1) r = mul(r, b);
    b = mul(b, b);
    e >>= 1;
  }
  return r;
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    // ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  int n_test; scanf("%d", &n_test);

  while(n_test--) {
    ll r, c; scanf("%lld %lld", &r, &c);
    ll t = r*c;
    ll a = t / 2 + (t&1), b = t / 2;
    printf("%lld\n", mul(fpow(a, b-1), fpow(b, a-1)));
  }

  return 0;
}