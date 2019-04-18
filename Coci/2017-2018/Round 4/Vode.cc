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

const int MAXN = int( 1e4 )+10;
const int MAXM = int( 5e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m, k;
int arr[ MAXN ];

int dp[ MAXN ][ MAXM ];

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d%d%d", &n, &m, &k ) == 3 ) {
    for( int i = 0; i < n; ++i ) {
      scanf( "%d", &arr[i] );
    }
    for( int i = n; i < MAXN; ++i ) {
      arr[i] = arr[ i%n ];
    }
    memset( dp, 0, sizeof(dp) );
    // base case
    for( int i = MAXN-1; i > 0; --i ) {
      dp[ i ][ m ] = ( arr[i] != arr[i-1] );
    }
    for( int j = m-1; j >= 0; --j ) {
      for( int i = MAXN-2; i >= 0; --i ) {
        int l = j+1, r = min(m,j+k);
        if( arr[i+1] != arr[i] ) {
          dp[i][j] = ( dp[i+1][l]-dp[i+1][r+1] != r-l+1 );
        } else {
          dp[i][j] = ( dp[i+1][l]-dp[i+1][r+1] != 0 );
        }
        dp[i][j] += dp[i][j+1];
      }
    }
    for( int i = 0; i < n; ++i ) {
      dp[i][0] -= dp[i][1];
      printf( "%d%c", dp[i][0]^arr[i]^1, " \n"[i+1==n] );
    }
  }

  return 0;
}

