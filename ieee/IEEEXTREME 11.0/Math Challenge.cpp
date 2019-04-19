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
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int t, a, b, c;
int fact[ MAXN ], ifact[ MAXN ]; 

const int mul( int a, int b, int mod ) { return ll(a)*ll(b) % ll(mod); }

int mod_pow( int b, int e, int mod ) {
  int r = 1;
  while( e > 0 ) {
    if( e&1 ) {
      r = mul( r, b, mod );
    }
    b = mul( b, b, mod );
    e >>= 1;
  }
  return r;
}

vi sieve( ) {
  bitset< MAXN > is_prime; is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for( int i = 2; i*i < MAXN; ++i ) {
    if( is_prime[i] ) {
      for( int j = i*i; j < MAXN; j += i ) {
        is_prime[j] = 0;
      }
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

vi primes;
int cnt[ MAXN ];

void f( int n, int sgn ) {
  for( auto& p : primes ) {
    int t = 0;
    for( ll i = p; i <= n; i *= ll(p) ) {
      t += n/i;
    }
    cnt[ p ] += sgn*t;
  }
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

  primes = sieve();
  
  cin >> t;

  while( t-- ){
    cin >> a >> b >> c;
    memset( cnt, 0, sizeof(cnt) );
    f(b,1); f(b-c,-1); f(c,-1);
    int e = 1;
    for( int i = 0; i < MAXN; ++i ) {
      if( cnt[i] == 0 ) continue;
      e = mul( e, mod_pow(i,cnt[i],MOD-1), MOD-1 );
    }
    cout << mod_pow( a, e, MOD ) << '\n';
  }

  return 0;
}

