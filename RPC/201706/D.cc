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

const int MAXN = int( 2e4 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n;
ll x;
ll a[ MAXN ], h[ MAXN ];

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

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    cin >> x >> n;
    a[ 0 ] = 0;
    for( int i = 1; i <= n; i++ ) {
      cin >> a[ i ];
      a[ i ] += a[ i-1 ];
    }
    for( int i = 0; i <= n; i++ ) {
      cin >> h[ i ];
    }
    ll ans = 0;
    for( int i = 1, j = 0; i <= n; i++ ) {
      if( h[ i ] >= h[ j ] ) {
        ans += h[ j ]*abs( a[ i ]-a[ j ] );
        j = i;
      }
    }
    for( int i = n-1, j = n; i >= 0; i-- ) {
      if( h[ i ] > h[ j ] ) {
        ans += h[ j ]*abs( a[ i ]-a[ j ] );
        j = i;
      }
    }
    cout << ans*x << "\n";
  }

  return 0;
}