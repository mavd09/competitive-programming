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

const int MAXN = int( 1e6 )+10;
const ll MOD  = ll( 1e9 )+7;
const int oo   = INT_MAX;

inline int add( int a, int b ) { return ( a+b >= MOD ? a+b-MOD : a+b ); }
inline int subt( int a, int b ) { return ( a-b < 0 ? a-b+MOD : a-b ); }

ll n, k;

vll prime;
bitset< MAXN > is_prime;

void sieve( ) {
  is_prime.set( );
  is_prime[ 0 ] = is_prime[ 1 ] = 0;
  for( int i = 2; i*i < MAXN; ++i ) {
    if( is_prime[ i ] ) {
      for( int j = i*i; j < MAXN; j += i ) {
        is_prime[ j ] = 0;
      }
    }
  }
  for( int i = 0; i < MAXN; ++i ) {
    if( is_prime[ i ] ) {
      prime.PB( i );
    }
  }
}

ll f( ll n ) {
  if( n < MAXN && is_prime[ n ] ) {
    return n-1;
  }
  ll ans = (n-1+MOD)%MOD;
  for( ll i = 2; i*i <= n; ++i ) {
    if( n%i == 0 ) {
      ans = subt( ans, f( i ) );
      while( n%i ) {
        n /= i;
      }
    }
  }
  return ans;
}

ll solve( ll n, ll k ) {
  if( n == 1 ) {
    return 1;
  }
  if( k == 0 ) {
    return n;
  }
  return solve( f( n ), k-1 );
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "attack.in", "r", stdin );
    //freopen( "attack.out", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  sieve( );

  while( cin >> n >> k ) {
    cout << solve( n, (k+1LL)/2LL ) << '\n';
  }

  return 0;
}