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

#define x( P )              real( P )
#define y( P )              imag( P )
#define cross( A, B )       y( conj(A)*(B) )
#define dot( A, B )         x( conj(A)*(B) )

const int MX  = int( 1e6 );
const ll  mod = int( 1e9 )+7;
const lf  oo  = 1e18;

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n_test; cin >> n_test;

  while( n_test-- ) {
    int n, m; cin >> n >> m;
    vvb ok( n+1,  vb( ( 1<<n ), false ) );
    fill( ok[ 0 ].begin( ), ok[ 0 ].end( ), true );
    for( int i = 0; i < m; i++ ) {
      int x; cin >> x; x--;
      ok[ 0 ][ x ] = false;
    }
    
    int ans = 0;
    for( int i = (1<<n)/2, id = 0; i >= 1; i /= 2, id++ ) {
      for( int j = 0; j < i; j++ ) {
        if( ( ok[ id ][ 2*j ] && !ok[ id ][ 2*j+1 ] ) || ( !ok[ id ][ 2*j ] && ok[ id ][ 2*j+1 ] ) ) {
          ans++;
        }
        ok[ id+1 ][ j ] = ok[ id ][ 2*j ]|ok[ id ][ 2*j+1 ];
      }
    }
    cout << ans << "\n";
  }

  return 0;
}