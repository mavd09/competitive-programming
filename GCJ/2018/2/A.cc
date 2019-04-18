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

const int MAXN = int( 1e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m;
int b[ MAXN ];

char ans[ MAXN ][ MAXN ];

int main( ) {

  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );

  int n_test; scanf( "%d", &n_test );

  for( int tc = 1; n_test--; ++tc ) {
    scanf( "%d", &m );
    for( int i = 0; i < m; ++i ) scanf( "%d", &b[i] );
    if( b[0] == 0 || b[m-1] == 0 ) {
      printf( "Case #%d: IMPOSSIBLE\n", tc );
      continue;
    }
    for( int i = 0; i < m; ++i ) {
      for( int j = 0; j < m; ++j ) {
        ans[i][j] = '.';
      }
    }
    n = 1;
    for( int j = 0, x = 0; j < m; ++j ) {
      while( b[x] == 0 ) x++;
      b[x]--;
      n = max( n, abs(j-x)+1 );
      if( x == j ) continue;
      if( x < j ) {
        for( int d = 0; d < (j-x); ++d ) {
          ans[d][j-d] = '/';
        } 
      } else {
        for( int d = 0; d < (x-j); ++d ) {
          ans[d][j+d] = '\\';
        }
      }
    }
    for( int i = 0; i < n; ++i ) assert( ans[i][0] == '.' && ans[i][m-1] == '.' );
    for( int j = 0; j < m; ++j ) assert( ans[n-1][j] == '.' );
    printf( "Case #%d: %d\n", tc, n );
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        printf( "%c", ans[i][j] );
      }
      puts("");
    }
  }

  return 0;
}

