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

struct Disjoint_Set {
  int n; 
  vi p, r;
  Disjoint_Set( int n ) : n( n ), p( n ), r( n ) {
    for( int i = 0; i < n; i++ ) {
        p[ i ] = i;
    }
  }
  int find_set( int x ) {
    if( x == p[ x ] ) {
      return x;
    }
    return p[ x ] = find_set( p[ x ] );
  }
  bool same_set( int x, int y ) {
    return find_set( x ) == find_set( y );
  }
  void union_set( int x, int y ) {
    x = find_set( x );
    y = find_set( y );
    if( r[ y ] > r[ x ] ) {
      swap( x, y );
    }
    p[ y ] = x;
    if( r[ y ] == r[ x ] ) {
      r[ x ]++;
    }
  }
};

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

  vi dx = { 0, 0, 1, -1 };
  vi dy = { 1, -1, 0, 0 };

  int n; cin >> n;

  vvi st( n+2, vi( n ) );
  vvi b( n+2, vi( n ) );
  int id = 0;
  for( int i = 0; i < n+2; i++ ) {
    for( int j = 0; j < n; j++ ) {
      b[ i ][ j ] = id++;
    }
  }

  Disjoint_Set ds( n*( n+2 ) );
  for( int j = 0; j+1 < n; j++ ) {
    st[ 0 ][ j ] = st[ 0 ][ j+1 ] = 1;
    st[ n+1 ][ j ] = st[ n+1 ][ j+1 ] = 1;
    ds.union_set( b[ 0 ][ j ], b[ 0 ][ j+1 ] );
    ds.union_set( b[ n+1 ][ j ], b[ n+1 ][ j+1 ] );
  }

  int x, y;
  for( int i = 1; cin >> x; i++ ) {
    if( x == -1 ) {
      break;
    }
    cin >> y;
    st[ x ][ y ] = 1;
    for( int k = 0; k < 4; k++ ) {
      int nx = x+dx[ k ], ny = y+dy[ k ];
      if( 0 <= nx && nx <= n+1 && 0 <= ny && ny < n && st[ nx ][ ny ] ) {
        ds.union_set( b[ x ][ y ], b[ nx ][ ny ] );
      }
    }
    if( ds.same_set( b[ 0 ][ 0 ], b[ n+1 ][ 0 ] ) ) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";

  return 0;
}