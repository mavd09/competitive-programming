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

typedef complex< lf >       pt;

const int MX  = 257;
const int MOD = int( 360 );
const lf  oo  = 1e18;

istream& operator >> ( istream& in, pt& p ) {
  lf x, y; in >> x >> y;
  p = pt( x, y );
  return in;
}

inline lf dist( pt a, pt b ) {
  return abs( b-a );
}

lf go( int& n, int& k, vvvd& dp, vector< pt >& p, int id, int last, int ig ) {
  if( id == n ) {
    return 0.0;
  }
  if( dp[ id ][ last ][ ig ] > -0.5 ) {
    return dp[ id ][ last ][ ig ];
  }
  lf r = oo;
  if( id != n-1 && id != 0 && ig+1 <= k ) {
    r = min( r, go( n, k, dp, p, id+1, last, ig+1 ) );
  }
  r = min( r, go( n, k, dp, p, id+1, id, ig )+dist( p[ last ], p[ id ] ) );
  return dp[ id ][ last ][ ig ] = r;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  cout << fixed << setprecision( 3 );

  int n, k;

  while( cin >> n >> k ) {
    vector< pt > p( n );
    for( auto& e : p ) {
      cin >> e;
    }
    vvvd dp( n, vvd( n, vd( k+1, -1.0 ) ) );
    cout << go( n, k, dp, p, 0, 0, 0 ) << "\n";
  }

  return 0;
}