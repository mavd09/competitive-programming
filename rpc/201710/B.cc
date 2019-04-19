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

const int MAXN = int( 1e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int arr[ MAXN ];

int tc;
int seen[ MAXN ][ MAXN ][ 2 ];
int dp[ MAXN ][ MAXN ][ 2 ];

int go( int i, int j, int p ) {
  if( i > n ) return 0;
  int& r = dp[i][j][p];
  if( seen[i][j][p] == tc ) return r;
  seen[i][j][p] = tc;
  r = go( i+1, j, p );
  if( p == 0 ) {
    if( j == 0 ) {
      r = max( r, go( i+1, i, 0 )+1 );
    }
    if( j && arr[i] > arr[j] ) {
      r = max( r, go( i+1, i, 0 )+1 );
    }
    if( j && arr[i] < arr[j] ) {
      r = max( r, go( i+1, i, 1 )+1 );
    }
  } else {
    if( arr[i] < arr[j] ) {
      r = max( r, go( i+1, i, 1 )+1 );
    }
  }
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

  int n_test; cin >> n_test;

  for( tc = 1; tc <= n_test; ++tc ) {
    cin >> n;
    for( int i = 1; i <= n; ++i ) {
      cin >> arr[ i ];
    }
    cout << go( 1, 0, 0 ) << '\n';
  }

  return 0;
}

