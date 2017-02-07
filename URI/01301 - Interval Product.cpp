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

const int MAX = int( 2e5 );
const int MOD = int( 360 );
const ll  oo  = ll( 1e18 );

int a[ MAX ];

struct SegmentTree {
  int s, e;
  int val;
  SegmentTree *l, *r;
  SegmentTree( int s, int e ) : s( s ), e( e ) {
    if( s == e ) {
      l = r = nullptr;
      calc( );
      return ;
    }
    int m = ( s+e )/2;
    l = new SegmentTree( s, m );
    r = new SegmentTree( m+1, e );
    val = l->val*r->val;
  }
  void calc( ) {
    val = 0;
    if( a[ s ] > 0 ) val = 1;
    if( a[ s ] < 0 ) val = -1;
  }
  void update( int x ) {
    if( s == e ) {
      calc( );
      return ;
    }
    if( x <= l->e )
      l->update( x );
    else
      r->update( x );
    val = l->val*r->val;
  }
  int query( int f, int t ) {
    if( s == f && e == t ) return val;
    if( t <= l->e ) return l->query( f, t );
    if( f >= r->s ) return r->query( f, t );
    return l->query( f, l->e )*r->query( r->s, t );
  }
};

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

  int n, k;

  while( cin >> n >> k ) {
    for( int i = 1; i <= n; i++ )
      cin >> a[ i ];
    SegmentTree st( 1, n );
    for( int j = 0; j < k; j++ ) {
      char cmd; cin >> cmd;
      if( cmd == 'C' ) {
        int x; cin >> x;
        cin >> a[ x ];
        st.update( x );
      }
      else {
        int x, y; cin >> x >> y;
        int ans = st.query( x, y );
        if( ans == 0 ) cout << "0";
        if( ans > 0 ) cout << "+";
        if( ans < 0 ) cout << "-";
      }
    }
    cout << "\n";
  }

  return 0;
}