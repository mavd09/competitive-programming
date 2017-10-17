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

const int MAXN = int( 2e5 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, k;
int arr[ MAXN ], cp[ MAXN ];
vi graph[ MAXN ]; 

int sz[ MAXN ], ok[ MAXN ], best[ MAXN ][ 2 ];

void update( int u, int val ) {
  if( val > best[ u ][ 0 ] ) {
    best[ u ][ 1 ] = best[ u ][ 0 ];
    best[ u ][ 0 ] = val;
  } else if( val > best[ u ][ 1 ] ) {
    best[ u ][ 1 ] = val;
  }
}

void dfs1( int x, int p, int u ) {
  best[ u ][ 0 ] = best[ u ][ 1 ] = 0;
  sz[ u ] = 1; ok[ u ] = ( arr[ u ] >= x );
  for( auto& v : graph[ u ] ) {
    if( v == p ) {
      continue;
    }
    dfs1( x, u, v );
    if( arr[ v ] >= x ) {
      if( sz[ v ] == ok[ v ] ) {
        ok[ u ] += ok[ v ];
      } else {
        update( u, ok[ v ]+best[ v ][ 0 ] );
      }
    }
    sz[ u ] += sz[ v ]; 
  }
  //cout << u+1 << ' ' << sz[ u ] << ' ' << ok[ u ] << '\n';
}

void dfs2( int x, int p, int u ) {
  if( p != -1 && arr[ p ] >= x ) {
    if( sz[ u ] == ok[ u ] ) {
      if( n-sz[ u ] == ok[ p ]-ok[ u ] ) {
        ok[ u ] = ok[ p ];
      } else {
        update( u, ok[ p ]-ok[ u ]+best[ p ][ 0 ] );
      }
    } else {
      if( n-sz[ u ] == ok[ p ] ) {
        ok[ u ] += ok[ p ];
      } else if( best[ p ][ 0 ] == ok[ u ]+best[ u ][ 0 ] ) {
        update( u, ok[ p ]+best[ p ][ 1 ] );
      } else {
        update( u, ok[ p ]+best[ p ][ 0 ] );
      }
    }
  }
  for( auto& v : graph[ u ] ) {
    if( v == p ) {
      continue;
    }
    dfs2( x, u, v );
  }
}

bool check( int x ) {
  //cout << "Checking with " << x << '\n';
  dfs1( x, -1, 0 );
  dfs2( x, -1, 0 );
  for( int i = 0; i < n; ++i ) {
    if( arr[ i ] >= x && ok[ i ]+best[ i ][ 0 ] >= k ) {
      return true;
    }
  }
  return false;
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

  while( cin >> n >> k ) {
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
      graph[ i ].clear( );
    }
    memcpy( cp, arr, sizeof( int )*n );
    for( int i = 1; i < n; ++i ) {
      int u, v; cin >> u >> v; --u; --v;
      graph[ u ].PB( v );
      graph[ v ].PB( u );
    }
    sort( cp, cp+n );
    int lo = 0, hi = n-1, mi;
    while( lo <= hi ) {
      mi = ( lo+hi )>>1;
      if( check( cp[ mi ] ) ) {
        lo = mi+1;
      } else {
        hi = mi-1;
      }
    }
    cout << cp[ hi ] << '\n';
  }

  return 0;
}