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

const int MX  = 123;
const int MOD = int( 360 );
const lf  oo  = 1e18;

void kmp( vvb& mark, int& id, int& total, int& cnt, string& t, string& p ) {
  int nid = 1-id;
  fill( mark[ nid ].begin( ), mark[ nid ].end( ), false );
  vector< int > phi( int( p.size( ) )+1 );
  int k;
  phi[ 0 ] = k = -1;
  for( int i = 1; i <= int( p.size( ) ); i++ ) {
    while( k > -1 && p[ k ] != p[ i-1 ] ) {
      k = phi[ k ];
    }
    phi[ i ] = ++k;
  }
  k = 0;
  for( int i = 0; i < int( t.size( ) ); i++ ) {
    while( k > -1 && p[ k ] != t[ i ] ) {
      k = phi[ k ];
    }
    k++;
    if( k == int( p.size( ) ) ) {
      int pos = i-int( p.size( ) )-cnt;
      if( ( total == 0 && pos == -1 ) || ( pos >= 0 && mark[ id ][ pos ] ) ) {
        mark[ nid ][ i ] = true;
      } 
      k = phi[ k ];
    }
  }
  total++; id = nid; cnt = 0; p = "";
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  string t, p;

  while( cin >> t >> p ) {
    vvb mark( 2, vb( int( t.size( ) ) ) );
    fill( mark[ 0 ].begin( ), mark[ 0 ].end( ), true );
    int id = 0;
    string cur = "";
    int cnt = 0, total = 0;
    for( auto& c : p ) {
      if( c == '?' ) {
        if( cur != "" ) {
          kmp( mark, id, total, cnt, t, cur );
        }
        cnt++;
      }
      else {
        cur += c;
      }
    }
    if( cur != "" ) {
      kmp( mark, id, total, cnt, t, cur );
    }
    int ans = 0;
    for( int i = 0; i < int( t.size( ) ); i++ ) {
      int pos = i-cnt;
      if( ( total == 0 && pos == -1 ) || ( pos >= 0 && mark[ id ][ pos ] ) ) {
        ans++;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}