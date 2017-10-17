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

vll primes;
int ways[ MAXN ];

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

ll euler_phi( ll n ) {
  ll r = n;
  for( auto& prime : primes ) {
    if( prime*prime > n ) {
      break;
    }
    if( n%prime == 0 ) {
      r = r-( r/prime );
    }
    while( n%prime == 0 ) {
      n /= prime;
    }
  }
  if( n != 1 ) {
    r = r-( r/n );
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

  sieve( );

  ways[ 1 ] = ways[ 2 ] = 1;
  for( int i = 3; i < MAXN; i++ ) {
    ways[ i ] = euler_phi( i );
  }

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    int n; cin >> n;
    cout << ways[ n ] << "\n";
  }

  return 0;
}