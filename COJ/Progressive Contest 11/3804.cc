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
    ll n; cin >> n;
    int to = 64-__builtin_clzll( n );
    //cout << bitset< 32 >( n ) << " " << to << endl;
    set< int > s;
    for( int i = 0; i < 32; i++ ) {
      int cur = 0;
      for( int j = 0; j < 5; j++ ) {
        int pos = ( i+j )%32;
        cur |= ( (n>>pos)&1 )<<j;
      }
      //cout << bitset< 5 >( cur ) << endl; 
      s.insert( cur );
    }
    if( SIZE( s ) == 32 ) {
      cout << "yes\n";
    }
    else {
      cout << "no\n";
    }
  }

  return 0;
}