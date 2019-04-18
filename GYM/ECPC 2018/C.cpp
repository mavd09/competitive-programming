#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

// mt19937 / mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
// uniform_int_distribution<T> / uniform_real_distribution<T> dis(fr, to);

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
  #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
  #define debug(...) 42
#endif

const int N = 2e3 + 100;
const ll oo = 1e17 + 100;

int seen[N][N];
ll dp[N][N];

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    freopen("transform.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  int n_test; cin >> n_test;
  for(int tc = 1; n_test--; ++tc) {
    debug("Testcase: ", tc);
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c(n);
    for(auto& e : a) cin >> e;
    for(auto& e : b) cin >> e;
    for(auto& e : c) cin >> e;
    vector<vector<bool>> left(n, vector<bool>(m+1, false));
    for(int i = 0; i < n; ++i) {
      bool found = false;
      for(int j = 0; j < m; ++j) {
        left[i][j] = !found;
        found |= (a[i] == b[j]);
      }
      left[i][m] = true;
    }
    vector<vector<bool>> right(n, vector<bool>(m+1, false));
    for(int i = 0; i < n; ++i) {
      bool found = false;
      for(int j = m-1; j >= 0; --j) {
        found |= (a[i] == b[j]);
        right[i][j] = found;
      }
    }
    function<ll(int, int)> go = [&] (int i, int j) {
      //~ debug(fa, ta, fb, tb, needed);
      if(i == n) return (j == m ? 0 : oo + oo);
      ll& ans = dp[i][j];
      if(seen[i][j] == tc) return ans;
      seen[i][j] = tc;
      ans = oo + oo;
      if(left[i][j] || !right[i][j]) {
        ans = min(ans, go(i+1, j) + c[i]);
      }
      if(j < m && a[i] == b[j]) {
        ans = min(ans, go(i+1, j+1));
      }
      return ans;
    };
    ll ans = go(0, 0);
    if(ans >= oo) {
      cout << "No" << endl;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}
