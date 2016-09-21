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
typedef vector< double >    vd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;

const int MAX = int( 1e5+1 );
const int MOD = int( 1e9+7 );
const int oo  = int( 1e8 );

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 ); cout.tie( 0 );

  int n_test;
  cin >> n_test;

  while( n_test-- ) {
    int n; cin >> n;
    vi coins( n );
    int sum = 0;
    for( auto& e : coins ) {
      cin >> e;
      sum += e;
    }
    vvb dp( n+1, vb( sum+1 ) );
    dp[ 0 ][ 0 ] = true;
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j+coins[ i ] <= sum; j++ ) {
        dp[ i+1 ][ j ] = dp[ i+1 ][ j ]|dp[ i ][ j ];
        if( j+coins[ i ] <= sum ) {
          dp[ i+1 ][ j+coins[ i ] ] = dp[ i+1 ][ j+coins[ i ] ]|dp[ i ][ j ];
        }
      }
    }
    int ans = oo;
    for( int j = 0; j <= sum; j++ ) {
      if( dp[ n ][ j ] ) {
        ans = min( ans, abs( sum-2*j ) );
      }
    }
    cout << ans << "\n";
  }

  return 0;
}