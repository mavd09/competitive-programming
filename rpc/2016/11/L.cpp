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

const int dx[ ] = { 0, 0, 1, -1 };
const int dy[ ] = { 1, -1, 0, 0 };

int go( int& r, int& c, vvi& board, int color ) {
  queue< int > q;
  vvb used( r, vb( c ) );
  int mn = r*c;
  for( int i = 0; i < r; i++ ) {
    for( int j = 0; j < c; j++ ) {
      if( used[ i ][ j ] )
        continue;
      int cnt = 0, cur_color = ( board[ i ][ j ] ? board[ i ][ j ] : color );
      q.push( i );
      q.push( j );
      used[ i ][ j ] = true;
      while( !q.empty( ) ) {
        int x = q.front( ); q.pop( );
        int y = q.front( ); q.pop( );
        cnt++;
        for( int k = 0; k < 4; k++ ) {
          int nx = x+dx[ k ];
          int ny = y+dy[ k ];
          if( 0 <= nx && nx < r && 0 <= ny && ny < c && !used[ nx ][ ny ] && ( ( board[ nx ][ ny ] == 0 && color == cur_color ) || ( board[ nx ][ ny ] != 0 && board[ nx ][ ny ] == cur_color ) ) ) {
            used[ nx ][ ny ] = true;
            q.push( nx );
            q.push( ny );
          }
        }
      }
      mn = min( mn, cnt );
    }
  }
  return mn;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int r, c;

  while( cin >> r >> c ) {
    vvi board( r, vi( c ) );
    vector< int > color;
    for( auto& row : board ) {
      for( auto& e : row ) {
        cin >> e;
        color.PB( e );
      }
    }
    sort( color.begin( ), color.end( ) );
    color.resize( unique( color.begin( ), color.end( ) )-color.begin( ) );
    for( int i = 0; i < r; i++ ) {
      for( int j = 0; j < c; j++ ) {
        board[ i ][ j ] = lower_bound( color.begin( ), color.end( ), board[ i ][ j ] )-color.begin( );
      }
    }
    cout << go( r, c, board, int( color.size( ) ) ) << "\n";
  }

  return 0;
}