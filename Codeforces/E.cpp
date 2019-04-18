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
#endif

const int N = 1e6 + 100;
const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;

vector<int> test = {14, 24, 9, 19};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int cnt_queries;

int memo_value[N];
int get_value(int i) {
  if(memo_value[i] == -1) {
    cnt_queries++;
    #ifdef LOCAL
      memo_value[i] = test[i-1];
      cout << test[i-1] << endl;
    #else
      cout << '?' << ' ' << i << endl;
      int ans; cin >> ans;
      memo_value[i] = ans;
    #endif
  }
  return memo_value[i];
}

map<int, int> memo_exists;
bool exists(int x) {
  if(!memo_exists.count(x)) {
    cnt_queries++;
    cout << '>' << ' ' << x << endl;
    #ifdef LOCAL
      bool g = false;
      for(int i = 0; i < test.size(); ++i) {
        if(test[i] > x) {
          g = true;
        }
      }
      cout << g << endl;
      memo_exists[x] = g;
    #else
      int ans; cin >> ans;
      memo_exists[x] = ans;
    #endif
  }
  return memo_exists[x] == 1;
}

int main() {

  // ios::sync_with_stdio(0); cin.tie(0);

  cnt_queries = 0;
  memset(memo_value, -1, sizeof(memo_value));
  memo_exists.clear();

  int n;
  #ifdef LOCAL
    n = test.size();
    cout << n << endl;
  #else
    cin >> n;
  #endif

  int lo = 0, hi = 1000000000;
  while(lo <= hi) {
    int mi = (lo + hi) >> 1;
    if(exists(mi)) {
      lo = mi+1;
    } else {
      hi = mi-1;
    }
  }
  
  int mx = lo;

  uniform_int_distribution<int> dis(1, n);

  vector<int> all = {mx};

  int lim = min(60, cnt_queries + n);
  while(cnt_queries < lim) {
    all.push_back(get_value(dis(rng)));
  }

  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());

  debug(all);

  set<int> divs;
  for(int i = 1; i < all.size(); ++i) {
    int diff = all[i] - all[i-1];
    set<int> cur_divs;
    for(int j = 1; j*j <= diff; ++j) {
      if(diff % j == 0) {
        cur_divs.insert(j);
        if(j*j != diff) {
          cur_divs.insert(diff / j);
        }
      }
    }
    debug(cur_divs);
    if(i == 1) {
      divs = cur_divs;
    } else {
      set<int> to_erase;
      for(auto& e : divs) {
        if(!cur_divs.count(e)) {
          to_erase.insert(e);
        }
      }
      for(auto& e : to_erase) {
        divs.erase(e);
      }
    }
  }

  int ans = -1, diff = -1;
  for(auto& d : divs) {
    if(mx - d*(n-1) <= all[0]) {
      assert(ans == -1);
      ans = mx - d*(n-1);
      diff = d;
    }
  }

  cout << '!' << ' ' << ans << ' ' << diff << endl;

  return 0;
}