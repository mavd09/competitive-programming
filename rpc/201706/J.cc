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

const int MAXN = int( 50 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

const int dx[ ] = { 1, 0, -1, 0 };
const int dy[ ] = { 0, 1, 0, -1 };

int dp[ MAXN ][ MAXN ];
int r, c;
bool seen[ MAXN ][ MAXN ];

int go( int x, int y, int d ) {
  if( !( 0 <= x && x < r && 0 <= y && y < c ) || seen[ x ][ y ] ) return 1;
  seen[ x ][ y ] = true;
  int r = 0;
  r += go( x+dx[ d ], y+dy[ d ], d );
  d = ( d+1 )%4;
  r += go( x+dx[ d ], y+dy[ d ], d );
  seen[ x ][ y ] = false;
  return r;
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

  memset( dp, -1, sizeof( dp ) );

  int n_test; cin >> n_test;

  //for( int tc = 1; n_test--; tc++ ) {
    //cin >> r >> c;
  for( r = 1; r <= 25; r++ ) {
    for( c = 1; c <= 25; c++ ) {
      if( dp[ r ][ c ] == -1 ) {
        dp[ r ][ c ] = go( 0, 0, 0 );
      }
      cout << r << " " << c << " = " << dp[ r ][ c ] << "\n";
    }
  }

  return 0;
}