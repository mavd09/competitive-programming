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
const ll  oo  = ll( 1e18 );

bool read_input( vll& v ) {
  ll sum = 0;
  for( int i = 0; i < 6; i++ ) {
    cin >> v[ i ];
    sum += v[ i ];
  }
  return ( sum > 0 );
}

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

  vll v( 6 );

  while( read_input( v ) ) {
    int ans = v[ 5 ], delta;
    
    delta = min( v[ 4 ]*11LL, v[ 0 ] );
    v[ 0 ] -= delta;
    ans += v[ 4 ];
  
    delta = min( v[ 3 ]*5LL, v[ 1 ] );
    v[ 1 ] -= delta;
    delta = min( (v[ 3 ]*5LL-delta)*4LL, v[ 0 ] );
    v[ 0 ] -= delta;
    ans += v[ 3 ];

    ans += v[ 2 ]/4LL;
    v[ 2 ] %= 4LL;
    if( v[ 2 ] == 1 ) {
      delta = min( 5LL, v[ 1 ] );
      v[ 1 ] -= delta;
      delta = min( (5-delta)*4LL + 7LL, v[ 0 ] );
      v[ 0 ] -= delta;
      ans++;
    }
    if( v[ 2 ] == 2 ) {
      delta = min( 3LL, v[ 1 ] );
      v[ 1 ] -= delta;
      delta = min( (3-delta)*4LL + 6LL, v[ 0 ] );
      v[ 0 ] -= delta;
      ans++;
    }
    if( v[ 2 ] == 3 ) {
      delta = min( 1LL, v[ 1 ] );
      v[ 1 ] -= delta;
      delta = min( (1-delta)*4LL + 5LL, v[ 0 ] );
      v[ 0 ] -= delta;
      ans++;
    }

    ans += v[ 1 ]/9LL;
    v[ 1 ] %= 9LL;
    if( v[ 1 ] ) {
      delta = min( (9LL-v[ 1 ])*4, v[ 0 ] );
      ans++; v[ 0 ] -= delta;
    }

    ans += v[ 0 ]/36LL;
    if( v[ 0 ]%36LL ) ans++;

    cout << ans << "\n"; 

  }

  return 0;
}