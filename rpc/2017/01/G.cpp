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

typedef complex< lf >       pt;

const int MAXN = int( 1e3 );
const int MOD  = int( 360 );
const int oo   = int( 1e7 );

const int dx[ ] = { 1, 0, -1, 0 };
const int dy[ ] = { 0, -1, 0, 1 };

int n, m;
string board[ MAXN ];
int min_dist[ MAXN ][ MAXN ];

void init( ) {
  for( int i = 0; i < MAXN; i++ ) {
    for( int j = 0; j < MAXN; j++ ) {
      min_dist[ i ][ j ] = oo;
    }
  }
}

int bfs( ) {
  init( );
  queue< int > q;
  q.push( 0 ); q.push( 0 );
  min_dist[ 0 ][ 0 ] = 0;
  while( !q.empty( ) ) {
    int x = q.front( ); q.pop( );
    int y = q.front( ); q.pop( );
    int d = board[ x ][ y ]-'0';
    for( int i = 0; i < 4; i++ ) {
      int nx = x+dx[ i ]*d;
      int ny = y+dy[ i ]*d;
      if( !( 0 <= nx && nx < n && 0 <= ny && ny < m ) )
        continue;
      if( min_dist[ x ][ y ]+1 < min_dist[ nx ][ ny ] ) {
        min_dist[ nx ][ ny ] = min_dist[ x ][ y ]+1;
        q.push( nx ); q.push( ny );
      }
    }
  }
  return min_dist[ n-1 ][ m-1 ];
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
    for( int i = 0; i < n; i++ ) {
      cin >> board[ i ];
    }
    int ans = bfs( );
    if( ans != oo )
      cout << ans << "\n";
    else
      cout << "IMPOSSIBLE\n";
  }

  return 0;
}
