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

int main( ) {

  //ios_base::sync_with_stdio( 0 );
  //cin.tie( 0 ); cout.tie( 0 );

  int n, x, y;

  while( ( scanf( "%d %d", &n, & x ) == 2 ) && !( n == 0 && x == 0 ) ) {
    vb dp( MAX+1 );
    dp[ 0 ] = true;
    for( int k = 1; k <= n; k++ ) {
      int a, b; scanf( "%d.%d", &a, &b );
      int cur = a*100+b;
      if( k == x ) {
        y = cur;
        continue;
      }
      for( int i = MAX-cur; i >= 0; i-- ) {
        dp[ i+cur ] = dp[ i+cur ]|dp[ i ];
      }
    }
    lf ans = 0;
    for( int i = 0; i+y <= MAX; i++ ) {
      if( dp[ i ] && i+y > 5000 ) {
        ans = lf( y*100 )/lf( i+y );
        break;
      }
    }
    printf( "%.2f\n", double( ans ) );
  }

  return 0;
}