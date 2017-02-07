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

const int MAXN = int( 2e5 );
const int MAXK = int( 2e3 );
const int LOG2 = int( 20 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, k;
vpii graph[ MAXN ];
int dp[ MAXK ];
int d[ MAXN ], p[ MAXN ][ LOG2 ], mx[ MAXN ][ LOG2 ];

void init( ) {
  for( int i = 0; i < MAXN; i++ ) {
    graph[ i ].clear( );
  }
  memset( dp, 0, sizeof( dp ) );
  memset( d, 0, sizeof( d ) );
  memset( mx, 0, sizeof( mx ) );
}

void dfs( int pu, int u ) {
  p[ u ][ 0 ] = pu;
  d[ u ] = d[ pu ]+1;
  for( auto& v : graph[ u ] ) {
    if( pu == v.FI ) continue;
    mx[ v.FI ][ 0 ] = v.SE;
    dfs( u, v.FI );
  }
}

void fill_table( ) {
  for( int j = 0; j+1 < LOG2; j++ ) {
    for( int i = 1; i <= n; i++ ) {
      p[ i ][ j+1 ] = p[ p[ i ][ j ] ][ j ];
      mx[ i ][ j+1 ] = max( mx[ i ][ j ], mx[ p[ i ][ j ] ][ j ] );
    }
  }
}

pii query( int a, int b ) {
  if( d[ a ] > d[ b ] ) swap( a, b );
  pii r = { 1, 0 };
  for( int j = LOG2-1; j >= 0; j-- ) {
    if( d[ a ] <= d[ p[ b ][ j ] ] ) {
      r.FI += ( 1<<j );
      r.SE = max( r.SE, mx[ b ][ j ] );
      b = p[ b ][ j ];
    }
  }
  if( a == b ) return r;
  for( int j = LOG2-1; j >= 0; j-- ) {
    if( p[ a ][ j ] != p[ b ][ j ] ) {
      r.FI += ( 1<<j );
      r.SE = max( r.SE, mx[ a ][ j ] );
      a = p[ a ][ j ];
      r.FI += ( 1<<j );
      r.SE = max( r.SE, mx[ b ][ j ] );
      b = p[ b ][ j ];
    }
  }
  r.SE = max( r.SE, max( mx[ a ][ 0 ], mx[ b ][ 0 ] ) );
  r.FI += 2;
  return r;
}

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

  while( cin >> n >> k ) {
    init( );
    for( int i = 1; i < n; i++ ) {
      int u, v, c; cin >> u >> v >> c;
      graph[ u ].PB( { v, c } );
      graph[ v ].PB( { u, c } );
    }
    dfs( 0, 1 );
    fill_table( );
    int q; cin >> q;
    while( q-- ) {
      int a, b; cin >> a >> b;
      pii cur = query( a, b );
      for( int i = k-cur.FI; i >= 0; i-- )
        dp[ i+cur.FI ] = max( dp[ i+cur.FI ], dp[ i ]+cur.SE );
    }
    int ans = 0;
    for( int i = 0; i <= k; i++ )
      ans = max( ans, dp[ i ] );
    if( ans == 0 ) ans = -1;
    cout << ans << "\n";
  }

  return 0;
}