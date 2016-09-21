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

const int MAX = int( 1e6 )+100;
const int MAX_N = int( 2e5 )+100;
const int MOD = int( 1e9+7 );
const int oo  = int( 1e8 );

int x;

struct Query { int f, t, id; };
bool cmp_query( const Query& a, const Query& b ) {
  if( a.f/x != b.f/x )
    return a.f/x < b.f/x;
  return a.t < b.t;
}

struct Mo {
  vi counter;
  int r;
  Mo( ) : counter( MAX ), r( 0 ) { }
  int get_ans( ) {
    return r;
  }
  void add( int v ) {
    r += ( counter[ v ]++ == 0 );
  }
  void erase( int v ) {
    r -= ( --counter[ v ] == 0 );
  }
};

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n;

  while( cin >> n ) {
    x = sqrt( n );
    vi a( n+1 );
    for( int i = 1; i <= n; i++ )
      cin >> a[ i ];
    int q; cin >> q;
    vector< Query > query;
    for( int i = 0; i < q; i++ ) {
      int f, t; cin >> f >> t;
      query.PB( { f, t, i } );
    }
    sort( query.begin( ), query.end( ), cmp_query );
    vi ans( q );
    int l = 0, r = 0;
    Mo mo;
    for( auto& e : query ) {
      while( r < e.t ) mo.add( a[ ++r ] );
      while( l > e.f ) mo.add( a[ --l ] );
      while( r > e.t ) mo.erase( a[ r-- ] );
      while( l < e.f ) mo.erase( a[ l++ ] );
      ans[ e.id ] = mo.get_ans( );
    }
    for( auto& e: ans )
      cout << e << "\n";
  }

  return 0;
}