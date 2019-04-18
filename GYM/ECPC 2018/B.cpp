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

const int oo = 1e9 + 100;

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    freopen("task.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  int n_test; 
  cin >> n_test;
  for(int tc = 1; n_test--; ++tc) {
    int n; cin >> n;
    vector<int> v(n);
    for(auto& e : v) {
      cin >> e;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    int base = n - (int)v.size();
    int ans = oo;
    for(int i = 0; i < (int)v.size(); ++i) {
      ans = min(ans, v[i]-i-1 + base + (int)v.size()-i-1);
    }
    ans = min(ans, n + 1);
    cout << ans << endl;
  }

  return 0;
}
