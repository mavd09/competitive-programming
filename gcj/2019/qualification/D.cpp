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

string ask(int n, int len) {
  for(int i = 0; i < n; ++i) {
    int x = i % (2 * len);
    if(x < len) cout << 0;
    else cout << 1;
  }
  cout << endl;
  string res; cin >> res;
  return res;
}

void solve(vector<string>& ans, vector<int>& broken, int idx, int len, int from, int to) {
  if(to <= from) {
    for(int i = 0; i < len; ++i) {
      broken.push_back(idx + i);
    }
    return ;
  }
  if(len == 1) {
    return ;
  }
  int zeros = 0, ones = 0;
  for(int i = from; i < to; ++i) {
    zeros += ans[len >> 1][i] == '0';
    ones += ans[len >> 1][i] == '1';
  }
  solve(ans, broken, idx, len >> 1, from, from+zeros);
  solve(ans, broken, idx + (len >> 1), len >> 1, from+zeros, to);
}

int main() {

  int n_test; cin >> n_test;
  for(int tc = 1; n_test--; ++tc) {
    int n, b, f; cin >> n >> b >> f;
    const int GROUP_LEN = 16;
    vector<string> ans(GROUP_LEN + 1);
    for(int i = GROUP_LEN; i > 0; i >>= 1) {
      ans[i] = ask(n, i);
    }
    int offset = 0;
    vector<int> broken;
    for(int i = 0, j = 0; i < (int) ans[GROUP_LEN].size(); i = j) {
      while(j < (int) ans[GROUP_LEN].size() && ans[GROUP_LEN][i] == ans[GROUP_LEN][j]) {
        j++;
      }
      solve(ans, broken, i + offset, GROUP_LEN >> 1, i, j);
      int missing = GROUP_LEN - (j-i);
      offset += missing;
    }
    sort(broken.begin(), broken.end());
    for(int i = 0; i < b; ++i) {
      if(i) cout << ' ';
      cout << broken[i];
    }
    cout << endl;
    int verdict; cin >> verdict;
    if(verdict == -1) {
      exit(0);
    }
  }

  return 0;
}
