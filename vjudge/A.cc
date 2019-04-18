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

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
vi graph[ MAXN ];

int dp[ 2 ][ MAXN ];

inline int mul( int a, int b ) { return ll(a)*ll(b) % ll(MOD); }
int mod_pow( int b, int e ) {
  int r = 1;
  while( e ) {
    if( e&1 ) r = mul( r, b );
    b = mul( b, b );
    e >>= 1;
  }
  return r;
}
inline int add( int a, int b ) { return ( a+b >= MOD ? a+b-MOD : a+b ); }
inline int inv( int a ) { return mod_pow( a, MOD-2 ); }
inline int dvs( int a, int b ) { return mul( a, inv(b) ); }

void dfs_up( int u, int p = -1 ) {
  int a = 1, b = 1;
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    dfs_up( v, u );
    a = mul( a, dp[0][v] );
    b = mul( b, dp[1][v] );
  }
  dp[0][u] = a; dp[1][u] = b;
}

void dfs_down( int u, int p = -1 ) {
  if( p != -1 ) {
    int x = mul( dp[0][u], dp[1][u] );
    dp[0][u] = add( dvs( dp[0][p], dp[0][u] ), x );
    dp[1][u] = add( dvs( dp[1][p], dp[1][u] ), x );
  }
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    dfs_down( v, u );
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

  while( cin >> n ) {
    for( int i = 1; i < n; ++i ) {
      int u, v; cin >> u >> v; u--; v--;
      graph[ u ].PB( v );
      graph[ v ].PB( u );
    }
    dfs_up( 0 );
    dfs_down( 0 );
    int ans = 0;
    for( int i = 0; i < n; ++i ) {
      ans = add( ans, dp[1][i] );
    }
    cout << ans << endl;
  }

  return 0;
}

