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

const int MAXN = int( 2e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = int( 2e8 );

int r, c;
int m[MAXN][MAXN];

int dist[MAXN][MAXN];

void init() {
  for( int i = 0; i < r; ++i ) {
    for( int j = 0; j < c; ++j ) {
      dist[i][j] = 0;
    }
  }
}

bool doit( int x ) {
  init();
  set< pair< int, pii > > pq;
  pq.insert( {-x, {0,0}} );
  dist[0][0] = x;
  while( !pq.empty() ) {
    pair< int, pii > cur = *pq.begin();
    int x = cur.SE.FI, y = cur.SE.SE, d = -cur.FI, nd;
    if( x == r-1 && y == c-1 ) return true;
    pq.erase( pq.begin() );
    if( d != dist[x][y] ) continue;
    nd = dist[x][y]+m[x+1][y];
    if( x+1 < r && nd > dist[x+1][y] ) {
      dist[x+1][y] = nd;
      pq.insert( {-nd, {x+1,y}} );
    }
    nd = dist[x][y]+m[x][y+1];
    if( y+1 < c && nd > dist[x][y+1] ) {
      dist[x][y+1] = nd;
      pq.insert( {-nd, {x,y+1}} );
    }
  }
  return false;
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  scanf( "%d%d", &r, &c );
  for( int i = 0; i < r; ++i ) {
    for( int j = 0; j < c; ++j ) {
      scanf( "%d", &m[i][j] );
    }
  }

  int lo = 1, hi = 4e5;
  while( lo <= hi ) {
    int mi = (lo+hi)>>1;
    if( !doit(mi) ) lo = mi+1;
    else hi = mi-1;
  }

  printf( "%d\n", lo );

  return 0;
}

