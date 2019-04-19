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
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;
typedef vector< pii >       vpii;

typedef complex< lf >       pt;

#define x( P )              real( P )
#define y( P )              imag( P )
#define cross( A, B )       y( conj(A)*(B) )
#define dot( A, B )         x( conj(A)*(B) )

const int MX  = 257;
const int MOD = int( 360 );
const lf oo   = 1e18;

const lf EPS = 1e-9;

istream& operator >> ( istream& in, pt& p ) {
  lf x, y; in >> x >> y;
  p = pt( x, y );
  return in;
}

inline lf dist( pt a, pt b ) {
  return abs( b-a );
}

lf dist_to_line( pt p, pt a, pt b, pt& c ) {
  lf u = dot( p-a, b-a )/norm( b-a );
  c = a + u*( b-a );
  return dist( p, c );
}

lf dist_to_segment( pt p, pt a, pt b, pt& c ) {
  lf u = dot( p-a, b-a )/norm( b-a );
  if( u < EPS ) {
    c = a;
    return dist( p, a );
  }
  if( ( u-1.0 ) > EPS ) {
    c = b;
    return dist( p, b );
  }
  return dist_to_line( p, a, b, c );
}

int to_int( string s ) {
  stringstream in( s );
  int r; in >> r;
  return r;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  cout << fixed << setprecision( 3 );

  string s;

  while( ( cin >> s ) && ( s != "*" ) ) {
    int n = to_int( s );
    pt center; cin >> center;
    vector< pt > p( n+1 );
    for( int i = 0; i < n; i++ ) {
      cin >> p[ i ];
    }
    p[ n ] = p[ 0 ];
    pt c;
    lf ans = oo;
    for( int i = 0; i < n; i++ ) {
      ans = min( ans, dist_to_segment( center, p[ i ], p[ i+1 ], c ) );
    }
    cout << ans << "\n";
  }

  return 0;
}