#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 2e5 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

int n, q;
map<string, int> id;

char buff[MAXN];

vector<int> graph[MAXN];
bool complete[]
ll fr_dv[MAXN], to_dv[MAXN];
ll fr_all[MAXN], to_all[MAXN];

int get_id( string name ) {
  if( name == "NONE" ) return -1;
  if( id.count(name) ) return id[name];
  int nid = id.size();
  id[name] = nid;
  return nid;
}

void dfs0( int u, int p = -1 ) {
  int zeros = 0, sum = 0;
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    if( fr_all[v] == 0 ) zeros++;
    sum += fr_all[v];
  }
  if( fr_all[u] != 0 && zeros == 1 ) {
    fr_all[id_zero] = to_all[id_zero] = fr_all[u]-sum;
  }
}

void dfs1( int u, int p = -1 ) {
  int zeros = 0, id_zero = -1;
  int sum = 0;
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    if( fr_all[v] == 0 ) {
      zeros++;
      id_zero = v;
    }
    sum += fr_all[v];
  }
  if( fr_all[u] != 0 && zeros == 1 ) {
    fr_all[id_zero] = to_all[id_zero] = fr_all[u]-sum;
  }
}

int main() {

  scanf( "%d %d", &n, &q );

  int root = -1;
  for( int i = 0; i < n; ++i ) {
    scanf( "%s", buff );
    int ida = get_id(buff);
    scanf( "%s", buff );
    int idb = get_id(buff);
    int sz, all; scanf( "%d %d", &sz, &all );
    fr_dv[ida] = to_dv[ida] = sz;
    fr_all[ida] = to_all[ida] = all;
    if( idb != -1 ) {
      graph[ida].push_back(idb);
      graph[idb].push_back(ida);
    } else {
      root = ida;
    }
  }

  dfs0(root);

  return 0;
}