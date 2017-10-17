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

const int MAXN = int( 2e6 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

ll bin_pow( ll b, int e ) {
  ll r = 1;
  while( e ) {
    if( e&1 ) {
      r = r*b;
    }
    b = b*b;
    e /= 2;
  }
  return r;
}

vll primes;

void sieve( ) {
  bitset< MAXN > is_prime;
  is_prime.set( );
  is_prime[ 0 ] = is_prime[ 1 ] = 0;
  for( ll i = 2; i*i < MAXN; i++ ) {
    if( is_prime[ i ] ) {
      for( ll j = i*i; j < MAXN; j += i ) {
        is_prime[ j ] = 0;
      }
    }
  }
  for( int i = 0; i < MAXN; i++ ) {
    if( is_prime[ i ] ) {
      primes.PB( i );
    }
  }
}

ll sum_divisors( ll n ) {
  ll r = 1, x = n;
  for( auto& prime : primes ) {
    if( prime*prime > n ) {
      break;
    }
    ll p = 1;
    while( n%prime == 0 ) {
      n /= prime;
      p++;
    }
    r = r*( ( bin_pow( prime, p )-1 )/( prime-1 ) );
  }
  if( n != 1 ) {
    r = r*( ( bin_pow( n, 2 )-1 )/( n-1 ) );
  }
  return r-x;
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

  sieve( );

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    ll n; cin >> n;
    ll sum = sum_divisors( n );
    if( sum < n ) cout << "deficient\n";
    else if( sum > n ) cout << "abundant\n";
    else cout << "perfect\n";
  }

  return 0;
}