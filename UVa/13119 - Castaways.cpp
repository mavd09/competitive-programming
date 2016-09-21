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
const int MOD = int( 1e9+7 );
const int oo  = int( 1e8 );

bool cmp_rectangles( const pii& a, const pii& b ) {
  return a.FI*a.SE > b.FI*b.SE;
}

int get_area_triangle( int a, int b, int c ) {
  double s = ( a+b+c )/2.0;
  double area = sqrt( s*( s-a )*( s-b )*( s-c ) );
  return int( area );
}

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n;

  while( cin >> n ) {
    vi stick( n ), cnt( MX );
    for( auto& e : stick ) {
      cin >> e;
      cnt[ e ]++;
    }
    int ans = 0;
    sort( stick.begin( ), stick.end( ) );
    stick.resize( unique( stick.begin( ), stick.end( ) )-stick.begin( ) );
    n = int( stick.size( ) );
    vpii rectangle;
    for( int i = 0; i < n; i++ ) {
      if( cnt[ stick[ i ] ] < 2 ) {
        continue;
      }
      if( cnt[ stick[ i ] ] >= 4 ) {
        rectangle.PB( { stick[ i ], stick[ i ] } );
        ans = max( ans, stick[ i ]*stick[ i ] );
      }
      for( int j = i+1; j < n; j++ ) {
        if( cnt[ stick[ j ] ] < 2 ) {
          continue;
        }
        rectangle.PB( { stick[ i ], stick[ j ] } );
        ans = max( ans, stick[ i ]*stick[ j ] );
      }
    }
    sort( rectangle.begin( ), rectangle.end( ), cmp_rectangles );
    for( int i = 0; i < n; i++ ) {
      if( cnt[ stick[ i ] ] == 0 ) {
        continue;
      }
      cnt[ stick[ i ] ]--;
      for( int j = i; j < n; j++ ) {
        if( cnt[ stick[ j ] ] == 0 ) {
          continue;
        }
        cnt[ stick[ j ] ]--;
        for( int k = j; k < n; k++ ) {
          if( cnt[ stick[ k ] ] == 0 ) {
            continue;
          }
          cnt[ stick[ k ] ]--;
          int area_triangle = get_area_triangle( stick[ i ], stick[ j ], stick[ k ] );
          ans = max( ans, area_triangle );
          for( auto& r : rectangle ) {
            if( ( r.FI == r.SE && cnt[ r.FI ] >= 4 ) || ( r.FI != r.SE && cnt[ r.FI ] >= 2 && cnt[ r.SE ] >= 2 ) ) {
              ans = max( ans, area_triangle+( r.FI*r.SE ) );
              break;
            }
          }
          cnt[ stick[ k ] ]++;
        }
        cnt[ stick[ j ] ]++;
      }
      cnt[ stick[ i ] ]++;
    }
    cout << ans << "\n";
  }

  return 0;
}