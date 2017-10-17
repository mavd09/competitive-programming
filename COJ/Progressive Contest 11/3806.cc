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

const int MAXN = int( 1e6 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int cnt[ MAXN ];

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

  vi seq = { 1 };
  cnt[ 1 ] = cnt[ 2 ] = 1;

  for( int it = 1; it < int( 1e4 ); it++ ) {
    int n;
    for( n = seq.back( )+1; ; n++ ) {
      if( cnt[ n ] == 1 ) {
        break;
      }
    }
    for( auto& e : seq ) {
      cnt[ e+n ]++;
    }
    seq.PB( n );
  }

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    int n; cin >> n;
    cout << seq[ n-1 ] << "\n";
  }

  return 0;
}