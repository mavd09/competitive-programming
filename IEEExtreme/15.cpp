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
typedef double              lf;
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
const int oo  = int( 2e9 );
const lf  eps = 0;

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

const lf inf_cap = 1e9;

struct Edge {

  int to, inv_idx;
  ll cap, flow;
  lf cost;
  
  Edge( int to, ll cap, lf cost, int inv_idx ) :
    to( to ), cap( cap ), cost( cost ), inv_idx( inv_idx ), flow( 0 ) { }

};

struct Min_Cost_Max_Flow {

  int n;
  vector< vector< Edge > > graph;
  vi prv, prv_id;
  vlf dist, phi;

  Min_Cost_Max_Flow( int n ) : 
    n( n ), graph( n ), dist( n ), phi( n ), prv( n ), prv_id( n ) { }

  void add_edge( int from, int to, ll cap, lf cost ) {
    graph[ from ].PB( Edge( to, cap, cost, int( graph[ to ].size( ) ) ) );
    graph[ to ].PB( Edge( from, 0, -cost, int( graph[ from ].size( ) )-1 ) );
  }

  ll dijkstra( int s, int t ) {
    fill( dist.begin( ), dist.end( ), inf_cap );
    set< pair< lf, int > > q;
    dist[ s ] = prv[ s ] = 0;
    q.insert( MP( dist[ s ], s ) );
    while( !q.empty( ) ) {
      int u = ( *q.begin( ) ).SE; q.erase( q.begin( ) );
      int id = -1;
      for( int i = 0; i < int( graph[ u ].size( ) ); i++ ) {
        Edge& e = graph[ u ][ i ];
        id++;
        if( e.cap <= 0 ) {
          continue;
        }
        lf cur = e.cost+phi[ u ]-phi[ e.to ];
        if( cmp( dist[ u ]+cur, dist[ e.to ] ) < 0 ) {
          q.erase( MP( dist[ e.to ], e.to ) );
          dist[ e.to ] = dist[ u ]+cur;
          prv[ e.to ] = u;
          prv_id[ e.to ] = id;
          q.insert( MP( dist[ e.to ], e.to ) );
        }
      }
    }
    if( prv[ t ] == -1 ) {
      return 0;
    }
    ll ret = inf_cap;
    for( int u = t; u != s; u = prv[ u ] ) {
      ret = min( ret, graph[ prv[ u ] ][ prv_id[ u ] ].cap );
    }
    return ret;
  }

  pair< ll, lf > max_flow( int s, int t ) {
    ll totflow = 0;
    lf totcost = 0;
    while( ll amt = dijkstra( s, t ) ) {
      for( int u = t; u != s; u = prv[ u ] ) {
        graph[ prv[ u ] ][ prv_id[ u ] ].cap -= amt;
        graph[ graph[ prv[ u ] ][ prv_id[ u ] ].to ][ graph[ prv[ u ] ][ prv_id[ u ] ].inv_idx].cap += amt;
      }
      totflow += amt;
      totcost += lf( amt )*( dist[ t ]-phi[ s ]+phi[ t ] );
      for( int u = 0; u < n; u++ ) {
        if( prv[ u ] != -1 ) {
          phi[ u ] += dist[ u ];
        }
      }
    }
    return MP( totflow, totcost );
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
    lf ans_a = ( lo+hi )/2.0;
    Min_Cost_Max_Flow mcmf( 2*n+2 );
    int source = 2*n, sink = 2*n+1;
    for( int i = 0; i < n; i++ ) {
      mcmf.add_edge( source, i, 1, 0 );
      mcmf.add_edge( n+i, sink, 1, 0 );
      for( int j = 0; j < n; j++ ) {
        if( cmp( d[ i ][ j ], ans_a ) <= 0 ) {
          mcmf.add_edge( i, n+j, 1, d[ i ][ j ] );
        }
      }
    }
    pair< ll, lf > ans_b = mcmf.max_flow( source, sink );
    cout << ans_a << "\n" << ans_b.SE << "\n";
  }

  return 0;
}