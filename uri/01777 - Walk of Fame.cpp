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

const int MAXN = int( 1e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

struct Event { int t, x; };
bool cmp_event( const Event& a, const Event& b ) {
  if( a.x != b.x ) return a.x < b.x;
  return a.t < b.t;
}

int n_test;
int n, c, e;
Event event[ MAXN ];

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

  for( int tc = 1; n_test--; tc++ ) {
    e = 0;
    cin >> n >> c;
    for( int i = 0; i < c; i++ ) {
      int a, b; cin >> a >> b;
      event[ e++ ] = { 1, a };
      event[ e++ ] = { 3, b };
    }
    int q; cin >> q;
    for( int i = 0; i < q; i++ ) {
      int a; cin >> a;
      event[ e++ ] = { 2, a };
    }
    sort( event, event+e, cmp_event );
    int ans = 0, cur = 0;
    for( int i = 0; i < e; i++ ) {
      if( event[ i ].t == 1 ) cur++;
      if( event[ i ].t == 2 ) ans += ( cur > 0 );
      if( event[ i ].t == 3 ) cur--;
    }
    cout << "Caso #" << tc << ": " << ans << "\n";
  }

  return 0;
}