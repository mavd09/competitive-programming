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

int board[ 8 ][ 8 ];
int black_pieces, tc;
int x[ 17 ], y[ 17 ];
vi all;

bool is_valid( int xx, int yy ) {
  return 0 <= xx && xx < 8 && 0 <= yy && yy < 8;
}

int get_dir( int dx, int dy ) {
  if( dx == 0 && dy == 1 ) return 1;
  if( dx == 0 && dy == -1 ) return -1;
  if( dx == 1 && dy == 0 ) return 2;
  if( dx == -1 && dy == 0 ) return -2;
  return 9;
}

vpii get_moves( int mask, bool is_king, int dir, int fx, int fy, int tx, int ty ) {
  vpii moves;
  if( fx != tx && fy != ty ) {
    return moves;
  }
  int dx = ( fx < tx ? 1 : ( fx == tx ? 0 : -1 ) );
  int dy = ( fy < ty ? 1 : ( fy == ty ? 0 : -1 ) );
  int ndir = get_dir( dx, dy );
  if( dir == -ndir ) {
    return moves;
  }
  if( !is_king ) {
    if( dx == 1 || ( abs( fx-tx )+abs( fy-ty ) ) != 1 ) {
      return moves;
    }
    fx += 2*dx; fy += 2*dy;
    if( is_valid( fx, fy ) && ( board[ fx ][ fy ] == 0 || ( ( mask>>board[ fx ][ fy ] )&1 ) ) ) {
      moves.PB( { fx, fy } );
    }
  }
  else {
    fx += dx; fy += dy;
    while( !( fx == tx && fy == ty ) ) {
      if( board[ fx ][ fy ] && ( ( mask>>board[ fx ][ fy ] )&1 ) == 0 ) {
        return moves;
      }
      fx += dx; fy += dy;
    }
    fx += dx; fy += dy;
    while( is_valid( fx, fy ) ) {
      if( board[ fx ][ fy ] && ( ( mask>>board[ fx ][ fy ] )&1 ) == 0 ) {
        return moves;
      }
      moves.PB( { fx, fy } );
      fx += dx; fy += dy;
    }
  }
  return moves;
}

int ans;
//set< vpii > ans;

void go( int mask, bool is_king, int dir, int xx, int yy ) {
  if( __builtin_popcount( mask ) == black_pieces ) {
    ans++;
    return ;
  }
  //int& r = dp[ mask ][ is_king ][ xx ][ yy ];
  //if( used[ mask ][ is_king ][ xx ][ yy ] == tc ) {
  //  return r;
  //}
  //used[ mask ][ is_king ][ xx ][ yy ] = tc;
  for( int i = 1; i < black_pieces; i++ ) {
    if( ( ( mask>>i )&1 ) ) {
      continue;
    }
    vpii moves = get_moves( mask, is_king, dir, xx, yy, x[ i ], y[ i ] );
    int dx = ( xx < x[ i ] ? 1 : ( xx == x[ i ] ? 0 : -1 ) );
    int dy = ( yy < y[ i ] ? 1 : ( yy == y[ i ] ? 0 : -1 ) );
    int ndir = get_dir( dx, dy );
    for( auto& e : moves ) {
      all.PB( ndir );
      go( mask|( 1<<i ), is_king|( e.FI == 0 ), ndir, e.FI, e.SE );
      all.pop_back( );
    }
  }
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

  int n_test; cin >> n_test;

  for( tc = 1; n_test--; tc++ ) {
    black_pieces = 1;
    memset( board, 0, sizeof( board ) );
    for( int i = 0; i < 8; i++ ) {
      for( int j = 0; j < 8; j++ ) {
        char c; cin >> c;
        if( c == 'o' ) {
          x[ 0 ] = i;
          y[ 0 ] = j;
        }
        if( c == 'x' ) {
          x[ black_pieces ] = i;
          y[ black_pieces ] = j;
          board[ i ][ j ] = black_pieces++;
        }
      }
    }
    ans = 0;
    go( 1, x[ 0 ] == 0, 0, x[ 0 ], y[ 0 ] );
    cout << ans << "\n";
  }

  return 0;
}