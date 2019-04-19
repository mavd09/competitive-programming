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
typedef vector< ll >        vi;
typedef vector< vi >        vvi;
typedef vector< vvi >       vvvi;
typedef vector< vvvi >      vvvvi;
typedef vector< pii >       vpii;
typedef vector< vpii >      vvpii;

typedef complex< lf >       pt;

const int MX  = 123;
const ll  mod = ( 1LL<<31 )-1LL;
const int oo  = 1e8;

bool can( int f1, int e1, int f2, int e2 ) {
  if( f1 > e1 ) {
    swap( f1, e1 );
  }
  if( f2 > e2 ) {
    swap( f2, e2 );
  }
  return (  ( f1 <= f2 && f2 <= e1 && f1 <= e2 && e2 <= e1 ) ||
            ( f2 <= f1 && f1 <= e2 && f2 <= e1 && e1 <= e2 ) ) &&
            abs( f2-e2 ) >= 1;
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n;

  while( cin >> n ) {
    n++;
    vi v( n );
    for( auto& e : v ) {
      cin >> e;
    }
    vvvi dp( 2, vvi( n+1, vi( n+1, 0 ) ) );
    dp[ 1 ][ v[ 0 ] ][ v[ 1 ] ] = 1;
    int id = 1, nid = 0;
    for( int i = 2; i < n; i++, id = 1-id, nid = 1-nid ) {
      for( int b = 1; b <= n; b++ ) {
        for( int e = v[ i-1 ]; e <= v[ i-1 ]; e++ ) {
          if( dp[ id ][ b ][ e ] == 0 ) {
            continue;
          }
          if( can( b, e, b, v[ i ] ) ) {
            dp[ nid ][ b ][ v[ i ] ] = ( dp[ nid ][ b ][ v[ i ] ]+dp[ id ][ b ][ e ] )%mod;
          }
          if( can( b, e, e, v[ i ] ) ) {
            dp[ nid ][ e ][ v[ i ] ] = ( dp[ nid ][ e ][ v[ i ] ]+dp[ id ][ b ][ e ] )%mod;
          }
          dp[ id ][ b ][ e ] = 0;
        }
      }
    }
    ll ans = 0;
    for( int b = 1; b <= n; b++ ) {
      ans = ( ans+dp[ id ][ b ][ v[ n-1 ] ] )%mod;
    }
    cout << ans << "\n";
  }

  return 0;
}