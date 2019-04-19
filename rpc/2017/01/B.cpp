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

const int MAXN = int( 50 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

const int dx[ ] = { 1, 1, -1, -1 };
const int dy[ ] = { 1, -1, 1, -1 };

int n;
int ans = 0, cnt = 0;
int cntp[ 2 ];
int board[ MAXN ][ MAXN ];

bool go( int x, int y ) {
  int t = board[ x ][ y ];
  if( cntp[ 1-t ] == cnt )
    return true;
  bool r = false;
  for( int i = 0; i < 4; i++ ) {
    int nx = x+2*dx[ i ], ny = y+2*dy[ i ];
    int a = x+dx[ i ], b = y+dy[ i ];
    if( 0 <= nx && nx < n && 0 <= ny && ny < n && board[ nx ][ ny ] == 2 && board[ a ][ b ] == 1-t ) {
      board[ x ][ y ] = 2;
      board[ a ][ b ] = 2;
      board[ nx ][ ny ] = t;
      cnt++;
      r |= go( nx, ny );
      cnt--;
      board[ x ][ y ] = t;
      board[ a ][ b ] = 1-t;
      board[ nx ][ ny ] = 2;
    }
    if( r ) break;
  }
  return r;
}

string to_str( int x ) {
  stringstream ss;
  ss << x;
  return ss.str( );
}

string get_pos( int x, int y ) {
  //cout << x << " " << y << endl;
  return string( 1, y+'a' )+to_str( n-x );
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

  while( cin >> n ) {
    cnt = cntp[ 0 ] = cntp[ 1 ] = 0;
    for( int i = 0; i < n; i++ ) {
      string line; cin >> line;
      for( int j = 0; j < n; j++ ) {
        if( line[ j ] == '_' || line[ j ] == '.' )
          board[ i ][ j ] = 2;
        else {
          board[ i ][ j ] = ( line[ j ] == 'W' );
          cntp[ 0 ] += ( line[ j ] == 'B' );
          cntp[ 1 ] += ( line[ j ] == 'W' );
        }
      }
    }
    ans = 0;
    int x, y;
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < n; j++ ) {
        if( board[ i ][ j ] == 0 && go( i, j ) ) {
          x = i; y = j;
          ans++;
        }
        if( ans >= 2 ) break;
      }
      if( ans >= 2 ) break;
    }
    if( ans == 0 ) cout << "None\n";
    if( ans >= 2 ) cout << "Multiple\n";
    if( ans == 1 ) cout << get_pos( x, y ) << "\n";
  }

  return 0;
}
