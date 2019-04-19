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

const int MAXN = int( 2e3 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

const int dx[ ] = { 0, 1, 0, -1 };
const int dy[ ] = { 1, 0, -1, 0 };

int n, m;
string b[ MAXN ];
int ans[ 4 ];
int color[ MAXN ][ MAXN ];
bool ok[ MAXN ][ MAXN ];

bool is_valid( int x, int y ) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void mark( char tp, int x, int y, int d ) {
  b[ x ][ y ] = tp;
  int nx = x+dx[ d ], ny = y+dy[ d ];
  if( !is_valid( nx, ny ) || b[ nx ][ ny ] != 'X' ) {
    d = -1;
    for( int k = 0; k < 4; ++k ) {
      if( (k^1) == d ) {
        continue;
      }
      nx = x+dx[ k ]; ny = y+dy[ k ];
      if( is_valid( nx, ny ) && b[ nx ][ ny ] == 'X' ) {
        d = k;
        break;
      }
    }
    if( d != -1 ) {
      mark( tp, nx, ny, d );
    }
  } else {
    mark( tp, nx, ny, d );
  }
}

void mark_invalid( char tp ) {
  memset( ok, true, sizeof( ok ) );
  queue< int > q;
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      if( ( i == 0 || j == 0 || i == n-1 || j == m-1 ) && b[ i ][ j ] == '.' ) {
        q.push( i );
        q.push( j );
        ok[ i ][ j ] = false;
      }
    }
  }
  while( !q.empty( ) ) {
    int x = q.front( ); q.pop( );
    int y = q.front( ); q.pop( );
    for( int k = 0; k < 4; ++k ) {
      int nx = x+dx[ k ], ny = y+dy[ k ];
      if( is_valid( nx, ny ) && b[ nx ][ ny ] != tp && ok[ nx ][ ny ] ) {
        q.push( nx );
        q.push( ny );
        ok[ nx ][ ny ] = false;
      }
    }
  }
}

void go( char tp, int x, int y, int c ) {
  int d = -1;
  for( int k = 0; k < 4; ++k ) {
    int nx = x+dx[ k ], ny = y+dy[ k ];
    if( is_valid( nx, ny ) && b[ nx ][ ny ] == 'X' ) {
      d = k;
    }
  }
  mark( tp, x, y, d );
  mark_invalid( tp );
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < m; ++j ) {
      if( ok[ i ][ j ] ) {
        color[ i ][ j ] |= c;
      }
      if( b[ i ][ j ] == tp ) {
        b[ i ][ j ] = 'X';
      }
    }
  }
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  while( cin >> n >> m ) {
    memset( ans, 0, sizeof( ans ) );
    memset( color, 0, sizeof( color ) );
    int ax, bx, ay, by;
    for( int i = 0;  i < n; ++i ) {
      cin >> b[ i ];
      for( int j = 0; j < m; ++j ) {
        if( b[ i ][ j ] == 'A' ) {
          ax = i, ay = j;
          b[ i ][ j ] = 'X';
        }
        if( b[ i ][ j ] == 'B' ) {
          bx = i; by = j;
          b[ i ][ j ] = 'X';
        }
      }
    }
    go( 'A', ax, ay, 1 );
    go( 'B', bx, by, 2 );
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        if( b[ i ][ j ] == '.' ) {
          ans[ color[ i ][ j ] ]++;
        }
      }
    }
    cout << ans[ 1 ] << ' ' << ans[ 2 ] << ' ' << ans[ 3 ] << '\n';
  }

  return 0;
}