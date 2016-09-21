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
typedef vector< vvi >       vvvi;
typedef vector< vvvi >      vvvvi;
typedef vector< pii >       vpii;

typedef pii                 pt;

const int MX  = 257;
const int MOD = int( 360 );
const int oo  = int( 1e8 );

const vpii delta_1 = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
const vpii delta_2 = { { 0, -1 }, { 0, 1 }, { 1, 0 }, { -1, 0 } };

istream& operator >> ( istream& in, pt& p ) {
  int x, y; in >> x >> y;
  p = { x-1, y-1 };
  return in;
}

pt operator + ( const pt& a, const pt& b ) {
  return { a.FI+b.FI, a.SE+b.SE };
}

pt operator - ( const pt& a, const pt& b ) {
  return { a.FI-b.FI, a.SE-b.SE };
}

bool is_valid( int& r, int& c, pt& p ) {
  return ( 0 <= p.FI && p.FI < r && 0 <= p.SE && p.SE < c );
}

int go( int& r, int& c, vector< string >& board, pt& target, pt& a, pt& b ) {
  vvvvi min_dist( r, vvvi( c, vvi( r, vi( c, oo ) ) ) );
  queue< pt > q;
  q.push( a ); q.push( b );
  min_dist[ a.FI ][ a.SE ][ b.FI ][ b.SE ] = 0;
  min_dist[ b.FI ][ b.SE ][ a.FI ][ a.SE ] = 0;
  while( !q.empty( ) ) {
    pt cur_a = q.front( ); q.pop( );
    pt cur_b = q.front( ); q.pop( );
    if( cur_a == target && cur_b == target ) {
      return min_dist[ cur_a.FI ][ cur_a.SE ][ cur_b.FI ][ cur_b.SE ];
    }
    for( int d = 0; d < 4; d++ ) {
      pt ncur_a = cur_a+delta_1[ d ];
      pt ncur_b = cur_b+delta_2[ d ];
      if( !is_valid( r, c, ncur_a ) || board[ ncur_a.FI ][ ncur_a.SE ] == '#' ) {
        ncur_a = ncur_a-delta_1[ d ];
      }
      if( !is_valid( r, c, ncur_b ) || board[ ncur_b.FI ][ ncur_b.SE ] == '#' ) {
        ncur_b = ncur_b-delta_2[ d ];
      }
      if( min_dist[ cur_a.FI ][ cur_a.SE ][ cur_b.FI ][ cur_b.SE ]+1 < min_dist[ ncur_a.FI ][ ncur_a.SE ][ ncur_b.FI ][ ncur_b.SE ] ) {
        min_dist[ ncur_a.FI ][ ncur_a.SE ][ ncur_b.FI ][ ncur_b.SE ] = min_dist[ cur_a.FI ][ cur_a.SE ][ cur_b.FI ][ cur_b.SE ]+1;
        min_dist[ ncur_b.FI ][ ncur_b.SE ][ ncur_a.FI ][ ncur_a.SE ] = min_dist[ cur_a.FI ][ cur_a.SE ][ cur_b.FI ][ cur_b.SE ]+1;
        q.push( ncur_a ); q.push( ncur_b );
      }
    }
  }
  return -1;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int r, c;

  while( cin >> r >> c ) {
    pt target, a, b;
    cin >> target >> a >> b;
    vector< string > board( r );
    for( auto& e : board ) {
      cin >> e;
    }
    int ans = go( r, c, board, target, a, b );
    if( ans != -1 ) {
      cout << ans << "\n";
    }
    else {
      cout << "NO LOVE\n";
    }
  }

  return 0;
}