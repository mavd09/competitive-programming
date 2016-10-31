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

const int MX  = int( 1e6 )+10;
const int MOD = int( 360 );
const int oo  = int( 2e9 );

int dx[ ] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[ ] = { 1, 0, -1, 0, 1, -1, 1, -1 };

int n, m, q, t, cur_id;
char board[ 1010 ][ 1010 ];
vi graph[ MX ], components;
int lca[ MX ][ 22 ], d[ MX ], id[ 1010 ][ 1010 ];
bool used[ MX ];

bool is_valid( int x, int y ) {
  return ( 0 <= x && x < n && 0 <= y && y < m );
}

void fill_component( int x, int y ) {
  id[ x ][ y ] = cur_id;
  for( int i = 0; i < t; i++ ) {
    int nx = x+dx[ i ], ny = y+dy[ i ];
    if( is_valid( nx, ny ) && board[ x ][ y ] == board[ nx ][ ny ] && id[ nx ][ ny ] == -1 ) {
      fill_component( nx, ny );
    }
  }
}

void dfs( int u, int p ) {
  used[ u ] = true;
  d[ u ] = d[ p ]+1;
  lca[ u ][ 0 ] = p;
  for( auto& v : graph[ u ] ) {
    if( v != p ) {
      if( used[ v ] ) {
        assert( true );
      }
      else {
        dfs( v, u );
      }
    }
  }
}

int query( int u, int v ) {
  int uu = u, vv = v;
  if( u == v ) {
    return 0;
  }
  if( d[ u ] > d[ v ] ) {
    swap( u, v );
  }
  int r = 0;
  for( int j = 21; j >= 0; j-- ) {
    if( d[ u ] <= d[ lca[ v ][ j ] ] ) {
      v = lca[ v ][ j ];
    }
  }
  if( u == v ) {
    return d[ vv ]-d[ u ];
  }
  for( int j = 21; j >= 0; j-- ) {
    if( lca[ u ][ j ] != lca[ v ][ j ] ) {
      u = lca[ u ][ j ];
      v = lca[ v ][ j ];
    }
  }
  u = lca[ u ][ 0 ];
  return d[ uu ]+d[ vv ]-2*d[ u ];
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

  cin >> n >> m >> q;

  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < m; j++ ) {
      cin >> board[ i ][ j ];
    }
  }

  memset( id, -1, sizeof( id ) );
  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < m; j++ ) {
      if( id[ i ][ j ] == -1 ) {
        t = ( board[ i ][ j ] == 'O' ? 8 : 8 );
        fill_component( i, j ); cur_id++;
      }
    }
  }

  for( int i = 0; i < n; i++ ) {
    for( int j = 0; j < m; j++ ) {
      for( int k = 0; k < 2; k++ ) {
        int ni = i+dx[ k ], nj = j+dy[ k ];
        if( is_valid( ni, nj ) && id[ ni ][ nj ] != id[ i ][ j ] ) {
          graph[ id[ i ][ j ] ].PB( id[ ni ][ nj ] );
          graph[ id[ ni ][ nj ] ].PB( id[ i ][ j ] );
        }  
      }
    }
  }

  n = cur_id;
  for( int i = 0; i < n; i++ ) {
    sort( graph[ i ].begin( ), graph[ i ].end( ) );
    graph[ i ].resize( unique( graph[ i ].begin( ), graph[ i ].end( ) )-graph[ i ].begin( ) );
  }
  dfs( 0, 0 );
  for( int j = 0; j+1 < 22; j++ ) {
    for( int i = 0; i < n; i++ ) {
      lca[ i ][ j+1 ] = lca[ lca[ i ][ j ] ][ j ]; 
    }
  }
  for( int i = 0; i < q; i++ ) {
    int w, x, y, z; cin >> w >> x >> y >> z;
    w--; x--; y--; z--;
    int u = id[ w ][ x ];
    int v = id[ y ][ z ];
    int ans = query( u, v )/2;
    cout << ans << "\n";
  }

  return 0;
}