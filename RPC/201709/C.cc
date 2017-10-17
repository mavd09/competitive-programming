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

const int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
const int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

int tc;
int n, m;
char b[ MAXN ][ MAXN ];
int seen[ MAXN ][ MAXN ];
int nc;
int val[ MAXN*MAXN ], id[ MAXN ][ MAXN ];

bool is_valid( int x, int y ) {
  return 0 <= x && x <= n+1 && 0 <= y && y <= m+1;
}

int bfs( int x, int y ) {
  int r = 0;
  queue< int > q;
  q.push( x ); q.push( y );
  seen[x][y] = tc;
  while( !q.empty() ) {
    x = q.front(); q.pop();
    y = q.front(); q.pop();
    r += (b[x][y] == '#');
    for( int d = 0; d < 8; ++d ) {
      int nx = x+dx[d], ny = y+dy[d];
      if( is_valid( nx, ny ) && seen[nx][ny] != tc && b[nx][ny] != '*' ) {
        seen[nx][ny] = tc;
        q.push(nx); q.push(ny);
      } else if( b[nx][ny] == '*' ) {
        seen[nx][ny] = tc;
      }
    }
  }
  return r;
}

void mark( int x, int y ) {
  queue< int > q, p;
  q.push( x ); q.push( y );
  seen[x][y] = tc;
  int t = 0;
  while( !q.empty() ) {
    x = q.front(); q.pop();
    y = q.front(); q.pop();
    p.push( x ); p.push( y );
    t += (b[x][y] == '#');
    for( int d = 0; d < 8; ++d ) {
      int nx = x+dx[d], ny = y+dy[d];
      if( is_valid( nx, ny ) && seen[nx][ny] != tc && b[nx][ny] != '*' ) {
        seen[nx][ny] = tc;
        q.push(nx); q.push(ny);
      }
    }
  }
  val[ nc ] = t;
  while( !p.empty() ) {
    x = p.front(); p.pop();
    y = p.front(); p.pop();
    id[x][y] = nc;
  }
  nc++;
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

  for( tc = 1; cin >> n >> m; ++tc ) {
    for( int i = 0; i <= n+1; ++i ) {
      for( int j = 0; j <= m+1; ++j ) {
        if( i == 0 || j == 0 || i == n+1 || j == m+1 ) b[i][j] = '.';
        else cin >> b[i][j];
      }
    }
    nc = 1;
    memset( id, 0, sizeof(id) );
    int ans = bfs( 0, 0 );
    for( int i = 1; i <= n; ++i ) {
      for( int j = 1; j <= m; ++j ) {
        if( seen[i][j] != tc && b[i][j] == '#' ) {
          mark( i, j );
        }
      }
    }
    int mx = 0;
    for( int i = 1; i <= n; ++i ) {
      for( int j = 1; j <= m; ++j ) {
        if( b[i][j] == '*' && seen[i][j] == tc ) {
          int cur = 0;
          set< int > s;
          for( int d = 0; d < 8; ++d ) {
            int ni = i+dx[d], nj = j+dy[d];
            s.insert( id[ni][nj] );
          }
          for( auto& e : s ) {
            cur += val[ e ];
          }
          mx = max( mx, cur );
        }
      }
    }
    cout << ans+mx << '\n';
  }

  return 0;
}

