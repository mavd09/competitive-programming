#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e5 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

int n, m;
vector<int> g[MAXN];

int st[4*MAXN], lz[4*MAXN];

void propagate( int node, int l, int r ) {
  st[node] += lz[node];
  if( lz[node] && l != r ) {
    lz[node+node] += lz[node];
    lz[node+node+1] += lz[node];
  }
  lz[node] = 0;
}

void update_tree( int f, int t, int val, int node = 1, int l = 0, int r = n-1 ) {
  propagate(node, l, r);
  if( f == l && t == r ) {
    lz[node] += val;
    propagate(node, l, r);
    return ;
  }
  int m = (l+r) >> 1;
  if( t <= m ) {
    update_tree( f, t, val, node+node, l, m );
    propagate( node+node+1, m+1, r);
  } else if( f > m ) {
    propagate( node+node, l, m );
    update_tree( f, t, val, node+node+1, m+1, r );
  } else {
    update_tree( f, m, val, node+node, l, m );
    update_tree( m+1, t, val, node+node+1, m+1, r );
  }
  st[node] = max( st[node+node], st[node+node+1] );
}

int idx;
int depth[MAXN];
vector<int> len, hld_child, hld_index, hld_root, up;
void dfs( int u, int p = 0 ) {
  len[u] = 1;
  up[u] = p;
  for( auto& v : g[u] ) {
    if( v == p ) continue;
    depth[v] = depth[u]+1;
    dfs(v, u);
    len[u] += len[v];
    if( hld_child[u] == -1 || len[hld_child[u]] < len[v] )
      hld_child[u] = v;
  }
}
void build_hld( int u, int p = 0 ) {
  hld_index[u] = idx++;
  if( hld_root[u] == -1 ) hld_root[u] = u;
  if( hld_child[u] != -1 ) {
    hld_root[hld_child[u]] = hld_root[u];
    build_hld(hld_child[u], u);
  }
  for( auto& v : g[u] ) {
    if( v == p || v == hld_child[u] ) continue;
    build_hld(v, u);
  }
}
void update_hld( int u, int v, int val ) {
  while( hld_root[u] != hld_root[v] ) {
    if( depth[hld_root[u]] < depth[hld_root[v]] ) swap(u, v);
    update_tree(hld_index[hld_root[u]], hld_index[u], val);
    u = up[hld_root[u]];
  }
  if( depth[u] > depth[v] ) swap(u, v);
  update_tree(hld_index[u], hld_index[v], val);
}
void build(int n, int root) {
  len = hld_index = up = vector<int>(n+1);
  hld_child = hld_root = vector<int>(n+1, -1);
  idx = 0;
  dfs(root); build_hld(root);
}

int main() {

  scanf( "%d %d", &n, &m );
  for( int i = 1; i < n; ++i ) {
    int u, v; scanf( "%d %d", &u, &v );
    g[u].push_back(v);
    g[v].push_back(u);
  }
  build(n, 0);
  for( int i = 0; i < m; ++i ) {
    int u, v, k; scanf( "%d %d %d", &u, &v, &k );
    update_hld( u, v, k );
  }
  printf( "%d\n", st[1] );

  return 0;
}