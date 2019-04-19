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

int pascal[ 20 ][ 20 ];

int color;
int seen[ 20 ][ MAXN ];
int dp[ 20 ][ MAXN ];

inline int add( int a, int b ) { return ( a+b >= MOD ? a+b-MOD : a+b ); }

int go( int sum, int x, int y ) {
  if( x == y ) return 1;
  int& ways = dp[y][sum];
  if( seen[y][sum] == color ) return ways;
  seen[y][sum] = color;
  ways = go(sum, x, y+1);
  if( sum-pascal[x][y] >= 0 ) {
    ways = add( ways, go(sum-pascal[x][y], x, y) );
  }
  return ways;
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

  pascal[0][0] = 1;
  for( int i = 1; i < 20; ++i ) {
    pascal[i][0] = pascal[i][i] = 1;
    for( int j = 1; j < i; ++j ) {
      pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
    }
  }

  int s; cin >> s;

  int ans = 0;
  for( int i = 0; ; ++i ) {
    if( (1<<i) > s ) break;
    color++;
    ans = add( ans, go(s-(1<<i),i,0) );
  }
  cout << ans << '\n';

  return 0;
}

