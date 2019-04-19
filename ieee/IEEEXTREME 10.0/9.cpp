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

string get_hash( vi& v ) {
  stringstream ss;
  vi nv;
  int i = 0;
  while( v[ i ] == 0 ) {
    i++;
  }
  for( ; i < int( v.size( ) ); i++ ) {
    if( v[ i ] == 0 ) {
      break;
    }
    ss << v[ i ] << " ";
    nv.PB( v[ i ] );
  }
  v = nv;
  return ss.str( );
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

  string line; getline( cin, line );
  stringstream ss( line );
  vi v, vv; int a, sz = 0;
  int D, H = 0;

  while( ss >> a ) {
    v.PB( a );
    sz++;
  }
  vv = v;
  map< string, int > d;
  string hash = get_hash( v );
  d[ hash ] = 0;

  for( int j = 1; ; j++ ) {
    for( int i = 1; i <= v[ 0 ]; i++ ) {
      if( i < int( v.size( ) ) ) {
        v[ i ]++;
      }
      else {
        v.PB( 1 );
      }
    }
    v[ 0 ] = 0;
    hash = get_hash( v );
    if( d.count( hash ) ) {
      D = d[ hash ];
      break;
    }
    d[ hash ] = j;
  }
  

  d.clear( );

  v = vv;
  queue< vi > q;
  queue< int > qc;
  q.push( v );
  qc.push( 0 );
  hash = get_hash( v );
  d[ hash ] = 0;
  while( !q.empty( ) ) {
    v = q.front( ); q.pop( );
    int c = qc.front( ); qc.pop( );
    //cout << string( 2*c, ' ' ) << get_hash( v ) << "\n";
    int cnt = 0;
    for( int i = 0; i < int( v.size( ) ); i++ ) {
      vv = vi( int( v.size( ) )+1 );
      bool ok = true, zeros = false;
      for( int j = 0; j <= i; j++ ) {
        vv[ j+1 ] = v[ j ];
        if( vv[ j+1 ] ) {
          vv[ 0 ]++;
          vv[ j+1 ]--;
          if( vv[ j+1 ] == 0 ) {
            zeros = true;
          }
          if( zeros && vv[ j+1 ] ) {
            ok = false;
          }
        }
        else {
          ok = false;
        }
      }
      for( int j = i+1; j < int( v.size( ) ); j++ ) {
        vv[ j+1 ] = v[ j ];
        if( zeros && vv[ j+1 ] ) {
          ok = false;
        }
      }
      if( ok ) {
        cnt++;
        hash = get_hash( vv );
        if( d.count( hash ) ) {
          H = max( H, c );
        }
        else {
          d[ hash ] = c+1;
          q.push( vv );
          qc.push( c+1 );
        }
      }
    }
    if( cnt == 0 ) {
      H = max( H, c );
    }
  }

  cout << D << " " << H << "\n";

  return 0;
}