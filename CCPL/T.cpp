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
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;

struct tarjan_tree {
  int n, m, comp;
  vector<bool> bad;
  vector<vector<pii>> g;
  tarjan_tree(int n, int m) : n(n), m(m), comp(0), g(n), bad(m) {}
  void add_edge(vector<vector<pii>> &g, int u, int v, int c) { /// nodes from [1, n]
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  void add_edge(int u, int v, int c) { add_edge(g, u, v, c); }
  void tarjan(bool with_bridge) {
    vector<int> dfn(n+1), low(n+1);
    stack<int> st;
    function<void(int, int, int&)> dfs = [&](int u, int p, int &t) {
      dfn[u] = low[u] = ++t;
      st.push(u);
      int cntp = 0;
      for(pii e : g[u]) {
        int v = e.first, c = e.second;
        cntp += v == p;
        if(!dfn[v])	{
          dfs(v, u, t);
          low[u] = min(low[u], low[v]);
          if(with_bridge && low[v] > dfn[u]) {
            bad[c] = true;
          }
        }
        else if(v != p || cntp > 1) low[u] = min(low[u], dfn[v]);
      }
    };
    for(int u = 0, t; u < n; ++u) {
      if(g[u].size() && !dfn[u]) {
        comp++;
        dfs(u, -1, t = 0);
      }
    }
  }
  vector<pii>& operator[] (const int& idx) {
    return g[idx];
  }
};

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    // ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  for(int n, c; scanf("%d %d", &n, &c) == 2; ) {
    if(n == 0 && c == 0) break;
    vector<vector<int>> edges(n);
    for(int i = 0; i < c; ++i) {
      int k; scanf("%d", &k);
      for(int j = 0; j < k; ++j) {
        int u; scanf("%d", &u);
        edges[u].push_back(i);
      }
    }
    tarjan_tree g(c, n);
    vector<int> deg(c);
    for(int i = 0; i < n; ++i) {
      assert(!edges[i].empty());
      int u = edges[i][0], v = edges[i].back();
      deg[u]++; deg[v]++;
      g.add_edge(u, v, i);
    }
    vector<int> odd_nodes;
    for(int i = 0; i < c; ++i) {
      if(deg[i]&1) {
        odd_nodes.push_back(i);
      }
    }
    g.tarjan(true);
    if(g.comp != 1 || odd_nodes.size() > 2) {
      printf("-1\n");
      continue;
    }
    if(odd_nodes.empty()) {
      printf("0\n");
      continue;
    }
    int ans = oo, aux_ans = oo;
    for(int i = 0; i < n; ++i) {
      for(auto& u : edges[i]) {
        if(u == odd_nodes[0] || u == odd_nodes[1]) {
          if(g[u].size() == 1 || !g.bad[i]) 
            ans = min(ans, i);
        }
      }
    }
    assert(ans != -1);
    printf("%d\n", ans);
  }

  return 0;
}