#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <algorithm>
#include <limits.h>
#include <iomanip>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cassert>

#include <complex>

#include <time.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< vb >        vvb;
typedef vector< lf >        vlf;
typedef vector< vlf >       vvlf;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;
typedef vector< vvi >       vvvi;
typedef vector< vvvi >      vvvvi;
typedef vector< pii >       vpii;
typedef vector< vpii >      vvpii;

typedef complex< lf >       pt;

const int MX  = 123;
const int MOD = int( 360 );
const lf  oo  = 2e7;
const lf  eps = 1e-9;

int cmp( lf a, lf b ) {
  if( a+eps < b ) {
    return -1;
  }
  if( b+eps < a ) {
    return 1;
  }
  return 0;
}

struct Hopcroft_Karp {

  const static int max_n1 = 510;
  const static int max_n2 = 510;
  const static int max_m  = 300010;

  int n1, n2, edges;
  vi last, prev, head, matching, dist, q;
  vb used, vis;

  Hopcroft_Karp( ) :
    last( max_n1 ), prev( max_m ), head( max_m ),
    matching( max_n2 ), dist( max_n1 ), q( max_n1 ),
    used( max_n1 ), vis( max_n1 ) {
  }

  void init( int n1, int n2 ) {
    this->n1 = n1;
    this->n2 = n2;
    edges = 0;
    fill( last.begin( ), last.begin( )+n1, -1 );
  }

  void add_edge( int u, int v ) {
    head[ edges ] = v;
    prev[ edges ] = last[ u ];
    last[ u ] = edges++;
  }

  void bfs( ) {
    fill( dist.begin( ), dist.begin( )+n1, -1 );
    int size_q = 0;
    for( int u = 0; u < n1; u++ ) {
      if( !used[ u ] ) {
        q[ size_q++ ] = u;
        dist[ u ] = 0;
      }
    }
    for( int i = 0; i < size_q; i++ ) {
      int u1 = q[ i ];
      for( int e = last[ u1 ]; e >= 0; e = prev[ e ] ) {
        int u2 = matching[ head[ e ] ];
        if( u2 >= 0 && dist[ u2 ] < 0 ) {
          dist[ u2 ] = dist[ u1 ] + 1;
          q[ size_q++ ] = u2;
        }
      }
    }
  }

  bool dfs( int u1 ) {
    vis[ u1 ] = true;
    for( int e = last[ u1 ]; e >= 0; e = prev[ e ] ) {
      int v = head[ e ];
      int u2 = matching[ v ];
      if( u2 < 0 || ( !vis[ u2 ] && dist[ u2 ] == dist[ u1 ]+1 && dfs( u2 ) ) ) {
        matching[ v ] = u1;
        used[ u1 ] = true;
        return true;
      }
    }
    return false;
  }

  int max_matching( ) {
    fill( used.begin( ), used.begin( )+n1, false );
    fill( matching.begin( ), matching.begin( )+n2, -1 );
    int ans = 0;
    while( true ) {
      bfs( );
      fill( vis.begin( ), vis.begin( )+n1, false );
      int f = 0;
      for( int u = 0; u < n1; u++ ) {
        if( !used[ u ] && dfs( u ) ) {
          f++;
        }
      }
      if( f == 0 ) {
        return ans;
      }
      ans += f;
    }
    return 0;
  }

}hk;

struct Edge { 
  int u, v;
  ll cap, flow;
  lf cost;
  Edge( ) { }
  Edge( int u, int v, lf cost, ll cap, ll flow ) : 
    u( u ), v( v ), cost( cost ), cap( cap ), flow( flow ) { }
};

struct Min_Cost_Max_Flow {

  int n;
  vector< Edge > edge;
  vvi graph;
  vi pred;
  vlf dist, phi;

  Min_Cost_Max_Flow( int n ) : 
    n( n ), graph( n ), pred( n ), dist( n ), phi( n ) { }

  void add_edge( int u, int v, lf cost, ll cap ) {
    graph[ u ].PB( int( edge.size( ) ) );
    edge.PB( Edge( u, v, cost, cap, 0 ) );
    graph[ v ].PB( int( edge.size( ) ) );
    edge.PB( Edge( v, u, -cost, 0, 0 ) );
  }

