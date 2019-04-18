#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

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
  #define endl '\n'
#endif

const int N = 5e3 + 10;
const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;  

int n;
int c[N], dp[N][N];
int fr[N], to[N];

int go(int i, int j) {
  if(j < i) return 0;
  int& r = dp[i][j];
  if(r != -1) return r;
  r = min(go(to[i], j), go(i, fr[j]));
  if(c[i] == c[j]) {
    r = min(r, go(to[i], fr[j]));
  }
  r += 1;
  return r;
}

int main() {

  ios::sync_with_stdio(0); cin.tie(0);

  while(cin >> n) {
    for(int i = 0; i < n; ++i) {
      cin >> c[i];
    }
    for(int i = 0; i < n; ) {
      int j = i;
      while(j < n && c[i] == c[j]) j++;
      for(int k = i; k < j; ++k) {
        to[k] = j;
      }
      i = j;
    }
    for(int i = n-1; i >= 0; ) {
      int j = i;
      while(j >= 0 && c[i] == c[j]) j--;
      for(int k = i; k > j; --k) {
        fr[k] = j;
      }
      i = j;
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, n-1) - 1 << endl;
  }

  return 0;
}