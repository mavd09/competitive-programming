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

const int MAXN = int( 6e2 )+10;
const int MOD  = int( 1e9 )+7;
const lf  oo   = 1e15;

const lf EPS = 1e-9;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int cmp( lf x, lf y ) {
  if( x+EPS < y ) return -1;
  if( y+EPS < x ) return 1;
  return 0;
}

struct State { lf d; int x, y, p; };
struct Cmp_State {
  bool operator () ( const State& a, const State& b ) {
    return cmp( a.d, b.d ) > 0;
  }
};

int n, m, p;
int x[ MAXN ], y[ MAXN ];
lf r[ MAXN ][ MAXN ], h[ MAXN ][ MAXN ];

lf min_dist[MAXN][MAXN][4];

bool is_valid( int x, int y ) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void init( ) {
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      for( int k = 0; k < 4; ++k ) {
        min_dist[i][j][k] = oo;
      }
    }
  }
}

lf go( int fx, int fy, int tx, int ty ) {
  init();
  priority_queue< State, vector<State>, Cmp_State > pq;
  for( int k = 0; k < 4; ++k ) {
    min_dist[fx][fy][k] = 0;
    pq.push( {min_dist[fx][fy][k], fx, fy, k} );
  }
  while( !pq.empty() ) {
    State cur = pq.top(); pq.pop();
    int x = cur.x, y = cur.y, p = cur.p;
    if( x == tx && y == ty ) return min_dist[tx][ty][p];
    if( cmp( cur.d, min_dist[x][y][p] ) != 0 ) continue;
    for( int k = 0; k < 4; ++k ) {
      int nx = x+dx[k], ny = y+dy[k];
      if( !is_valid( nx, ny ) ) continue;
      lf cost = min_dist[x][y][p] + (r[x][y]+r[nx][ny])/2.0*exp(3.5*abs( (h[nx][ny]-h[x][y])/10.0+0.05 ));
      if( cmp( cost, min_dist[nx][ny][k] ) < 0 ) {
        min_dist[nx][ny][k] = cost;
        pq.push( {cost, nx, ny, k} );
      }
    }
  }
  return -1.0;
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

  cin >> n >> m;
  cin >> p;
  for( int i = 0; i <= p; ++i ) {
    cin >> x[i] >> y[i];
  }
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      cin >> r[i][j];
    }
  }
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      cin >> h[i][j];
    }
  }

  lf ans = 0;
  for( int i = 0; i < p; ++i ) {
    ans += go( x[i], y[i], x[i+1], y[i+1] );
  }

  cout << ll( ceil(ans) ) << '\n';

  return 0;
}

