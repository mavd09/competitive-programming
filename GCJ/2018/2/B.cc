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

const int MAXN = 510;
const int MAXR = 35;
const int MOD  = int( 1e9 )+7;
const int oo   = 1e8;

int best[ MAXR ];
int dp[ MAXN ][ MAXN ][ MAXR ];

int cnt = -1;

int go( int x, int y, int r ) {
  cnt++;
  if( r == MAXR ) {
//    cout << string(2*cnt,'.') << "(" << x << "," << y << "," << r << ") = " << 0 << endl;
    cnt--;
    return 0;
  }
//  if( r > x ) return 0;
  int& ans = dp[x][y][r];
  if( ans != -1 ) {
//    cout << string(2*cnt,'.') << "(" << x << "," << y << "," << r << ") = " << ans << "!" << endl;
    cnt--;
    return ans;
  }
  ans = go(x, y,r+1);
  if( r == 0 ) {
    for( int i = 1; i < MAXR; ++i ) {
      if( best[i] > y || i*r > x ) break;
      ans = max( ans, go( x-i*r, y-best[i], r+1 )+i );
    }
  } else {
    for( int i = 0; i < MAXR; ++i ) {
      if( best[i] > y || (i+1)*r > x ) break;
      ans = max( ans, go( x-(i+1)*r, y-best[i], r+1 )+i+1 );
    }
  }
//  cout << string(2*cnt,'.') << "(" << x << "," << y << "," << r << ") = " << ans << endl;
  cnt--;
  return ans;
}

int main( ) {

  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );

  memset( dp, -1, sizeof(dp) );

  best[0] = 0;
  for( int i = 1; i < MAXR; ++i ) {
    best[i] = best[i-1]+i;
  }

  int n_test; scanf( "%d", &n_test );

  for( int tc = 1; n_test--; ++tc ) {
    int r, b; scanf( "%d %d", &r, &b );
    printf( "Case #%d: %d\n", tc, go(r,b,0) );
  }

  return 0;
}

