#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <algorithm>
#include <limits.h>
#include <iomanip>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cassert>

#include <complex>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< vb >        vvb;
typedef vector< lf >        vd;
typedef vector< vd >        vvd;
typedef vector< vvd >       vvvd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;
typedef vector< vvi >       vvvi;
typedef vector< vvvi >      vvvvi;
typedef vector< pii >       vpii;
typedef vector< vpii >      vvpii;

typedef complex< lf >       pt;

const int MX  = 123;
const ll  mod = 1000000007LL;
const int oo  = int( 2e9 );

ll fpow( ll b, int e ) {
  ll r = 1;
  while( e ) {
    if( e&1 ) {
      r = ( r*b )%mod;
    }
    b = ( b*b )%mod;
    e /= 2;
  }
  return r;
}

ll two = fpow( 2, mod-2 );

ll g( ll x ) {
  x %= mod;
  return ( ( x*( x+1 ) )%mod * two )%mod;
}

vi sieve( const ll mx ) {
  bitset< 1000010 > is_prime; is_prime.set( );
  is_prime[ 0 ] = is_prime[ 1 ] = 0;
  for( int i = 2; i*i < mx; i++ ) {
    if( is_prime[ i ] ) {
      for( int j = i*i; j < mx; j += i ) {
        is_prime[ j ] = 0;
      }
    }
  }
  vi primes;
  for( int i = 0; i < mx; i++ ) {
    if( is_prime[ i ] ) {
      primes.PB( i );
    }
  }
  return primes;
}

vll number_decomposition( vi& primes, ll n ) {
  vll ret;
  for( auto& p : primes ) {
    bool flag = false;
    while( n%p == 0 ) {
      flag = true;
      n /= p;
    }
    if( flag ) {
      ret.PB( p );
    }
  }
  if( n != 1 ) {
    ret.PB( n );
  }
  return ret;
}

ll f( vll& nd, ll x ) {
  ll r = 0;
  int sz = int( nd.size( ) );
  for( int mask = 1; mask < ( 1<<sz ); mask++ ) {
    ll num = 1;
    for( int i = mask; i; i -= ( i&(-i) ) ) {
      int j = __builtin_ctz( i&(-i) );
      num = num*nd[ j ];
    }
    ll t = g( x/num ); num = ( num )%mod;
    t = ( t*num )%mod;
    if( __builtin_popcount( mask )%2 == 0 ) {
      r = ( r-t+mod )%mod;
    }
    else {
      r = ( r+t )%mod;
    }
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
  #endif

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  vi primes = sieve( 1000010 );

  int n_test; cin >> n_test;

  while( n_test-- ) {
    ll n, a, b; cin >> n >> a >> b;
    vll nd = number_decomposition( primes, n );
    ll ans = ( g( b )-g( a-1 )+mod )%mod;
    ans = ( ans-f( nd, b )+mod )%mod;
    ans = ( ans+f( nd, a-1LL) )%mod;
    cout << ans << "\n";
  }

  return 0;
}