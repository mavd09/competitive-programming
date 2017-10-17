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
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n[ 3 ];
queue< int > q[ 3 ];

int get_top( int id ) {
  if( q[ id ].empty( ) ) {
    return oo;
  }
  return q[ id ].front( );
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

  while( cin >> n[ 0 ] >> n[ 1 ] >> n[ 2 ] ) {
    for( int i = 0; i < 3; ++i ) {
      for( int j = 0; j < n[ i ]; ++j ) {
        int x; cin >> x;
        q[ i ].push( x );
      }
    }
    vi ans;
    while( true ) {
      int mn = oo;
      for( int i = 0; i < 3; ++i ) {
        mn = min( mn, get_top( i ) );
      }
      if( mn == oo ) {
        break;
      }
      int cnt = 0;
      for( int i = 0; i < 3; ++i ) {
        if( get_top( i ) == mn ) {
          q[ i ].pop( );
          ++cnt;
        }
      }
      if( cnt >= 2 ) {
        ans.PB( mn );
      }
    }
    cout << SIZE( ans ) << '\n';
    for( int i = 0; i < SIZE( ans ); ++i ) {
      cout << ans[ i ] << "\n";
    }
  }

  return 0;
}