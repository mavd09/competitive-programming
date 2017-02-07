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
      bit[ i ][ j ] += v;
}

int query( int x, int y ) {
  int sum = 0;
  for( int i = x; i > 0; i -= (i&-i) )
    for( int j = y; j > 0; j -= (j&-j) )
      sum += bit[ i ][ j ];
  return sum;
}

int query( int x1, int y1, int x2, int y2 ) {
  return query( x2, y2 )-query( x2, y1-1 )-query( x1-1, y2 )+query( x1-1, y1-1 );
}

void fix_coordinates( int& x, int& y, int& w, int& z ) {
  int a = min( x, w ), b = max( x, w );
  int c = min( y, z ), d = max( y, z );
  x = a; y = c;
  w = b; z = d;
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

  int h, w, p;

  while( cin >> h >> w >> p ) {
    if( h == 0 && w == 0 && p == 0 ) break;
    init( );
    int q; cin >> q;
    while( q-- ) {
      char cmd; cin >> cmd;
      if( cmd == 'A' ) {
        int n, x, y; cin >> n >> x >> y; x++; y++;
        update( x, y, n );
      }
      else {
        int x, y, z, w; cin >> x >> y >> z >> w;
        x++; y++; z++; w++;
        fix_coordinates( x, y, z, w );
        cout << query( x, y, z, w )*p << "\n";
      }
    }
    cout << "\n";
  }

  return 0;
}