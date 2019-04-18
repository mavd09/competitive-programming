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

const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;  

int main() {

  ios::sync_with_stdio(0); cin.tie(0);

  int x, y, z, a, b, c;

  while(cin >> x >> y >> z >> a >> b >> c) {
    bool ok = true;
    if(x <= a) {
      a -= x;
    } else {
      ok = false;
    }
    a += b;
    if(y <= a) {
      a -= y;
    } else {
      ok = false;
    }
    a += c;
    if(z <= a) {
      a -= z;
    } else {
      ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}