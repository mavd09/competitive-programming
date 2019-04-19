#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m;
vi graph[MAXN];

int t = 1;
int dfn[MAXN], low[MAXN];
bool seen[MAXN];

int p[MAXN];

int find_set( int x ) {
  if( x == p[x] ) return x;
  return p[x] = find_set(p[x]);
}

void union_set( int a, int b ) {
  p[find_set(a)] = find_set(b);
}

void dfs( int u, int p = -1 ) {
  dfn[ u ] = low[ u ] = ++t;
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    if( dfn[ v ] == -1 ) {
      dfs( v, u );
      low[ u ] = min( low[u], low[v] );
      if( low[v] > dfn[u] ) {
        union_set( u, v );
      }
    }
    else if( v != p ) {
      low[ u ] = min( low[u], dfn[v] );
    }
  }
}

int mark( int u ) {
  int cnt = 0;
  queue< int > q;
  q.push( u );
  while( !q.empty() ) {
    u = q.front(); q.pop();
    cnt++;
    for( auto& v : graph[u] ) {
      if( !seen[v] && find_set(u) != find_set(v) ) {
        seen[v] = true;
        q.push(v);
      }
    }
  }
  return cnt;
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  memset( dfn, -1, sizeof(dfn) );

  cin >> n >> m;

  for( int i = 0; i < m; ++i ) {
    int u, v; cin >> u >> v; u--; v--;
    graph[u].PB(v);
    graph[v].PB(u);
  }

  for( int i = 0; i < n; ++i ) {
    p[i] = i;
  }

  for( int i = 0; i < n; ++i ) {
    if( dfn[i] == -1 ) {
      dfs( i );
    }
  }

  for( int i = 0; i < n; ++i ) {
    if( !seen[i] && mark(i) == 1 ) {
      cout << i+1 << '\n';
    }
  }

  return 0;
}

