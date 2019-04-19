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

const int MAXN = int( 13e5 )+1;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

vi sieve( ) {
  bitset< MAXN > is_prime; is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for( int i = 2; i*i < MAXN; ++i ) {
    if( !is_prime[i] ) continue;
    for( int j = i*i; j < MAXN; j += i ) {
      is_prime[j] = false;
    }
  }
  vi primes;
  for( int i = 0; i < MAXN; ++i ) {
    if( is_prime[i] ) {
      primes.PB(i);
    }
  }
  return primes;
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  vi primes = sieve();

  for( int a, b; cin >> a >> b; ) {
    if( a == 0 && b == 0 ) break;
    if( a > b ) swap( a, b );
    int ans = 0;
    for( int i = 1; i < SIZE(primes); ++i ) {
      if( primes[i] > b ) break;
      if( primes[i-1] >= a ) {
        ans = max( ans, primes[i]-primes[i-1] );
      }
    }
    if( ans == 0 ) {
      cout << "NULL\n";
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}

