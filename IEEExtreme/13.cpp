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
const int oo  = int( 2e9 );

struct State { string u; int f, d; };
struct Cmp_State {
  bool operator( ) ( const State& x, const State& y ) {
    if( x.d != y.d ) {
      return x.d > y.d;
    }
    return x.f < y.f; 
  }
  
};

int dijkstra( map< string, vector< pair< string, int > > >& graph, map< string, int >& fuel, string u, string v ) {
  map< pair< string, int >, int > min_dist;
  priority_queue< State, vector< State >, Cmp_State > pq;
  pq.push( { u, 0, 0 } );
  min_dist[ { u, 0 } ] = 0;
  while( !pq.empty( ) ) {
    State cur = pq.top( ); pq.pop( );
    //cout << cur.u << " " << cur.f << " " << cur.d << "\n";
    if( min_dist[ { cur.u, cur.f } ] != cur.d ) {
      continue;
    }
    if( cur.u == v ) {
      return cur.d;
    }
    for( auto& nxt : graph[ cur.u ] ) {
      //cout << nxt.FI << " " << nxt.SE << "\n";
      State st = { nxt.FI, min( 100, cur.f+fuel[ cur.u ] ), cur.d+nxt.SE };
      //cout << st.u << " " << st.f << " " << st.d << endl;
      if( st.f < nxt.SE ) {
        continue;
      }
      else {
        st.f -= nxt.SE;
        if( !min_dist.count( { st.u, st.f } ) || st.d < min_dist[ { st.u, st.f } ] ) {
          min_dist[ { st.u, st.f } ] = st.d;
          pq.push( st );
        }
      }
    }
  }
  return -1;
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

  int n_test; cin >> n_test;

  while( n_test-- ) {
    int n, m; cin >> n;
    map< string, int > fuel;
    for( int i = 0; i < n; i++ ) {
      string c; int f; cin >> c >> f;
      fuel[ c ] = f;
    }
    cin >> m;
    map< string, vector< pair< string, int > > > graph;
    for( int i = 0; i < m; i++ ) {
      string u, v; int c; cin >> u >> v >> c;
      graph[ u ].PB( { v, c } );
      graph[ v ].PB( { u, c } );
    }
    int ans = dijkstra( graph, fuel, "start", "end" );
    if( ans == -1 ) {
      cout << "Impossible\n";
    }
    else {
      cout << ans << "\n";
    }
  }

  return 0;
}