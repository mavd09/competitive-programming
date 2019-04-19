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
const int oo  = 1e8;

vi dijkstra( int& n, vvpii& graph, vb& is_bank, vb& is_police ) {
  priority_queue< pii > pq;
  vi min_dist( n, oo );
  for( int u = 0; u < n; u++ ) {
    if( is_police[ u ] ) {
      pq.push( { 0, u } );
      min_dist[ u ] = 0;
    }
  }
  while( !pq.empty( ) ) {
    int u = pq.top( ).SE; 
    int c = -pq.top( ).FI;
    pq.pop( );
    if( min_dist[ u ] != c ) {
      continue;
    }
    for( auto& e : graph[ u ] ) {
      int v = e.FI, t = e.SE;
      if( min_dist[ u ]+t < min_dist[ v ] ) {
        min_dist[ v ] = min_dist[ u ]+t;
        pq.push( { -min_dist[ v ], v } );
      }
    }
  }
  return min_dist;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n, m, b, p;

  while( cin >> n >> m >> b >> p ) {
    vvi min_time( n, vi( n, oo ) );
    for( int i = 0; i < m; i++ ) {
      int u, v, t; cin >> u >> v >> t;
      min_time[ u ][ v ] = min_time[ v ][ u ] = min( min_time[ u ][ v ], t );
    }
    vvpii graph( n );
    for( int u = 0; u < n; u++ ) {
      for( int v = 0; v < n; v++ ) {
        if( u == v || min_time[ u ][ v ] == oo ) {
          continue;
        }
        graph[ u ].PB( { v, min_time[ u ][ v ] } );
      }
    }
    vb is_bank( n );
    for( int i = 0; i < b; i++ ) {
      int u; cin >> u;
      is_bank[ u ] = true;
    }
    vb is_police( n );
    for( int i = 0; i < p; i++ ) {
      int u; cin >> u;
      is_police[ u ] = true;
    }
    vi min_dist = dijkstra( n, graph, is_bank, is_police );
    int ans = 0;
    for( int u = 0; u < n; u++ ) {
      if( is_bank[ u ] ) {
        ans = max( ans, min_dist[ u ] );
      }
    }
    vi v_ans;
    for( int u = 0; u < n; u++ ) {
      if( is_bank[ u ] && min_dist[ u ] == ans ) {
        v_ans.PB( u );
      }
    }
    cout << int( v_ans.size( ) ) << " ";
    if( ans == oo ) {
      cout << "*\n";
    }
    else {
      cout << ans << "\n";
    }
    for( int i = 0; i < int( v_ans.size( ) ); i++ ) {
      if( i > 0 ) {
        cout << " ";
      }
      cout << v_ans[ i ];
    }
    cout << "\n";
  }

  return 0;
}