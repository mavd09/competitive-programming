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

const int MAXN = int( 7e5 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

enum { OPEN, POINT, CLOSE };

struct Event { int t, x, y, tp, idx; };

int n, q, t;
Event events[ MAXN ];
int ans[ MAXN ];

int bit[ 2 ][ MAXN ];

bool cmp_event( const Event& e1, const Event& e2 ) {
  if( e1.t != e2.t ) {
    return e1.t < e2.t;
  }
  return e1.tp < e2.tp;  
}

void init( ) {
  t = 0;
  memset( bit, 0, sizeof( bit ) );
}

void update( int id, int i ) {
  for( ; i < MAXN; i += ( i&-i ) ) {
    bit[ id ][ i ]++;
  }
}

int query( int id, int i ) {
  int sum = 0;
  for( ; i > 0; i -= ( i&-i ) ) {
    sum += bit[ id ][ i ];
  }
  return sum;
}

void solve( ) {
  int seen_points = 0;
  for( int i = 0; i < t; ++i ) {
    auto& e = events[ i ];
    if( e.tp == OPEN ) {
      ans[ e.idx ] = query( 0, e.x-1 )+query( 1, e.y-1 )-seen_points;
    } else if( e.tp == POINT ) {
      ++seen_points;
      update( 0, e.x );
      update( 1, e.y );
    } else {
      ans[ e.idx ] += seen_points-query( 0, e.x-1 )-query( 1, e.y-1 );
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

  while( cin >> n >> q ) {
    init( );
    for( int i = 0; i < n; ++i ) {
      int x, y; cin >> x >> y;
      events[ t++ ] = { x+y, x, y, POINT, -1 };
    }
    for( int i = 0; i < q; ++i ) {
      int x, y, d; cin >> x >> y >> d;
      events[ t++ ] = { x+y, x, y, OPEN, i };
      events[ t++ ] = { x+y+d, x, y, CLOSE, i };
    }
    sort( events, events+t, cmp_event );
    solve( );
    for( int i = 0; i < q; ++i ) {
      cout << ans[ i ] << '\n';
    }
  }

  return 0;
}