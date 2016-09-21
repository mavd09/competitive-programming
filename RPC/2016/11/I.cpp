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

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int n;

  while( cin >> n ) {
    vi a( n );
    vi max_left( n ), max_right( n );
    for( auto& e : a )
      cin >> e;
    max_left[ 0 ] = ( a[ 0 ] ? 1 : 0 );
    for( int i = 1; i < n; i++ )
      max_left[ i ] = min( max_left[ i-1 ]+1, a[ i ] );
    max_right[ n-1 ] = ( a[ n-1 ] ? 1 : 0 );
    for( int i = n-2; i >= 0; i-- )
      max_right[ i ] = min( max_right[ i+1 ]+1, a[ i ] );
    max_right.PB( 0 );
    int ans = 0;
    for( int i = 0; i < n; i++ ) {
      ans = max( ans, min( max_left[ i ], max_right[ i+1 ]+1 ) );
    }
    cout << ans << "\n";
  }

  return 0;
}