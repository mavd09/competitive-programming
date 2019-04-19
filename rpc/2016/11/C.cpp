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

struct State { int cost; vi v; };
struct Cmp_State {
  bool operator ( ) ( const State& x, const State& y ) {
    return x.cost > y.cost;
  }  
};

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  vi a( 8 ), b( 8 );

  while( cin >> a[ 0 ] ) {
    for( int i = 1; i < 8; i++ )
      cin >> a[ i ];
    for( int i = 0; i < 8; i++ )
      cin >> b[ i ];
    set< vi > used;
    priority_queue< State, vector< State >, Cmp_State > pq;
    pq.push( { 0, a } );
    while( !pq.empty( ) ) {
      State cur = pq.top( ); pq.pop( );
      if( used.count( cur.v ) )
        continue;
      used.insert( cur.v );
      if( cur.v == b ) {
        cout << cur.cost << "\n";
        break;
      }
      for( int i = 0; i+1 < 4; i++ ) {
        for( int d = 0; d <= 4; d += 4 ) {
          swap( cur.v[ i+d ], cur.v[ i+d+1 ] );
          cur.cost += cur.v[ i+d ]+cur.v[ i+d+1 ];
          if( !used.count( cur.v ) )
            pq.push( cur );
          cur.cost -= cur.v[ i+d ]+cur.v[ i+d+1 ];
          swap( cur.v[ i+d ], cur.v[ i+d+1 ] );
        }
      }
      for( int i = 0; i < 4; i++ ) {
        swap( cur.v[ i ], cur.v[ i+4 ] );
        cur.cost += cur.v[ i ]+cur.v[ i+4 ];
        if( !used.count( cur.v ) )
          pq.push( cur );
        cur.cost -= cur.v[ i ]+cur.v[ i+4 ];
        swap( cur.v[ i ], cur.v[ i+4 ] );
      }
    }
  }

  return 0;
}