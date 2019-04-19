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

const int MAXN = int( 200 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int board[ MAXN ][ MAXN ];
vpii tokens[ 2 ];

bool is_valid( int x, int y ) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

bool check( int p, int dx, int dy, int x, int y ) {
  for( int j = 0; j < 3; ++j ) {
    x += dx; y += dy;
    if( !is_valid( x, y ) || board[x][y] != p ) {
      return false;
    }
    swap( dx, dy );
    dy = -dy;
  }
  return true; 
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

  while( cin >> n ) {
    int m = n*n;
    int ans = 0;
    memset( board, 0, sizeof(board) );
    tokens[0].clear(); tokens[1].clear();
    for( int i = 0; i < m; ++i ) {
      int x, y; cin >> x >> y;
      if( ans ) continue;
      int p = (i&1) + 1;
      board[x][y] = p;
      for( auto& e : tokens[p-1] ) {
        if( check(p,x-e.FI,y-e.SE,e.FI,e.SE) || check(p,e.FI-x,e.SE-y,x,y) ) {
          ans = p;
          break;
        }
      }
      tokens[p-1].PB( {x,y} );
    }
    cout << ans << '\n';  
  }

  return 0;
}

