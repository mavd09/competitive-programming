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
const int oo  = int( 1e7 );

const lf eps = 1e-9;

int cmp( lf x, lf y ) {
  if( x+eps < y ) {
    return -1;
  }
  if( y+eps < x ) {
    return 1;
  }
  return 0;
}

bool f( int& x, vd& d, int g, int mn, lf up, lf lw ) {
  int mask = 0, mx_mask = ( 1<<g )-1;
  for( int i = 0; i < x; i++ ) {
    mask = (mask<<1)&(mx_mask);
    if( cmp( d[ i ], up ) > 0 ) {
      mask |= 1;
    }
    if( __builtin_popcount( mask ) >= mn ) {
      return false;
    }
  }
  for( int i = 0; i < x; i++ ) {
    mask = (mask<<1)&(mx_mask);
    if( cmp( d[ i ], lw ) < 0 ) {
      mask |= 1;
    }
    if( __builtin_popcount( mask ) >= mn ) {
      return false;
    }
  }
  return true;
}

bool can( int& x, vd& d, lf ucl, lf lcl, lf cl, lf sigma ) {
  for( int i = 0; i < x; i++ ) {
    if( cmp( d[ i ], ucl ) > 0 || cmp( d[ i ], lcl ) < 0 ) {
      return false;
    }
  }
  bool r = true;
  r &= f( x, d, 3, 2, cl+2.0*sigma, cl-2.0*sigma );
  r &= f( x, d, 5, 4, cl+1.0*sigma, cl-1.0*sigma );
  r &= f( x, d, 8, 8, cl+0.0*sigma, cl-0.0*sigma );
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

  vd A2 = { 0, 0, 1.880, 1.023, 0.729, 0.577, 0.483, 0.419, 0.373, 0.337, 0.308 };

  int n_test; cin >> n_test;

  while( n_test-- ) {
    int x, n; cin >> x >> n;
    int g = ( x-1 )/n+1;
    vd d( x ), avg( g ), mn( g, oo ), mx( g, -oo ), t( g );
    for( int i = 0; i < x; i++ ) {
      cin >> d[ i ];
      int id = i/n;
      avg[ id ] += d[ i ];
      mn[ id ] = min( mn[ id ], d[ i ] );
      mx[ id ] = max( mx[ id ], d[ i ] );
      t[ id ] += 1;
    }
    lf x_avg = 0, r_avg = 0;
    for( int i = 0; i < g; i++ ) {
      x_avg += avg[ i ]/t[ i ];
      r_avg += ( mx[ i ]-mn[ i ] );
    }
    x_avg /= lf( g ); r_avg /= lf( g );
    lf ucl = x_avg + A2[ n ]*r_avg;
    lf lcl = x_avg - A2[ n ]*r_avg;
    lf cl = x_avg;
    lf sigma = ( ucl-cl )/3.0;
    //cout << ucl << " " << lcl << " " << cl << " " << sigma << "\n";
    if( can( x, d, ucl, lcl, cl, sigma ) ) {
      cout << "In Control\n";
    } 
    else {
      cout << "Out of Control\n";
    }
  }

  return 0;
}