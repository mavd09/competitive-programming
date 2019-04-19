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

  int n;

  while( cin >> n ) {
    int n_cds; cin >> n_cds;
    vb dp( n+1 );
    vi prv( n+1 );
    dp[ 0 ] = true;
    for( int k = 0; k < n_cds; k++ ) {
      int t; cin >> t;
      for( int i = n-t; i >= 0; i-- ) {
        if( dp[ i ] && !dp[ i+t ] ) {
          dp[ i+t ] = true;
          prv[ i+t ] = t;
        }
      }
    }
    int sum = n;
    while( !dp[ sum ] ) {
      sum--;
    }
    int cur = sum;
    while( cur != 0 ) {
      cout << prv[ cur ] << " ";
      cur -= prv[ cur ];
    }
    cout << "sum:" << sum << "\n";
  }

  return 0;
}