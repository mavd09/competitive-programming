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

const int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
const int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int n, m;
int board[ MAXN ][ MAXN ];
bool seen[ MAXN ][ MAXN ];

void mark( int f, int t, int x, int y ) {
  if( seen[x][y] ) return ;
  seen[x][y] = true;
  for( int i = f; i <= t; ++i ) {
    if( board[ x+dx[i] ][ y+dy[i] ] ) {
      mark( f, t, x+dx[i], y+dy[i] );
    }
  }
}

int doit( int f, int t ) {
  int ans = 0;
  memset( seen, false, sizeof(seen) );
  for( int i = 1; i <= n; ++i ) {
    for( int j = 1; j <= m; ++j ) {
      if( !seen[i][j] && board[i][j] ) {
        ans++;
        mark( f, t, i, j );
      }
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
  
  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; ++tc ) {
    cin >> m >> n;
    for( int i = 0; i <= n+1; ++i ) {
      for( int j = 0; j <= m+1; ++j ) {
        if( i == 0 || i == n+1 || j == 0 || j == m+1 ) {
          board[i][j] = 0;
        } else {
          char x; cin >> x;
          board[i][j] = x-'0';
        }
      }
    }
    cout << doit( 0, 3 ) << ' ';
    cout << doit( 4, 7 ) << ' ';
    cout << doit( 0, 7 ) << '\n';
  }

  return 0;
}

