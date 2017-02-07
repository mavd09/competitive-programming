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

const int MAX  = int( 100 );
const int MAXN = int( 1e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n_test;
int nf, f[ MAX ], m[ MAXN ];

bool is_valid( int mask ) {
  for( int i = 0; i < nf; i++ ) {
    if( ((mask>>i)&1) && ((mask>>(i+1))&1) )
      return false;
  }
  return true;
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

  f[ nf++ ] = 1; f[ nf++ ] = 2;
  while( true ) {
    if( f[ nf-1 ]+f[ nf-2 ] > 25000 ) break;
    f[ nf ] = f[ nf-1 ]+f[ nf-2 ];
    nf++;
  }

  for( int mask = 0; mask < (1<<nf); mask++ ) {
    if( !is_valid( mask ) ) continue;
    int cur = 0;
    for( int i = 0; i < nf; i++ ) {
      if( (mask>>i)&1 ) 
        cur += f[ i ];
    }
    int nmask = mask>>1, ncur = 0;
    for( int i = 0; i < nf; i++ ) {
      if( (nmask>>i)&1 ) 
        ncur += f[ i ];
    }
    m[ cur ] = ncur;
  }

  cin >> n_test;

  while( n_test-- ) {
    int x; cin >> x;
    cout << m[ x ] << "\n";
  }

  return 0;
}