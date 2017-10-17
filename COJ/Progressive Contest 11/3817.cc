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

const int MAXN = int( 1e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

ll mod_mul( ull a, ull b, ull mod ) {
  ll x = 0, y = a%mod;
  while( b > 0 ) {
    if( b&1 ) {
      x = x+y;
      x = ( x > mod ? x-mod : x );
    }
    y = y*2LL;
    y = ( y > mod ? y-mod : y );
    b >>= 1;
  }
  return x;
}

ll mod_pow( ll a, ll e, ll mod ) {
  ll r = 1;
  while( e > 0 ) {
    if( e&1 )
      r = mod_mul( r, a, mod );
    a = mod_mul( a, a, mod );
    e >>= 1;
  }
  return r;
}

// checks whether a is a witness that n is not prime, 1 < a < n
bool witness( ll a, ll n ) {
  // check as in Miller Rabin Primality Test described
  ll u = n-1;
  int t = 0;
  while( !( u&1 ) ) {
    t++;
    u >>= 1;
  }
  ll next = mod_pow( a, u, n );
  if( next == 1 ) return false;
  ll last;
  for( int i = 0; i < t; ++i ) {
    last = next;
    next = mod_mul( last, last, n );
    if( next == 1 )
      return ( last != n - 1 );
  }
  return next != 1;
}

// Checks if a number is prime with prob 1 - 1 / (2 ^ it)
bool miller_rabin( ll n, int it = 20 ) {
  if( n <= 1 ) return false;
  if( n == 2 ) return true;
  if( n%2 == 0 ) return false;
  for( int i = 0; i < it; ++i ) {
    ll a = rand( )%( n-1 ) + 1;
    if( witness( a, n ) )
      return false;
  }
  return true;
}

ll pollard_rho( ll n ) {
  ll x, y, i = 1, k = 2, d;
  x = y = rand( )%n;
  while( true ) {
    ++i;
    x = mod_mul( x, x, n );
    x += 2;
    if( x >= n ) x -= n;
    if( x == y ) return 1;
    d = __gcd( abs( x-y ), n );
    if( d != 1 ) return d;
    if( i == k ) {
      y = x;
      k *= 2;
    }
  }
  return 1;
}

vll factorize( ll n ) {
  vll ans;
  if( n == 1 )
    return ans;
  if( miller_rabin( n ) )
    ans.PB( n );
  else {
    ll d = 1;
    while( d == 1 ) d = pollard_rho( n );
    vll dd = factorize( d );
    ans = factorize( n/d );
    for( int i = 0; i < SIZE( dd ); i++ )
      ans.PB( dd[ i ] );
  }
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

  int n_test;
  cin >> n_test;

  while( n_test-- ) {
    ll n; cin >> n;
    vll ans = factorize( n );
    sort( ALL( ans ) );
    cout << ans[ 0 ];
    for( int i = 1; i < SIZE( ans ); i++ )
      cout << " " << ans[ i ];
    cout << "\n";
  }

  return 0;
}