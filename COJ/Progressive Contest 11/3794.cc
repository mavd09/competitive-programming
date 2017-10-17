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

const int MAXN = int( 6e3 );
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int cnt[ MAXN ];
int comb[ MAXN ][ MAXN ];
int dp1[ MAXN ][ MAXN ], dp2[ MAXN ][ MAXN ];

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

  comb[ 0 ][ 0 ] = 1;
  for( int i = 1; i < MAXN; i++ ) {
    comb[ i ][ 0 ] = comb[ i ][ i ] = 1;
    for( int j = 1; j < i; j++ ) {
      comb[ i ][ j ] = ( comb[ i-1 ][ j-1 ]+comb[ i-1 ][ j ] )%MOD;
    }
  }

  for( int i = 2; i < MAXN; i++ ) {
    cnt[ i ] = 1;
    for( int j = 2; j*j <= i; j++ ) {
      if( i%j != 0 ) {
        continue;
      }
      cnt[ i ]++;
      if( j*j != i )
        cnt[ i ]++;
    }
  }

  for( int j = 1; j < MAXN; j++ ) {
    dp1[ 0 ][ j ] = 0;
    dp2[ 0 ][ j ] = 1;
  }
  for( int i = 1; i < MAXN; i++ ) {
    for( int j = 1; j < MAXN; j++ ) {
      int x = min( cnt[ i ], j );
      dp1[ i ][ j ] = ( dp1[ i-1 ][ j ]+x )%MOD;
      dp2[ i ][ j ] = ( 1LL*dp2[ i-1 ][ j ]*comb[ cnt[ i ] ][ x ] )%ll(MOD); 
    }
  }

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    int n, k; cin >> n >> k;
    cout << dp1[ n ][ k ] << " " << dp2[ n ][ k ] << "\n";
  }

  return 0;
}