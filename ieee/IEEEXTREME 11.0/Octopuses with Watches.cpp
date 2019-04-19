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

const int MAXN = 10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m;
int b[ MAXN ][ MAXN ];

int r[ MAXN ], c[ MAXN ];

int f( int mask ) {
  for( int i = 0; i < n; ++i ) {
    r[i] = mask%3;
    mask /= 3;
  }
  for( int i = 0; i < m; ++i ) {
    c[i] = mask%3;
    mask /= 3;
  }
  int ans = 0;
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      int val = (b[i][j]+r[i]+c[j])%3;
      if( val == 0 ) ans++;
    }
  }
  return ans;
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

  srand( time(NULL) );

  cin >> n >> m;
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      cin >> b[i][j];
      b[i][j] = (b[i][j]-1)%3;
    }
  }

  int mx = 1;
  for( int i = 1; i <= n+m; ++i ) {
    mx *= 3;
  }

  int ans = 0;
  for( int it = 0; it < 3e6; ++it ) {
    ans = max( ans, f(rand()%mx) );
  }
  cout << ans << '\n';

  return 0;
}

