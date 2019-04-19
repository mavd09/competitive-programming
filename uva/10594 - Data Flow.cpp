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
typedef vector< lf >        vd;
typedef vector< vd >        vvd;
typedef vector< vvd >       vvvd;
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
const ll  oo  = ll( 1e16 );

struct Edge { 
  int u, v;
  ll cost, cap, flow;
  Edge( ) { }
  Edge( int u, int v, ll cost, ll cap, ll flow ) : 
    u( u ), v( v ), cost( cost ), cap( cap ), flow( flow ) { }
};

struct Min_Cost_Max_Flow {

  int n;
  vector< Edge > edge;
  vvi graph;
  vll pred, dist, phi;

  Min_Cost_Max_Flow( int n ) : 
    n( n ), graph( n ), pred( n ), dist( n ), phi( n ) { }

  void add_edge( int u, int v, ll cost, ll cap ) {
    graph[ u ].PB( int( edge.size( ) ) );
    edge.PB( Edge( u, v, cost, cap, 0 ) );
    graph[ v ].PB( int( edge.size( ) ) );
    edge.PB( Edge( v, u, -cost, 0, 0 ) );
  }

  bool dijkstra( int source, int sink ) {
    fill( dist.begin( ), dist.end( ), oo );
    fill( pred.begin( ), pred.end( ), -1 );
    set< pii > pq;
    dist[ source ] = 0;
    for( pq.insert( MP( dist[ source ], source ) ); !pq.empty( ); ) {
      int u = ( *pq.begin( ) ).SE; pq.erase( pq.begin( ) );
      for( int i = 0; i < int( graph[ u ].size( ) ); i++ ) {
        Edge& e = edge[ graph[ u ][ i ] ];
        int ndist = dist[ e.u ]+e.cost+phi[ e.u ]-phi[ e.v ];
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

  pll max_flow( int source, int sink ) {
    ll mincost = 0, maxflow = 0;
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

  int n, m;

  while( cin >> n >> m ) {
    vi u( m ), v( m ), c( m );
    for( int i = 0; i < m; i++ )
      cin >> u[ i ] >> v[ i ] >> c[ i ];
    ll d, k; cin >> d >> k; 
    Min_Cost_Max_Flow mcmf( n+1 );
    for( int i = 0; i < m; i++ ) {
      mcmf.add_edge( u[ i ]-1, v[ i ]-1, c[ i ], k );
      mcmf.add_edge( v[ i ]-1, u[ i ]-1, c[ i ], k );
    }
    int source = n, sink = n-1;
    mcmf.add_edge( source, 0, 0, d );
    pll ans = mcmf.max_flow( source, sink );
    if( ans.FI == d ) cout << ans.SE << "\n";
    else cout << "Impossible.\n";
  }

  return 0;
}