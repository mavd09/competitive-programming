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

  int n;

  for( int tc = 1; cin >> n; tc++ ) {
    map< string, int > cnt;
    string line;
    while( getline( cin, line ) ) {
      if( line == "EndOfText" ) break;
      string cur = "";
      for( auto& c : line ) {
        if( ( 'A' <= c && c <= 'Z' ) || ( 'a' <= c && c <= 'z' ) )
          cur += tolower( c );
        else {
          if( cur != "" ) cnt[ cur ]++;
          cur = "";
        }
      }
      if( cur != "" ) cnt[ cur ]++;
    }
    if( tc > 1 ) cout << "\n";
    vector< string > ans;
    for( auto& e : cnt ) {
      if( e.SE == n ) 
        ans.PB( e.FI );
    }
    sort( ans.begin( ), ans.end( ) );
    if( ans.empty( ) )
      cout << "There is no such word.\n";
    else {
      for( auto& w : ans )
        cout << w << "\n";
    }
  }

  return 0;
}