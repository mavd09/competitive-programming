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
const ll mod  = ll( 1e9 )+7;
const int oo  = int( 2e9 );

ll go( vvll& dp, string& s, int& t, int i, int n ) {
  if( i >= t ) {
    if( n ) {
      return 0;
    }
    return 1;
  }
  ll& r = dp[ i ][ n ];
  if( r != -1 ) {
    return r;
  }
  r = 0;
  int j = int( s.size( ) )-i-1;
  if( i == j ) {
    r = ( r+go( dp, s, t, i+1, n ) )%mod;
    if( n ) {
      r = ( r+go( dp, s, t, i+1, n-1 )*25LL )%mod;
    }
  }
  else {
    if( s[ i ] == s[ j ] ) {
      r = ( r+go( dp, s, t, i+1, n ) )%mod;
      if( n >= 2 ) {
        r = ( r+go( dp, s, t, i+1, n-2 )*25LL )%mod;
      }
    }
    else {
      if( n ) {
        r = ( r+go( dp, s, t, i+1, n-1 )*2LL )%mod;
      }
      if( n >= 2 ) {
        r = ( r+go( dp, s, t, i+1, n-2 )*24LL )%mod;
      }
    }
  }
  return r;
}

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

  int n_test; cin >> n_test;

  while( n_test-- ) {
    int n, t; string s;
    cin >> n >> s;
    t = int( s.size( ) )+1;
    t /= 2;
    vvll dp( int( s.size( ) ), vll( n+1, -1 ) );
    cout << go( dp, s, t, 0, n ) << "\n";
  }

  return 0;
}