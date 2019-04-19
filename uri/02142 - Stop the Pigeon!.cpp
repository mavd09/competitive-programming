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

int get_tam( int x ) {
  if( x < 10 ) return 1;
  if( x < 100 ) return 2;
  if( x < 1000 ) return 3;
  if( x < 10000 ) return 4;
  if( x < 100000 ) return 5;
  if( x < 1000000 ) return 6;
  return 7;
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  vi dx = { 0, 1, 0, -1 };
  vi dy = { 1, 0, -1, 0 };

  int n, m;

  for( int tc = 1; cin >> n >> m; tc++ ) {
    if( 3*m > n ) {
      cout << "Raios! Raios Duplos! Raios Triplos!\n";
      continue;
    }
    int d = sqrt( n );
    vvi v( d, vi( d ) );
    int i = 0, j = 0, delta = 0, ni, nj;
    for( int it = n; it >= 1; it-- ) {
      v[ i ][ j ] = it;
      while( it > 1 ) {
        ni = i+dx[ delta ];
        nj = j+dy[ delta ];
        if( ni < 0 || ni >= d || nj < 0 || nj >= d || v[ ni ][ nj ] != 0 ) {
          delta = ( delta+1 )%4;
          continue;
        }
        i = ni; j = nj;
        break;
      }
    }
    int tam = get_tam( n );
    for( int i = 0; i < d; i++ ) {
      for( int j = 0; j < d; j++ ) {
        if( v[ i ][ j ] == 3*m ) cout << setw( tam ) << "!";
        else if( v[ i ][ j ] == 2*m ) cout << setw( tam ) << "*";
        else cout << setw( tam ) << v[ i ][ j ];
        if( !( i+1 == d && j+1 == d ) ) cout << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}