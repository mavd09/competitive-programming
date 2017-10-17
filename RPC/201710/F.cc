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

const int MAXN = 40;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int n, m;
char board[ MAXN ][ MAXN ];

int seen[ MAXN ][ MAXN ];

bool is_valid( int x, int y ) {
  return 0 <= x && x < n && 0 <= y && y < m;
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

  for( int tc = 1; tc <= n_test; ++tc ) {
    cin >> n >> m;
    queue< int > q;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        cin >> board[i][j];
        if( i == 0 || j == 0 || i == n-1 || j == m-1 ) {
          if( board[i][j] == '0' ) {
            seen[i][j] = tc;
            q.push( i ); q.push(j);
          }
        }
      }
    }
    int ans = 0;
    while( !q.empty() ) {
      int x = q.front(); q.pop();
      int y = q.front(); q.pop();
      ans++;
      for( int d = 0; d < 4; ++d ) {
        int nx = x+dx[d], ny = y+dy[d];
        if( is_valid(nx,ny) && seen[nx][ny] != tc && board[nx][ny] == '0' ) {
          seen[nx][ny] = tc;
          q.push(nx); q.push(ny);
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

