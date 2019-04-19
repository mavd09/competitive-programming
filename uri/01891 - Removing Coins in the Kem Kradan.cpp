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

const int MAXN = int( 2e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n_test;
int n;
bool st[ MAXN ];

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  cin >> n_test;

  while( n_test-- ) {
    cin >> n;
    memset( st, false, sizeof( st ) );
    int lst = 0;
    vi ans;
    for( int i = 0; i < n; i++ ) {
      char c; cin >> c;
      if( c == 'D' )
        st[ i ] ^= true;
      if( st[ i ] ) {
        for( int j = i; j >= lst; j-- )
          ans.PB( j+1 );
        lst = i+1;
        st[ i+1 ] ^= true;
      }
    }
    if( st[ n-1 ] ) {
      cout << "Y\n" << ans[ 0 ];
      for( int i = 1; i < n; i++ )
        cout << " " << ans[ i ];
      cout << "\n";
    }
    else cout << "N\n";
  }

  return 0;
}