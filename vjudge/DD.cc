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
const int oo   = 1e7;

int n, m;
int mi;
int a[ MAXN ], b[ MAXN ];

bool seen[ 110 ][ 110 ];
int dp[ 110 ][ 110 ];

int go( int i, int x ) {
  if( i == n ) {
    if( x == 0 ) return 0;
    return -oo;
  }
  int& r = dp[i][x];
  if( seen[i][x] ) return r;
  seen[i][x] = true;
  r = -oo;
  for( int aa = 0; aa*a[i] <= mi && aa <= x; ++aa ) {
    r = max( r, go( i+1, x-aa )+( mi-aa*a[i] )/b[i] );
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

  for( int tc = 1; n_test--; ++tc ) {
    cin >> n >> m;
    for( int i = 0; i < n; ++i ) {
      cin >> a[i] >> b[i];
    }
    int lo = 0, hi = 50000;
    while( lo < hi ) {
      mi = (lo+hi)>>1;
      memset( seen, false, sizeof(seen) );
      if( go( 0, m ) < m ) lo = mi+1;
      else hi = mi;
    }
    cout << "Case " << tc << ": " << lo << '\n'; 
  }

  return 0;
}