  bool dijkstra( int source, int sink ) {
    fill( dist.begin( ), dist.end( ), oo );
    fill( pred.begin( ), pred.end( ), -1 );
    set< pair< lf, int > > pq;
    dist[ source ] = 0;
    for( pq.insert( MP( dist[ source ], source ) ); !pq.empty( ); ) {
      int u = ( *pq.begin( ) ).SE; pq.erase( pq.begin( ) );
      for( int i = 0; i < int( graph[ u ].size( ) ); i++ ) {
        Edge& e = edge[ graph[ u ][ i ] ];
        lf ndist = dist[ e.u ]+e.cost+phi[ e.u ]-phi[ e.v ];
        if( 0 < ( e.cap-e.flow ) && ndist < dist[ e.v ] ) {
          pq.erase( MP( dist[ e.v ], e.v ) );
          dist[ e.v ] = ndist;
          pred[ e.v ] = graph[ u ][ i ];
          pq.insert( MP( dist[ e.v ], e.v ) );
        }
      }
    }
    for( int i = 0; i < n; i++ ) {
      phi[ i ] = min( oo, phi[ i ]+dist[ i ] );
    }
    return ( dist[ sink ] != oo );
  }

  pair< ll, lf > max_flow( int source, int sink ) {
    lf mincost = 0;
    ll maxflow = 0;
    fill( phi.begin( ), phi.end( ), 0 );
    while( dijkstra( source, sink ) ) {
      ll flow = oo;
      for( int v = pred[ sink ]; v != -1; v = pred[ edge[ v ].u ] ) {
        flow = min( flow, edge[ v ].cap-edge[ v ].flow );
      }
      for( int v = pred[ sink ]; v != -1; v = pred[ edge[ v ].u ] ) {
        Edge& e1 = edge[ v ];
        Edge& e2 = edge[ v^1 ];
        mincost += e1.cost*flow;
        e1.flow += flow;
        e2.flow -= flow;
      }
      maxflow += flow;
    }
    return MP( maxflow, mincost );
  }
  
};

istream& operator >> ( istream& in, pt& p ) {
  lf x, y; in >> x >> y;
  p = { x, y };
  return in;
}

lf dist( pt& a, pt& b ) {
  return abs( b-a );
}

bool can( int& n, vector< vector< lf > >& d, lf val ) {
  hk.init( n, n );
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < n; j++ ) {
      if( cmp( d[ i ][ j ] , val ) <= 0 ) {
        hk.add_edge( i, j );
      }
    }
  }
  return ( hk.max_matching( ) == n );
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #endif

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  cout << fixed << setprecision( 4 );

  int n;

  while( cin >> n ) {
    vector< pt > p( n ), q( n );
    for( auto& e : p ) {
      cin >> e;
    }
    for( auto& e : q ) {
      cin >> e;
    }
    vector< vector< lf > > d( n, vector< lf >( n ) );
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < n; j++ ) {
        d[ i ][ j ] = dist( p[ i ], q[ j ] );
      }
    }
    lf lo = 0.0, hi = 1500.0, mi;
    for( int it = 0; it < 100; it++ ) {
      mi = ( lo+hi )/2.0;
      if( !can( n, d, mi ) ) {
        lo = mi;
      }
      else {
        hi = mi;
      }
    }
    lf ans_a = ( lo+hi )/2.0+eps;
    assert( can( n, d, ans_a ) );
    Min_Cost_Max_Flow mcmf( 2*n+2 );
    int source = 2*n, sink = 2*n+1;
    for( int i = 0; i < n; i++ ) {
      mcmf.add_edge( source, i, 0, 1 );
      mcmf.add_edge( n+i, sink, 0, 1 );
      for( int j = 0; j < n; j++ ) {
        if( cmp( d[ i ][ j ], ans_a ) <= 0 ) {
          mcmf.add_edge( i, n+j, d[ i ][ j ], 1 );
          //cout << i << " " << n+j << " " << d[ i ][ j ] << " " << 1 << endl;
        }
      }
    }
    pair< ll, lf > ans_b = mcmf.max_flow( source, sink );
    cout << ans_a << "\n" << ans_b.SE << "\n";
  }

  return 0;
}