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
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, h;
int arr[ MAXN ];

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

  while( cin >> n >> h ) {
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
    }
    int pos = 0, has_box = 0;
    int cmd;
    while( cin >> cmd ) {
      if( cmd == 0 ) {
        break;
      } else if( cmd == 1 ) {
        pos = max( 0, pos-1 );
      } else if( cmd == 2 ) {
        pos = min( n-1, pos+1 );
      } else if( cmd == 3 ) {
        if( has_box == 0 && arr[ pos ] > 0 ) {
          has_box = 1;
          arr[ pos ]--;
        }
      } else if( cmd == 4 ) {
        if( has_box && arr[ pos ]+1 <= h ) {
          has_box = 0;
          arr[ pos ]++;
        }
      } else {
        assert( false );
      }
    }
    for( int i = 0; i < n; ++i ) {
      cout << arr[ i ] << " \n"[ i+1 == n ];
    }
  }

  return 0;
}