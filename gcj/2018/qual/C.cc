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
const int oo   = INT_MAX;

const int dx[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
const int dy[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

void print( int x, int y ) {
  printf( "%d %d\n", x, y );
  fflush( stdout );  
}

int f( int fx, int fy, int tx, int ty ) {
  for( int i = 0; i < 9; ++i ) {
    if( fx+dx[i] == tx && fy+dy[i] == ty ) {
      return i;
    }
  }
  assert( false );
}

vi find_cycle( ) {
  int x, y;
  vi c;
  print( 500, 500 ); 
  scanf( "%d %d", &x, &y );
  c.PB( f(500,500,x,y) );
  cerr << c[0];
  for( int it = 1000; it > 0; --it  ) {
    print( 500, 500 );
    scanf( "%d %d", &x, &y );
    int val = f(500,500,x,y);
    //if( val == c[0] ) break;
    c.PB( val );
    cerr << val;
  }
  cerr << endl;
  return c;
}

int main( ) {

#ifdef LOCAL
  //freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  int mn_x = 490, mx_x = 510;
  int mn_y = 490, mx_y = 510;

  int n_test; n_test = scanf( "%d", &n_test );

  for( int tc = 1; n_test--; ++tc ) {
    int a, x, y;
    scanf( "%d", &a );
    vi v = find_cycle();
    int idx = 1;
    for( int i = mn_x; i <= mx_x; ++i ) {
      for( int j = mn_y; j <= mx_y; ++j ) {
        idx %= v.size();
        print( i-dx[v[idx]], j-dy[v[idx]] );
        idx = (idx+1)%v.size();
        scanf( "%d %d", &x, &y );
      }
    }
  }

  return 0;
}

