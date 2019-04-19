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
typedef double              lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 5e2 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int t,c,n;
int w[MAXN], f[MAXN];
int dp[ MAXN ][ MAXN ];

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
  cin >> t;
  while( t-- ) {
    cin >> c >> n;
    for( int i = 1; i <= n; ++i ) {
      cin >> w[i] >> f[i];
      for( int j = 0; j <= c; ++j ) {
        dp[i][j] = dp[i-1][j];
        if( j-w[i] >= 0 ) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+f[i] );
        }
      }
    }
    cout << dp[n][c] << '\n';
  }

  return 0;
}
