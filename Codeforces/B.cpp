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

const int N = 2e5 + 100;
const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9; 

int n, m, k;
pii arr[N];
bool used[N];

int main() {

  ios::sync_with_stdio(0); cin.tie(0);

  while(cin >> n >> m >> k) {
    for(int i = 0; i < n; ++i) {
      cin >> arr[i].first;
      arr[i].second = i;
    }
    sort(arr, arr+n);
    reverse(arr, arr+n);
    memset(used, false, sizeof(used));
    ll ans = 0;
    for(int i = 0; i < m*k; ++i) {
      ans += arr[i].first;
      used[arr[i].second] = true;
    }
    vector<int> p;
    int t = 0;
    for(int i = 0; i < n; ++i) {
      if(used[i]) {
        t++;
      }
      if(t == m) {
        p.push_back(i+1);
        t = 0;
      }
    }
    cout << ans << endl;
    for(int i = 0; i+1 < p.size(); ++i) {
      cout << p[i] << " \n"[i+2 == p.size()];
    }
  }

  return 0;
}