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

int n;
ll a, b;
vll primes;

ll val[ MAXN ];
int cnt[ MAXN ];

void sieve( ) {
  bitset< MAXN > is_prime; is_prime.set();
  is_prime[0] = is_prime[1] = 0;
  for( int i = 2; i*i < MAXN; ++i ) {
    if( is_prime[i] ) {
      for( int j = i*i; j < MAXN; j += i ) {
        is_prime[j] = 0;
      }
    }
  }
  for( int i = 0; i < MAXN; ++i ) {
    if( is_prime[i] ) {
      primes.PB(i);
    }
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

  sieve();

  int n_test; cin >> n_test;
  cin >> a >> b;

  n = b-a+1LL;
  for( int i = 0; i < n; ++i ) {
    cnt[i] = 1;
    val[i] = a+i;
  }

  for( auto& p : primes ) {
    ll j = a/p * p;
    while( j < a ) j += p;
    for( ; j <= b; j += p ) {
      int t = 1, idx = j-a;
      while( val[ idx ]%p == 0 ) {
        t++;
        val[ idx ] /= p;
      }
      cnt[ idx ] *= t;
    }
  }

  for( int i = 0; i < n; ++i ) {
    if( val[ i ] != 1 ) {
      cnt[ i ] *= 2;
    }
  }

  for( int tc = 1; n_test--; ++tc ) {
    ll d; cin >> d;
    int ans = 0;
    for( int i = 0; i < n; ++i ) {
      ll cur = a+i;
      if( cur%d == 0 ) {
        int p = 1;
        while( cur%d == 0 ) {
          cur /= d;
          p++;
        }
        ans += cnt[i]/p;
      } else {
        ans += cnt[i];
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

