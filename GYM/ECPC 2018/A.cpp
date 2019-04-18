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

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    freopen("zeros.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  int n_test; cin >> n_test;
  for(int tc = 1; n_test--; ++tc) {
    int x, y, M, K;
    cin >> x >> y >> M >> K;
    int len = x+y;
    if(len <= 4) {
      int ans = 0;
      for(int num = (1 << (len-1)); num < (1 << len); ++num) {
        if(__builtin_popcount(num) != x) {
          continue;
        }
        if(num % M >= K) {
          ans++;
        }
      }
      cout << ans << endl;
      continue;
    }
    vector<vector<int>> by_ones(x + 1);
    int a = (len + 1) / 2, b = len - a;
    for(ll mask = (1 << (a-1)); mask < (1 << a); ++mask) {
      int ones = __builtin_popcount(mask);
      if(ones > x) continue;
      by_ones[ones].push_back((mask << b) % M);
    }
    for(auto& v : by_ones) {
      sort(v.begin(), v.end());
    }
    function<int(int, int, int)> count_between = [&] (int idx, int fr, int to) {
      int upper = upper_bound(by_ones[idx].begin(), by_ones[idx].end(), to) - by_ones[idx].begin();
      int lower = lower_bound(by_ones[idx].begin(), by_ones[idx].end(), fr) - by_ones[idx].begin();
      return upper-lower;
    };
    ll ans = 0;
    for(ll mask = 0; mask < (1 << b); ++mask) {
      int ones = __builtin_popcount(mask);
      if(ones > x) continue;
      int target = x - ones;
      int mod = mask % M;
      int fr1 = max(0, K-mod), to1 = M-mod-1;
      int fr2 = M-mod+K, to2 = M-1;
      if(fr2 <= to1) { // fr1, to2
        ans += count_between(target, fr1, to2);
      } else {
        ans += count_between(target, fr1, to1);
        ans += count_between(target, fr2, to2);
      }
    }
    cout << ans << endl;
  }

  return 0;
}
