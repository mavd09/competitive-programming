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

const int LOG2 = 22;

int n, q, k;
vpii graph[ MAXN ];

int d[ MAXN ];
int dp[ MAXN ][ LOG2 ];
ll val[ MAXN ][ LOG2 ];

void init( ) {
  for( int i = 0; i < MAXN; ++i ) {
    graph[ i ].clear( );
  }
}

void dfs( int u, int p = 0 ) {
  d[ u ] = d[ p ]+1;
  dp[ u ][ 0 ] = p;
  for( auto& e : graph[ u ] ) {
    if( e.FI != p ) {
      dfs( e.FI, u );
      val[ e.FI ][ 0 ] = e.SE;
    }
  }
}

ll query( int u, int v ) {
  ll r = 0;
  if( d[ u ] > d[ v ] ) {
    swap( u, v );
  }
  for( int j = LOG2-1; j >= 0; --j ) {
    if( d[ u ] <= d[ dp[v][j] ] ) {
      r += val[ v ][ j ];
      v = dp[ v ][ j ];
    }
  }
  if( u == v ) {
    return r;
  }
  for( int j = LOG2-1; j >= 0; --j ) {
    if( dp[ u ][ j ] != dp[ v ][ j ] ) {
      r += val[ u ][ j ];
      u = dp[ u ][ j ];
      r += val[ v ][ j ];
      v = dp[ v ][ j ];
    }
  }
  r += val[ u ][ 0 ];
  r += val[ v ][ 0 ];
  return r;
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

  while( cin >> n ) {
    #ifdef LOCAL
      init( );
    #endif
    for( int i = 1; i < n; ++i ) {
      int u, v, c; cin >> u >> v >> c;
      graph[ u ].PB( { v, c } );
      graph[ v ].PB( { u, c } );
    }
    val[ 1 ][ 0 ] = 0;
    dfs( 1 );
    for( int j = 1; j < LOG2; ++j ) {
      for( int i = 1; i <= n; ++i ) {
        val[ i ][ j ] = val[ i ][ j-1 ]+val[ dp[i][j-1] ][ j-1 ];
        dp[ i ][ j ] = dp[ dp[i][j-1] ][ j-1 ];
      }
    }
    cin >> q >> k;
    while( q-- ) {
      int u, v; cin >> u >> v;
      cout << query( u, k )+query( v, k ) << '\n';
    }
  }

  return 0;
}