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
const ll  mod = ( 1LL<<31 )-1LL;
const int oo  = 1e8;

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n, m;

  for( int tc = 0; ( cin >> n >> m ); tc++ ) {
    vi cnt( n+m+1 );
    for( int i = 1; i <= n; i++ ) {
      for( int j = 1; j <= m; j++ ) {
        cnt[ i+j ]++;
      }
    }
    int mx = 0;
    for( int i = 0; i <= n+m; i++ ) {
      mx = max( mx, cnt[ i ] );
    }
    if( tc ) {
      cout << "\n";
    }
    for( int i = 0; i <= n+m; i++ ) {
      if( cnt[ i ] == mx ) {
        cout << i << "\n";
      }
    }
  }

  return 0;
}