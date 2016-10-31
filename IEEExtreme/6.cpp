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

  while( n_test-- ) {
    int p, s, n, a; cin >> p >> s >> n;
    map< int, int > last_pos;
    queue< int > q;
    set< int > in_queue_fifo, in_queue_lru;
    set< pii > pq;
    int ans_fifo = 0, ans_lru = 0;
    for( int i = 0; i < n; i++ ) {
      cin >> a; a = a/s;
      if( !in_queue_fifo.count( a ) ) {
        if( int( q.size( ) ) == p ) {
          in_queue_fifo.erase( q.front( ) );
          q.pop( );
          ans_fifo++;
        }
        q.push( a );
        in_queue_fifo.insert( a );
      }
      if( !in_queue_lru.count( a ) ) {
        if( int( pq.size( ) ) == p ) {
          in_queue_lru.erase( ( *pq.begin( ) ).SE );
          pq.erase( pq.begin( ) );
          ans_lru++;
        }
        in_queue_lru.insert( a );
      }
      else {
        pq.erase( { last_pos[ a ], a } );
      }
      pq.insert( { i, a } );
      last_pos[ a ] = i;
    }
    if( ans_fifo > ans_lru ) {
      cout << "yes";
    }
    else {
      cout << "no";
    }
    cout << " " << ans_fifo << " " << ans_lru << "\n";
  }

  return 0;
}