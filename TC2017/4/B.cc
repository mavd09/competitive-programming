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
typedef double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 4e3 )+10;
const int MOD  = int( 360 );
const lf  oo   = 1e12;

int tc, n, f, t;

lf dp[ MAXN ][ 2 ][ 2 ];

int x[ MAXN ], y[ MAXN ];

inline int add( int a, int b ) { return ( a+b >= n ? a+b-n : a+b ); }
inline int subt( int a, int b ) { return ( a-b < 0 ? a-b+n : a-b ); }
inline int sqr( int x ) { return x*x; }

inline lf get_dist( int i, int j ) {
  return sqrt( sqr( x[ i ]-x[ j ] ) + sqr( y[ i ]-y[ j ] ) );
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    //ios_base::sync_with_stdio( 0 );
    //cin.tie( 0 );
  #endif

  for( tc = 1; scanf( "%d%d%d", &n, &f, &t ) == 3; ++tc ) {
    f--; t--;
    for( int i = 0; i < n; ++i ) {
      scanf( "%d%d", &x[ i ], &y[ i ] );
    }
    int v, id = 0;
    for( int i = 0 ; i < n; ++i ) {
      for( int j = 0; j < 2; ++j ) {
        dp[ i ][ j ][ 0 ] = dp[ i ][ j ][ 1 ] = oo;
      }
    }
    dp[ f ][ id ][ 0 ] = dp[ f ][ id ][ 1 ] = 0;
    for( int c = 1; c < n; ++c, id ^= 1 ) {
      for( int u = 0; u < n; ++u ) {
        for( int s = 0; s < 2; ++s ) {
          lf& r = dp[ u ][ id ][ s ];
          if( s == 0 ) {
            v = add( u, c );
            dp[ v ][ id^1 ][ 1 ] = min( dp[ v ][ id^1 ][ 1 ], r+get_dist( u, v ) );
            v = subt( u, 1 );
            dp[ v ][ id^1 ][ 0 ] = min( dp[ v ][ id^1 ][ 0 ], r+get_dist( u, v ) );
          } else {
            v = add( u, 1 );
            dp[ v ][ id^1 ][ 1 ] = min( dp[ v ][ id^1 ][ 1 ], r+get_dist( u, v ) );
            v = subt( u, c );
            dp[ v ][ id^1 ][ 0 ] = min( dp[ v ][ id^1 ][ 0 ], r+get_dist( u, v ) );
          }
          r = oo;
        }
      }
    }
    lf ans = min( dp[ t ][ id ][ 0 ], dp[ t ][ id ][ 1 ] );
    printf( "%.6f\n", double( ans ) );
  }

  return 0;
}