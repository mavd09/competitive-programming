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

const int MAXN = int( 2e5 );
const int MAXV = int( 2e6 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n;
int a[ MAXN ], seen[ MAXV ];

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
    cin >> n;
    for( int i = 0; i < n; i++ ) {
      cin >> a[ i ];
    }
    int ans = 0;
    for( int i = 0, j = 0; i < n; i++ ) {
      while( j < n && seen[ a[ j ] ] != tc ) {
        seen[ a[ j++ ] ] = tc;
      }
      seen[ a[ i ] ] = 0;
      ans = max( ans, j-i );
    }
    cout << ans << "\n";
  }

  return 0;
}