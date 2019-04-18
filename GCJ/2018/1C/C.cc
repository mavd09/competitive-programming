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
const int MAXL = 610;
const int MOD  = int( 1e9 )+7;
const ll  oo   = ll(1e14);

int tc;
int N;
int W[ MAXN ];

ll dp[ 2 ][ MAXN ];

int main( ) {

  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );

  int n_test; scanf( "%d", &n_test );

  for( tc = 1; n_test--; ++tc ) {
    scanf( "%d", &N );
    for( int i = 0; i < N; ++i ) {
      scanf( "%d", &W[i] );
    }
    int idx = 0;
    dp[idx][0] = W[idx];
    for( int i = 1; i < N; ++i ) {
      dp[idx][i] = min( 1LL*W[i], dp[idx][i-1] );
    }
    int ans = 1;
    while( ans < N ) {
      idx ^= 1;
      bool flag = false;
      for( int i = 0; i < ans; ++i ) dp[idx][i] = oo;
      for( int i = ans; i < N; ++i ) {
        dp[idx][i] = dp[idx][i-1];
        if( dp[idx^1][i-1] <= 6LL*W[i] ) {
          dp[idx][i] = min( dp[idx][i], W[i]+dp[idx^1][i-1] );
          flag = true;
        }
      }
      if( !flag ) break;
      ans++;
    }
    printf( "Case #%d: %d\n", tc, ans );
  }

  return 0;
}
