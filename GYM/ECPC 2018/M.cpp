#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

enum {IN, QRY, OUT};

struct event {
  int tp, x, val, id;
};

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    freopen("business.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  int n_test; cin >> n_test;
  for(int tc = 1; n_test--; ++tc) {
    int n, m; cin >> n >> m;
    vector<event> events;
    for(int i = 0; i < n; ++i) {
      int x, q, r; cin >> x >> q >> r;
      events.push_back({IN, x, q-x, i});
      events.push_back({OUT, x+r, q-x, i});
    }
    for(int i = 0; i < m; ++i) {
      int y, d; cin >> y >> d;
      events.push_back({QRY, y, d-y, i});
    }
    sort(events.begin(), events.end(), [&] (const event& e1, const event& e2) {
      if(e1.x != e2.x) {
        return e1.x < e2.x;
      }
      return e1.tp < e2.tp;
    });
    ordered_set cur;
    vector<int> ans(m);
    for(auto& e : events) {
      debug(e.tp, e.x, e.val);
      if(e.tp == IN) {
        cur.insert({e.val, e.id});
      } else if(e.tp == OUT) {
        cur.erase({e.val, e.id});
      } else {
        ans[e.id] = (int)cur.size() - cur.order_of_key({e.val, -1});
      }
    }
    for(int i = 0; i < m; ++i) {
      cout << ans[i] << " \n"[i+1==m];
    }
  }

  return 0;
}
