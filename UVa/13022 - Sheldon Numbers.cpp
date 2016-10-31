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
const int oo  = 1e8;

vll precompute( ) {
  set< ll > sheldon_numbers;
  for( int ones = 1; ones <= 64; ones++ ) {
    for( int zeros = 1; zeros+ones <= 64; zeros++ ) {
      ll cur = ( 1LL<<ones )-1LL;
      sheldon_numbers.insert( cur );
      int sz = ones;
      while( true ) {
        if( sz+zeros <= 64 ) {
          cur <<= zeros;
          sz += zeros;
          sheldon_numbers.insert( cur );
        }
        else {
          break;
        }
        if( sz+ones <= 64 ) {
          cur <<= ones;
          cur |= ( 1LL<<ones )-1LL;
          sz += ones;
          sheldon_numbers.insert( cur );
        }
        else {
          break;
        }
      }
    }
  }
  vll all( sheldon_numbers.begin( ), sheldon_numbers.end( ) );
  return all;
}

int f( vll& all, ll x ) {
  int ans = upper_bound( all.begin( ), all.end( ), x )-all.begin( )-1;
  return max( 0, ans );
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  vll all = precompute( );

  ll x, y;

  while( cin >> x >> y ) {
    cout << f( all, y )-f( all, x-1 ) << "\n";
  }

  return 0;
}