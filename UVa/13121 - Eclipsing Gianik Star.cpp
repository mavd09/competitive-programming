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
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;
typedef vector< pii >       vpii;

const int MX  = 257;
const int MOD = int( 360 );
const int oo  = int( 1e8 );

int extended_euclid( int a, int b, int& x, int& y ) {
  int xx = y = 0;
  int yy = x = 1;
  while( b ) {
    int q = a/b;
    int t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

int mod_inverse( int a, int n ) {
  int x, y;
  int g = extended_euclid( a, n, x, y );
  if( g > 1 ) {
    return -1;
  }
  return ( x%n + n )%n;
}

bool linear_diophantine( int a, int b, int c, int& x, int& y ) {
  int d = __gcd( a, b );
  if( c%d ) {
    return false;
  }
  x = c/d*mod_inverse( a/d, b/d );
  y = ( c-a*x )/b;
  return true;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int mod = 360;

  int n;

  while( cin >> n ) {
    vi rho( n ), alpha( n ), beta( n );
    for( int i = 0; i < n; i++ ) {
      cin >> rho[ i ] >> alpha[ i ] >> beta[ i ];
      alpha[ i ] = ( alpha[ i ]%mod + mod )%mod;
      beta[ i ] = ( beta[ i ]%mod + mod )%mod;
    }
    int ans = -1;
    for( int i = 0; i < n; i++ ) {
      for( int j = i+1; j < n; j++ ) {
        int a = ( ( alpha[ j ]-alpha[ i ] )%mod + mod )%mod;
        int b = ( ( beta[ i ]-beta[ j ] )%mod + mod )%mod;
        int t, k;
        if( !linear_diophantine( b, 360, a, t, k ) ) {
          continue;
        }
        int nmod = 360/__gcd( b, 360 );
        t = ( t%nmod + nmod )%nmod;
        if( ans == -1 || t < ans ) {
          ans = t;
        }
      }
    }
    if( ans == -1 ) {
      cout << "GIANIK IS NEVER ECLIPSED\n";
    }
    else {
      cout << ans << "\n";
    }
  }

  return 0;
}