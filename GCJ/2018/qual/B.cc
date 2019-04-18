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

int n;
int arr[ MAXN ];

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  int n_test; scanf( "%d", &n_test );

  for( int tc = 1; n_test--; ++tc ) {
    scanf( "%d", &n );
    vi even, odd;
    for( int i = 0; i < n; ++i ) {
      scanf( "%d", &arr[i] );
      if( i&1 ) odd.PB( arr[i] );
      else even.PB( arr[i] );
    }
    sort( arr, arr+n );
    sort( ALL(odd) ); sort( ALL(even) );
    int ans = -1;
    for( int i = 0; i < n; ++i ) {
      if( (i%2 == 0 && arr[i] != even[i/2]) || (i%2 == 1 && arr[i] != odd[i/2] ) ) {
        ans = i;
        break;
      } 
    }
    printf( "Case #%d: ", tc );
    if( ans == -1 ) puts( "OK" );
    else printf( "%d\n", ans );
  }

  return 0;
}

