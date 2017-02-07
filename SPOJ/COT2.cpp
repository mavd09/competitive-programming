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

const int MAXN = int( 1e5 );
const int MAXM = int( 2e5 );
const int LOG2 = int( 20 );
const int MOD = int( 360 );
const int oo  = INT_MAX;

int n, m, nn;
int w[ MAXN ], ww[ MAXN ];
vi graph[ MAXN ];
int t, sz;
int in[ MAXN ], out[ MAXN ], lst[ MAXN ];
int ans[ MAXM ];
int p[ MAXN ][ LOG2 ], d[ MAXN];

bool seen[ MAXN ];
int cnt[ MAXN ];
int cur_ans;

struct Query { int l, r, a, id; } query[ MAXM ];
bool cmp_query( const Query& a, const Query& b ) {
  if( a.l/sz != b.l/sz )
    return a.l/sz < b.l/sz;
  return a.r < b.r;
}

void init( ) {
  t = 0; cur_ans = 0;
  for( int i = 0; i < MAXN; i++ ) {
    graph[ i ].clear( );
    cnt[ i ] = seen[ i ] = 0;
  }
}

void dfs( int pu, int u ) {
  lst[ t ] = u; in[ u ] = t++;
  p[ u ][ 0 ] = pu;
  d[ u ] = d[ pu ]+1;
  for( auto& v : graph[ u ] ) {
    if( v == pu ) continue;
    dfs( u, v );
  }
  lst[ t ] = u; out[ u ] = t++;
}

void fill_table( ) {
  for( int j = 0; j+1 < LOG2; j++ )
    for( int i = 0; i < n; i++ )
      p[ i ][ j+1 ] = p[ p[ i ][ j ] ][ j ];
}

int get_lca( int u, int v ) {
  for( int j = LOG2-1; j >= 0; j-- )
    if( d[ u ] <= d[ p[ v ][ j ] ] )
      v = p[ v ][ j ];
  if( u == v ) return u;
  for( int j = LOG2-1; j >= 0; j-- ) {
    if( p[ u ][ j ] != p[ v ][ j ] ) {
      u = p[ u ][ j ];
      v = p[ v ][ j ];
    }
  }
  return p[ u ][ 0 ];
}

void add( int x ) {
  if( seen[ x ] ) {
    cnt[ w[ x ] ]--;
    if( cnt[ w[ x ] ] == 0 )
      cur_ans--;
  }
  else {
    if( cnt[ w[ x ] ] == 0 )
      cur_ans++;
    cnt[ w[ x ] ]++;
  }
  seen[ x ] = !seen[ x ];
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

  while( cin >> n >> m ) {
    init( );
    for( int i = 0; i < n; i++ ) {
      cin >> w[ i ];
      ww[ i ] = w[ i ];
    }
    sort( ww, ww+n );
    nn = unique( ww, ww+n )-ww;
    for( int i = 0; i < n; i++ )
      w[ i ] = lower_bound( ww, ww+nn, w[ i ] )-ww;
    for( int i = 1; i < n; i++ ) {
      int u, v; cin >> u >> v; u--; v--;
      graph[ u ].PB( v );
      graph[ v ].PB( u );
    }
    dfs( 0, 0 );
    fill_table( );
    sz = sqrt( t );
    for( int i = 0; i < m; i++ ) {
      int u, v; cin >> u >> v; u--; v--;
      if( d[ v ] < d[ u ] ) swap( u, v );
      int lca = get_lca( u, v );
      if( lca == u ) 
        query[ i ] = { in[ u ], in[ v ], -1, i };
      else
        query[ i ] = { out[ u ], in[ v ], lca, i };
    }
    sort( query, query+m, cmp_query );
    int l = 0, r = -1;
    for( int i = 0; i < m; i++ ) {
      while( r < query[ i ].r ) add( lst[ ++r ] );
      while( l > query[ i ].l ) add( lst[ --l ] );
      while( l < query[ i ].l ) add( lst[ l++ ] );
      while( r > query[ i ].r ) add( lst[ r-- ] );
      if( query[ i ].a != -1 ) add( query[ i ].a );
      ans[ query[ i ].id ] = cur_ans;
      if( query[ i ].a != -1 ) add( query[ i ].a );
    }
    for( int i = 0; i < m; i++ )
      cout << ans[ i ] << "\n";
  }

  return 0;
}