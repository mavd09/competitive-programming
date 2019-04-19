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

const int MAX = int( 1e4 );
const int MOD = int( 1e9+7 );
const int oo  = int( 1e8 );

pii go( int& n, vvi& tree ) {
  int r1 = 0, r2 = 0;
  queue< int > q;
  q.push( 1 ); q.push( 1 ); q.push( 1 );
  while( !q.empty( ) ) {
    int u = q.front( ); q.pop( );
    int c = q.front( ); q.pop( );
    int f = q.front( ); q.pop( );
    if( f ) r1 = max( r1, c );
    r2 = max( r2, c );
    if( tree[ u ][ 1 ] ) {
      q.push( tree[ u ][ 1 ] );
      q.push( c+1 );
      q.push( f );
    }
    if( tree[ u ][ 0 ] ) {
      q.push( tree[ u ][ 0 ] );
      q.push( 1 );
      q.push( 0 );
    }
  }
  return make_pair( r1, r2 );
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int n, m;

  while( cin >> n ) {
    vvi tree1( n+1, vi( 2 ) );
    for( int i = 0; i < n; i++ ) {
      int id; cin >> id;
      cin >> tree1[ id ][ 0 ] >> tree1[ id ][ 1 ];
    }
    cin >> m;
    vvi tree2( m+1, vi( 2 ) );
    for( int i = 0; i < m; i++ ) {
      int id; cin >> id;
      cin >> tree2[ id ][ 1 ] >> tree2[ id ][ 0 ];
    }
    pii x = go( n, tree1 ), y = go( m, tree2 );
    int ans = n+m-max( min( x.FI, y.FI ), max( min( x.FI, y.SE ), min( x.SE, y.FI ) ) );
    cout << ans << "\n";
  }

  return 0;
}