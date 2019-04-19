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
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int a[ MAXN ];

int add( int a, int b ) { return ( a+b )%MOD; }
int mul( int a, int b ) { return ( 1LL*a*b )%( 1LL*MOD ); } 

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
    int s = 0, m = 0;
    for( int i = n-1; i >= 0; i-- ) {
      s = add( add( s, s ), a[ i ] );
      m = mul( a[ i ], add( m, 1 ) );
    }
    cout << s << " " << m << endl;
    cout << add( s, m ) << "\n";
  }

  return 0;
}