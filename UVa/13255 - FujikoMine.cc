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

const int MAXN = int( 5e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = int( 1e8 );

int n, m, q;
vpii graph[ MAXN ];
int in_deg[ MAXN ];
int is_transmitter[ MAXN ];

int sz[ MAXN ];
int dp1[ MAXN ][ MAXN ]; // for complete paths
int dp2[ MAXN ][ MAXN ]; // for incomplete paths

int ans[ MAXN ];

void update( int& r, int x, int y, int w ) {
  if( x == -1 || y == -1 ) return ;
  r = max( r, x+y+w );
}

void dfs( int u ) {
  for( int i = 0; i <= n; ++i ) {
    dp1[u][i] = dp2[u][i] = -1;
  }
  sz[u] = is_transmitter[u];
  dp1[u][0] = 0;
  dp2[u][ sz[u] ] = 0;
  for( auto& e : graph[u] ) {
    int v = e.FI, w = e.SE;
    dfs( v );
    for( int i = sz[u]; i >= 0; --i ) {
      for( int j = sz[v]; j > 0; --j ) {
        update( dp1[u][i+j], dp1[u][i], dp1[v][j], 0 );
        update( dp2[u][i+j], dp2[u][i], dp2[v][j], w );
      }
    }
    sz[u] += sz[v];
  }
  for( int i = 0; i <= sz[u]; ++i ) {
    if( is_transmitter[u] ) {
      dp1[u][i] = max( dp1[u][i], dp2[u][i] );
    }
    ans[i] = max( ans[i], dp1[u][i] );
  }
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

  while( cin >> n >> m >> q ) {
    for( int i = 0; i <= n; ++i ) {
      graph[i].clear();
      in_deg[i] = ans[i] = 0;
      is_transmitter[i] = 0;
    }
    for( int i = 1; i < n; ++i ) {
      int u, v, w; cin >> u >> v >> w;
      graph[u].PB( {v,w} );
      in_deg[v]++;
    }
    for( int i = 0; i < m; ++i ) {
      int u; cin >> u;
      is_transmitter[u] = 1;
    }
    int root = -1;
    for( int i = 0; i < n; ++i ) {
      if( in_deg[i] == 0 ) {
        root = i;
      }
    }
    dfs( root );
    for( int i = 0; i < q; ++i ) {
      int x; cin >> x; 
      cout << ans[x] << '\n';
    }
  }
  return 0;
}

