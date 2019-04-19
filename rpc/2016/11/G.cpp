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

int get_accum( vvi& v, int x, int y, int s ) {
  return v[ x+s-1 ][ y+s-1 ]-v[ x+s-1 ][ y-1 ]-v[ x-1 ][ y+s-1 ]+v[ x-1 ][ y-1 ];
}

void go( int n, vvi& v ) {
  for( int i = 1; i < n; i++ ) {
    for( int j = 1; j < n; j++ ) {
      v[ i ][ j ] += v[ i-1 ][ j ]+v[ i ][ j-1 ]-v[ i-1 ][ j-1 ];
    }
  }
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int n, c;

  while( cin >> n >> c ) {
    vvi w( n+1, vi( n+1 ) ), b( n+1, vi( n+1 ) );
    for( int i = 0; i < c; i++ ) {
      int x, y; cin >> x >> y;
      b[ x ][ y ] = 1;
    }
    for( int i = 0; i < c; i++ ) {
      int x, y; cin >> x >> y;
      w[ x ][ y ] = 1;
    }
    go( n+1, w ); go( n+1, b );
    int ans_b = 0, ans_w = 0;
    for( int i = 1; i <= n; i++ ) {
      for( int j = 1; j <= n; j++ ) {
        for( int s = 1; i+s-1 <= n && j+s-1 <= n; s++ ) {
          int ww = get_accum( w, i, j, s );
          int bb = get_accum( b, i, j, s );
          if( ww > 0 && bb == 0 )
            ans_w++;
          if( ww == 0 && bb > 0 )
            ans_b++;
        }
      }
    }
    cout << ans_b << " " << ans_w << "\n";
  }

  return 0;
}