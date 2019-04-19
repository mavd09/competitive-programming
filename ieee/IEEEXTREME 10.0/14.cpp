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
const int oo  = int( 2e9 );

int get_value( string& symbols, char c ) {
  for( int i = 0; i < int( symbols.size( ) ); i++ ) {
    if( symbols[ i ] == c ) {
      return i;
    }
  }
  return 0;
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

  int b;
  string symbols;
  cin >> b >> symbols;
  cin.ignore( );
  string x, y, z, w;
  getline( cin, x );
  getline( cin, y );
  getline( cin, z );
  getline( cin, w );

  int carry = 0;
  for( int i = int( x.size( ) )-1; i >= 0; i-- ) {
    if( x[ i ] == '+' || y[ i ] == '+' ) {
      break;
    } 
    int n = get_value( symbols, x[ i ] ), m = get_value( symbols, y[ i ] );
    int r = n+m+carry;
    w[ i ] = ( symbols[ r%b ] );
    carry = r/b;
  }
  if( carry ) {
    w[ 0 ] = ( symbols[ carry ] );
  }

  cout << b << " " << symbols << "\n";
  cout << x << "\n";
  cout << y << "\n";
  cout << z << "\n";
  cout << w << "\n";

  return 0;
}