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

typedef complex< lf >       pt;

const int MAXN = int( 2e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int g;
int n, m; ll x;
ll a[ MAXN ], b[ MAXN ];

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

  cin >> g;

  while( g-- ) {
    cin >> n >> m >> x;
    for( int i = 1; i <= n; i++ ) {
      cin >> a[ i ];
      a[ i ] += a[ i-1 ];
    }
    for( int i = 1; i <= m; i++ ) {
      cin >> b[ i ];
      b[ i ] += b[ i-1 ];
    }
    int ans = 0;
    for( int i = 0; i <= n; i++ ) {
      if( x-a[ i ] < 0 ) break;
      int t = upper_bound( b, b+m+1, x-a[ i ] )-b-1;
      ans = max( ans, i+t );
    }
    cout << ans << "\n";
  }

  return 0;
}
