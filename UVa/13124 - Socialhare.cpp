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

typedef complex< lf >       pt;

const int MX  = 257;
const int MOD = int( 360 );
const lf  oo  = 1e18;

bool is_valid( vi& acc, vi& acc_word ) {
  bool ok = true;
  for( int i = 0; i < 26 && ok; i++ ) {
    ok &= ( acc[ i ] == acc_word[ i ] );
  }
  return ok;
}

bool check( int& r, int& c, vector< string >& board, vi& acc_word, int word_size, int x, int y, int dx, int dy ) {
  vi acc( 26 );
  for( int i = 0; i < word_size && ( 0 <= x && x < r && 0 <= y && y < c ); i++, x += dx, y += dy ) {
    acc[ board[ x ][ y ]-'a' ]++;
  }
  bool ans = is_valid( acc, acc_word );
  for( ; !ans && ( 0 <= x && x < r && 0 <= y && y < c ); x += dx, y += dy ) {
    acc[ board[ x ][ y ]-'a' ]++; acc[ board[ x-word_size*dx ][ y-word_size*dy ]-'a' ]--;
    ans = is_valid( acc, acc_word );
  }
  return ans;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int r, c, w;

  while( cin >> r >> c >> w ) {
    vector< string > board( r );
    for( auto& e : board ) {
      cin >> e;
    }
    int ans = 0;
    for( int q = 0; q < w; q++ ) {
      string word; cin >> word;
      vi acc_word( 26 );
      for( auto& e : word ) {
        acc_word[ e-'a' ]++;
      }
      int word_size = int( word.size( ) );
      bool ok = false;
      for( int i = 0; i < r && !ok; i++ ) {
        ok |= check( r, c, board, acc_word, int( word.size( ) ), i, 0, 0, 1 );
        ok |= check( r, c, board, acc_word, int( word.size( ) ), i, 0, 1, 1 );
        ok |= check( r, c, board, acc_word, int( word.size( ) ), i, c-1, 1, -1 );
      }
      for( int j = 0; j < c && !ok; j++ ) {
        ok |= check( r, c, board, acc_word, int( word.size( ) ), 0, j, 1, 0 );
        ok |= check( r, c, board, acc_word, int( word.size( ) ), 0, j, 1, 1 );
        ok |= check( r, c, board, acc_word, int( word.size( ) ), 0, j, 1, -1 );
      }
      ans += ok;
    }
    cout << ans << "\n";
  }

  return 0;
}