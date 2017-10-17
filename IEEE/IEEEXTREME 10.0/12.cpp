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
const int oo  = int( 1e8 );

struct Disjoint_Set {
  int n; 
  vi p, r, s;
  Disjoint_Set( int n ) : n( n ), p( n ), r( n ), s( n ) {
    for( int i = 0; i < n; i++ ) {
        p[ i ] = i;
        s[ i ] = 1;
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
    if( x == y ) {
      return ;
    }
    if( r[ y ] > r[ x ] ) {
      swap( x, y );
    }
    p[ y ] = x;
    s[ x ] += s[ y ];
    if( r[ y ] == r[ x ] ) {
      r[ x ]++;
    }
  }
  vi get_sizes( ) {
    vi ret;
    for( int i = 1; i < n; i++ ) {
      if( i == p[ i ] ) {
        ret.PB( s[ i ] );
      } 
    }
    return ret;
  } 
};

int go( int& n, vi& dp, vi& acc, int& a, int f ) {
  if( f == n+1 ) {
    return 0;
  }
  int& r = dp[ f ];
  if( r != -1 ) {
    return r;
  }
  r = oo;
  for( int t = f; t <= n; t++ ) {
    r = min( r, max( go( n, dp, acc, a, t+1 ), abs( (acc[ t ]-acc[ f-1 ])-a ) ) );
  }
  return r;
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

  int a, p;

  while( cin >> a >> p ) {
    Disjoint_Set ds( p+1 );
    for( int i = 1; i <= p; i++ ) {
      int x; cin >> x;
      if( x ) {
        ds.union_set( x, i );
      }
    }
    vi s = ds.get_sizes( );
    int n = int( s.size( ) );
    vi acc( n+1 ), dp( n+1, -1 );
    for( int i = 0; i < n; i++ ) {
      acc[ i+1 ] = acc[ i ]+s[ i ];
    }
    cout << go( n, dp, acc, a, 1 ) << "\n";
  }

  return 0;
}