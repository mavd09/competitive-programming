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

  ll mod = ll( 1e6 )+7;

  int n_test;
  cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    ll k, c;
    int n;
    cin >> k >> c >> n;
    vll a( n );
    cin >> a[ 0 ];
    for( int i = 1; i < n; i++ ) {
      a[ i ] = ( k*a[ i-1 ] + c )%mod;
    }
    sort( a.begin( ), a.end( ) );
    ll ans = 0, acc = 0;
    for( int i = 0; i < n; i++ ) {
      ans += ( ( ll( i )*a[ i ] ) - acc );
      acc += a[ i ];
    }
    cout << "Case " << tc << ": " << ans << "\n";
  }

  return 0;
}