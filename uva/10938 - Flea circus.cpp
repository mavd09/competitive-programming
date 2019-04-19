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

#define x( P )              real( P )
#define y( P )              imag( P )
#define cross( A, B )       y( conj(A)*(B) )
#define dot( A, B )         x( conj(A)*(B) )

const int MX  = int( 1e6 );
const ll  mod = int( 1e9 )+7;
const lf  oo  = 1e18;

const int LOG2 = 15;

void dfs( vvi& graph, vvi& lca, vi& depth, int u, int p ) {
  lca[ u ][ 0 ] = p; depth[ u ] = depth[ p ]+1;
  for( auto& v : graph[ u ] ) {
    if( p != v ) {
      dfs( graph, lca, depth, v, u );
    }
  }
}

pii query( vvi& lca, vi& depth, int u, int v ) {
  if( depth[ u ] > depth[ v ] ) {
    swap( u, v );
  }
  int nu = u, nv = v, steps = 0;
  for( int j = LOG2-1; j >= 0; j-- ) {
    if( depth[ u ] < depth[ lca[ v ][ j ] ] ) {
      v = lca[ v ][ j ];
      steps += ( 1<<j );
    }
  }
  if( depth[ u ] != depth[ v ] ) {
    v = lca[ v ][ 0 ];
    steps++;
  }
  if( u != v ) {
    for( int j = LOG2-1; j >= 0; j-- ) {
      if( lca[ u ][ j ] != lca[ v ][ j ] ) {
        u = lca[ u ][ j ];
        v = lca[ v ][ j ];
        steps += 2*( 1<<j );
      }
    }
    steps += 2;
  }
  u = nu; v = nv;
  int mask = steps/2;
  for( int j = LOG2-1; j >= 0; j-- ) {
    if( ( mask>>j )&1 ) {
      v = lca[ v ][ j ];
    }
  }
  u = v;
  if( steps%2 == 1 ) {
    u = lca[ u ][ 0 ];
  }
  return { u+1, v+1 };
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n;

  while( ( cin >> n ) && ( n != 0 ) ) {
    vvi graph( n+1 );
    for( int i = 0; i+1 < n; i++ ) {
      int u, v; cin >> u >> v; u--; v--;
      graph[ u ].PB( v );
      graph[ v ].PB( u );
    }
    vvi lca( n, vi( LOG2 ) );
    vi depth( n );
    dfs( graph, lca, depth, 0, 0 );
    for( int j = 0; j+1 < LOG2; j++ ) {
      for( int i = 0; i < n; i++ ) {
        lca[ i ][ j+1 ] = lca[ lca[ i ][ j ] ][ j ];
      }
    }
    int q; cin >> q;
    while( q-- ) {
      int u, v; cin >> u >> v; u--; v--;
      pii ans = query( lca, depth, u, v );
      if( ans.FI != ans.SE ) {
        if( ans.FI > ans.SE ) {
          swap( ans.FI, ans.SE );
        }
        cout << "The fleas jump forever between " << ans.FI << " and " << ans.SE << ".\n";
      }
      else {
        cout << "The fleas meet at " << ans.FI << ".\n";
      }
    }
  }

  return 0;
}