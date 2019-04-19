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
const int oo  = int( 5e8 );
const lf  eps = 1e-9;

void update( set< pii >& s, set< pii >::iterator& it, vvi& graph, vi& degree, vb& is_in, int& u ) {
  s.erase( it );
  is_in[ u ] = false;
  for( auto& v : graph[ u ] ) {
    if( is_in[ v ] ) {
      s.erase( { degree[ v ], v } );
      degree[ v ]--;
      s.insert( { degree[ v ], v } );
    }
  }
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #endif

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n, m, a, b;

  while( cin >> n >> m >> a >> b ) {
    int t = n;
    vvi graph( n );
    vi degree( n );
    for( int i = 0; i < m; i++ ) {
      int u, v; cin >> u >> v; u--; v--;
      graph[ u ].push_back( v );
      graph[ v ].push_back( u );
      degree[ u ]++;
      degree[ v ]++;
    }
    set< pii > s;
    set< pii >::iterator it;
    vb is_in( n, true );
    for( int i = 0; i < n; i++ ) {
      s.insert( { degree[ i ], i } );
    }
    bool change = true;
    while( !s.empty( ) && change ) {
      change = false;
      int u;
      it = s.begin( );
      u = ( *it ).SE;
      if( degree[ u ] < a ) {
        change = true;
        update( s, it, graph, degree, is_in, u );
      }
      if( s.empty( ) ) {
        continue;
      }
      it = s.end( ); it--;
      u = ( *it ).SE;
      if( int( s.size( ) )-degree[ u ]-1 < b ) {
        change = true;
        update( s, it, graph, degree, is_in, u );
      }
    }
    cout << int( s.size( ) ) << "\n";
  }

  return 0;
}
/*  ANOTHER SOLUTION

  int main( ) {

    int n, m, a, b;

    while( cin >> n >> m >> a >> b ) {
      int ans = n;
      vvi graph( n );
      vi degree( n );
      for( int i = 0; i < m; i++ ) {
        int u, v; cin >> u >> v; u--; v--;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
        degree[ u ]++;
        degree[ v ]++;
      }
      bool change;
      vb is_in( n, true );
      do {
        queue< int > q;
        change = false;
        for( int u = 0; u < n; u++ ) {
          if( is_in[ u ] && ( degree[ u ] < a || ans-degree[ u ]-1 < b ) ) {
            q.push( u );
            is_in[ u ] = false;
          }
        }
        while( !q.empty( ) ) {
          change = true;
          int u = q.front( ); q.pop( );
          ans--;
          for( auto& v : graph[ u ] ) {
            degree[ v ]--;
            if( is_in[ v ] && ( degree[ v ] < a || ans-degree[ v ]-1 < b ) ) {
              q.push( v );
              is_in[ v ] = false;
            }
          }
        }
      } while( change );
      cout << ans << "\n";
    }

    return 0;
  }
*/