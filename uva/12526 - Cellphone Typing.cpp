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
const int oo  = int( 1e8 );

struct Trie {
  int sz;
  vb end_word;
  vi cnt_son, son, cnt;
  vvi trie;
  Trie( ) {
    sz = 0;
    add_node( );
  }
  int add_node( ) {
    end_word.PB( false );
    cnt_son.PB( 0 ); son.PB( -1 ); cnt.PB( 0 );
    trie.PB( vi( 26, -1 ) );
    return sz++;
  }
  void add_word( string& word ) {
    int node = 0;
    for( auto& c : word ) {
      int x = c-'a';
      if( trie[ node ][ x ] == -1 ) {
        int new_node = add_node( );
        cnt_son[ node ]++;
        son[ node ] = new_node;
        trie[ node ][ x ] = new_node;
      }
      node = trie[ node ][ x ];
      cnt[ node ]++;
    }
    end_word[ node ] = true;
  }
  int get_keystrokes( ) {
    cnt_son[ 0 ] = 26;
    int r = 0;
    queue< int > q;
    q.push( 0 );
    while( !q.empty( ) ) {
      int cur_node = q.front( ); q.pop( );
      while( !end_word[ cur_node ] && cnt_son[ cur_node ] == 1 ) {
        cur_node = son[ cur_node ];
      }
      for( int i = 0; i < 26; i++ ) {
        if( trie[ cur_node ][ i ] != -1 ) {
          r += cnt[ trie[ cur_node ][ i ] ];
          q.push( trie[ cur_node ][ i ] );
        }
      }
    }
    return r;
  }
};

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

  cout << fixed << setprecision( 2 );

  int n;

  while( cin >> n ) {
    Trie trie;
    for( int i = 0; i < n; i++ ) {
      string word; cin >> word;
      trie.add_word( word );
    }
    double ans = double( trie.get_keystrokes( ) )/double( n );
    cout << ans << "\n";
  }

  return 0;
}