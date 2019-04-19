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

const int MAX = int( 2e3 );
const int MOD = int( 360 );
const ll  oo  = ll( 1e18 );

int bit[ MAX ][ MAX ];

void init( ) {
  memset( bit, 0, sizeof( bit ) );
}

void update( int x, int y, int v ) {
  for( int i = x; i < MAX; i += (i&-i) )
    for( int j = y; j < MAX; j += (j&-j) )
      bit[ i ][ j ] = max( bit[ i ][ j ], v );
}

int query( int x, int y ) {
  int mx = 0;
  for( int i = x; i > 0; i -= (i&-i) )
    for( int j = y; j > 0; j -= (j&-j) )
      mx = max( mx, bit[ i ][ j ] );
  return mx;
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

  int n_test;
  cin >> n_test;

  while( n_test-- ) {
    init( );
    int n; cin >> n;
    vi x( n ), y( n );
    for( int i = 0; i < n; i++ ) {
      cin >> x[ i ] >> y[ i ];
      x[ i ] = 1001-x[ i ];
      y[ i ] = 1001-y[ i ];
    }
    int ans = 0;
    for( int i = n-1; i >= 0; i-- ) {
      int q = query( x[ i ], y[ i ] );
      ans = max( ans, q+1 );
      update( x[ i ], y[ i ], q+1 );
    }
    cout << ans << "\n";
  }

  return 0;
}