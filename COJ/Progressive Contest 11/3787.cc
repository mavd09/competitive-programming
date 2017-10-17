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

const int MAXN = int( 11e3 );
const int MAXS = int( 6e7 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n;
int dp[ MAXN ][ 3 ];
int mp[ MAXS ];

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

  for( int i = 0; i < MAXN; i++ ) {
    dp[ i ][ 0 ] = 1;
  }
  for( n = 0; n < MAXN; n++ ) {
    for( int i = 0; i <= n; i++ ) {
      dp[ n ][ 1 ] += dp[ n-i ][ 0 ];
    }
    for( int i = 0; i <= n; i++ ) {
      dp[ n ][ 2 ] += dp[ n-i ][ 1 ];
    }
    if( dp[ n ][ 2 ] < MAXS ) {
      mp[ dp[ n ][ 2 ] ] = n+1;
    }
  }

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    int x; cin >> x;
    if( mp[ x ] == 0 ) {
      cout << "No solution\n";
    }
    else {
      cout << mp[ x ]-1 << "\n";
    }
  }

  return 0;
}