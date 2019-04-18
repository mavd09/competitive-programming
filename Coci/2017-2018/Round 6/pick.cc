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
const ll  oo   = 1e16;

int a, b, c, d;

ll best = oo;
set< pii > seen;
vector< pii > ans, pts;

pii operator - ( const pii& a, const pii& b ) {
  return MP( a.FI-b.FI, a.SE-b.SE );
} 

ll cross( pii p1, pii p2 ) {
  return p1.FI*p2.SE - p1.SE*p2.FI;
}

bool add( int w, int z ) {
  if( seen.count( MP(w,z) ) ) return false;
  seen.insert( MP(w, z) );
  pts.PB( MP(w,z) );
  return true;
}

void del( int w, int z ) {
  pts.pop_back();
  seen.erase( MP(w, z) );
}

ll compute_area() {
    ll area = 0;
    for( int i = 1; i + 1 < pts.size(); ++i )
        area += cross(pts[i] - pts[0], pts[i + 1] - pts[0]);
    return abs(area);
}

void go( int x, int y ) {
  if( a+b+c+d == 0 ) {
    ll cur = compute_area();
    if( x == 0 && y == 0 && cur < best ) {
      ans = pts;
      best = cur;
    }
    return ;
  }
  if( a ) {
    a--;
    if( add(x+1, y) ) {
      go( x+1, y );
      del( x+1, y );
    }
    if( add(x-1, y) ) {
      go( x-1, y );
      del( x-1, y );
    }
    a++;
  }
  if( b ) {
    b--;
    if( add(x, y+1) ) {
      go( x, y+1 );
      del( x, y+1 );
    }
    if( add(x, y-1) ) {
      go( x, y-1 );
      del( x, y-1 );
    }
    b++;
  }
  if( c ) {
    c--;
    if( add(x+1, y+1) ) {
      go( x+1, y+1 );
      del( x+1, y+1 );
    }
    if( add(x-1, y-1) ) {
      go( x-1, y-1 );
      del( x-1, y-1 );
    }
    c++;
  }
  if( d ) {
    d--;
    if( add(x+1, y-1) ) {
      go( x+1, y-1 );
      del( x+1, y-1 );
    }
    if( add(x-1, y+1) ) {
      go( x-1, y+1 );
      del( x-1, y+1 );
    }
    d++;
  }
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d %d %d %d", &a, &b, &c, &d ) == 4 ) {
    pts.clear(); 
    go( 0, 0 );
    reverse( ALL(ans) );
    for( auto& e : ans ) {
      printf( "%d %d\n", e.FI, e.SE );
    }
  }

  return 0;
}

