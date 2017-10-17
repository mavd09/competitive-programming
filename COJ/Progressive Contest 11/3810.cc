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

int fpow( int b, int e ) {
  int r = 1;
  while( e ) {
    if( e&1 ) {
      r = ( 1LL*r*b )%ll( MOD );
    }
    b = ( 1LL*b*b )%ll( MOD );
    e /= 2;
  }
  return r;
}

ll inv( ll x ) { return fpow( x, MOD-2 ); }
ll add( int a, int b ) { return ( a+b )%MOD; }
ll sub( int a, int b ) { return ( a-b+MOD )%MOD; }
ll mul( ll a, ll b, ll mod = MOD ) { return ( a*b )%MOD; }

ll inv2 = inv( 2 );
ll inv3 = inv( 3 );

ll g1( ll n ) { return mul( mul( n, add( n, 1 ) ), inv2 ); }
ll g2( ll n ) { return mul( mul( g1( n ), add( mul( 2, n ), 1 ) ), inv3 ); }

int f( ll n ) {
  ll r = n/2 + 1;
  ll h = n-r+1;

  n %= MOD; r %= MOD; h %= MOD;

  ll sum = sub( g1( g1( r ) ), g1( g1( r-1 ) ) );
  
  ll y = mul( sub( h, 1 ), mul( r, h ) );
  y = sub( y, mul( r, g1( h-1 ) ) );
  y = add( y, mul( h, g1( h-1 ) ) );
  y = sub( y, g2( h-1 ) );

  ll ans = mul( sum, h );
  ans = add( ans, mul( r, y ) );
  return ans;
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

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    ll n; cin >> n;
    cout << "Case #" << tc << ": " << f( n ) << "\n";
  }

  return 0;
}