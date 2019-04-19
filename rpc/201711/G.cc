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

const int MAXN = int( 2e2 )+10;
const int MAXP = int( 2e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m, p1, p2;

inline int add( int a, int b ) { return (a+b >= MOD ? a+b-MOD : a+b); }
inline int mul( int a, int b ) { return ll(a)*ll(b) % ll(MOD); }

int dp[ MAXN ][ MAXP ];
int go( int k, int p ) {
  if( k == 0 ) return p == 0;
  if( p <= 0 ) return 0;
  int& r = dp[k][p];
  if( r != -1 ) return r;
  r = 0;
  for( int j = 1; j <= m; ++j ) {
    r = add( r, go( k-1, p-j ) );
  }
  return r; 
}

int fact[ MAXN ], ifact[ MAXN ]; 

int comb( int n, int k ) {
  return mul( fact[n], mul( ifact[k], ifact[n-k] ) );
}

int f( int k1, int k2 ) {
  int w1 = mul( go( k1, p1 ), comb( n, k1 ) );
  int w2 = mul( go( k2, p2 ), comb( n-k1, k2 ) );
  int r = mul( w1, w2 );
  return r;
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

  fact[ 0 ] = 1; ifact[ 0 ] = 1;
  fact[ 1 ] = 1; ifact[ 1 ] = 1;
  for( int i = 2; i < MAXN; ++i ) {
    fact[ i ] = mul( fact[i-1], i );
    ifact[ i ] = mul( MOD-MOD/i, ifact[MOD%i] );
  }

  for( int i = 2; i < MAXN; ++i ) {
    ifact[ i ] = mul( ifact[i-1], ifact[i] );
    assert( mul(fact[i], ifact[i]) == 1 );
  }

  while( cin >> n >> m >> p1 >> p2 ) {
    int ans = 0;
    memset( dp, -1, sizeof(dp) );
    for( int k1 = 0; k1 <= n; ++k1 ) {
      for( int k2 = 0; k1+k2 <= n; ++k2 ) {
        ans = add( ans, f( k1, k2 ) );
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

