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
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n;
vpii graph[ MAXN ];

int size_trie;
int trie[ MAXN*32 ][ 2 ];

int val[ MAXN ];

int add_node( ) {
  int new_node = size_trie++;
  trie[ new_node ][ 0 ] = trie[ new_node ][ 1 ] = -1;
  return new_node;
}

void add( int x ) {
  int node = 0;
  for( int i = 31; i >= 0; --i ) {
    int v = (x>>i)&1;
    if( trie[ node ][ v ] == -1 ) {
      trie[ node ][ v ] = add_node( );
    }
    node = trie[ node ][ v ];
  }
}

int query( int x ) {
  int node = 0, ans = 0;
  for( int i = 31; i >= 0; --i ) {
    int v = ((x>>i)&1);
    if( trie[ node ][ v^1 ] != -1 ) {
      ans |= (1<<i);
      node = trie[ node ][ v^1 ];
    } else {
      node = trie[ node ][ v ];
    }
  }
  return ans;
}

void dfs( int p, int u ) {
  for( auto& e : graph[ u ] ) {
    if( e.FI == p ) {
      continue;
    }
    val[ e.FI ] = val[ u ]^e.SE;
    dfs( u, e.FI );
  }
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  while( cin >> n ) {
    for( int i = 0; i < n; ++i ) {
      graph[ i ].clear( );
    }
    for( int i = 1; i < n; ++i ) {
      int u, v, c; cin >> u >> v >> c; --u; --v;
      graph[ u ].PB( { v, c } );
      graph[ v ].PB( { u, c } );
    }
    val[ 0 ] = 0;
    dfs( -1, 0 );
    size_trie = 0;
    add_node( );
    for( int i = 0; i < n; ++i ) {
      add( val[ i ] );
    }
    for( int i = 0; i < n; ++i ) {
      cout << query( val[ i ] ) << '\n';
    }
  }

  return 0;
}