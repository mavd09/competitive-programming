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
const ll  oo   = ll( 1e18 );

int n;

ll calc( vll& x, ll p ) {
  ll r = 0;
  for( int i = 0; i < n; i++ ) {
    r += abs( x[ i ]-p );
  }
  return r;
}

ll f( vll& x ) {
  ll lo, hi, mi1, mi2, fmi1, fmi2;
  lo = -ll( 1e10 ); hi = ll( 1e10 );
  for( int i = 0; i < 100; i++ ) {
    mi1 = lo + ( hi-lo )/3;
    mi2 = hi - ( hi-lo )/3;
    fmi1 = calc( x, mi1 );
    fmi2 = calc( x, mi2 );
    if( fmi1 >= fmi2 ) {
      lo = mi1;
    }
    if( fmi2 >= fmi1 ) {
      hi = mi2;
    }
  }
  ll r = oo;
  for( ll i = lo; i <= hi; i++ ) {
    r = min( r, calc( x, i ) );
  }
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

  while( cin >> n ) {
    vll x( n ), y( n );
    for( int i = 0; i < n; i++ ) {
      cin >> x[ i ] >> y[ i ];
    }
    cout << f( x )+f( y ) << "\n";
  }

  return 0;
}