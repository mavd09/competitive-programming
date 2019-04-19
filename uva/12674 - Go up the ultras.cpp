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
const int oo  = int( 2e7 );

const int LOG2 = 22;

struct Sparse_Table {
  int n;
  vvi st;
  Sparse_Table( int& n, vi& h ) : n( n ), st( n, vi( LOG2, oo ) ) {
    for( int i = 0; i < n; i++ ) {
      st[ i ][ 0 ] = h[ i ];
    }
    for( int j = 1; j < LOG2; j++ ) {
      for( int i = 0; i+(1<<(j-1)) < n; i++ ) {
        st[ i ][ j ] = min( st[ i ][ j-1 ], st[ i+(1<<(j-1)) ][ j-1 ] );
      }
    }
  }
  int query( int f, int t ) {
    int j = 31-__builtin_clz( t-f+1 );
    return min( st[ f ][ j ], st[ t-(1<<j)+1 ][ j ] );
  }
};

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

  int n;

  while( cin >> n ) {
    vi h( n );
    for( int i = 0; i < n; i++ ) {
      cin >> h[ i ];
    }
    Sparse_Table st( n, h );
    vi nearest_left( n ), nearest_right( n );
    stack< int > s;
    for( int i = 0; i < n; i++ ) {
      while( !s.empty( ) && h[ s.top( ) ] <= h[ i ] ) {
        s.pop( );
      }
      nearest_left[ i ] = i;
      if( !s.empty( ) ) {
        nearest_left[ i ] = s.top( );
      }
      s.push( i );
    }
    while( !s.empty( ) ) {
      s.pop( );
    }
    for( int i = n-1; i >= 0; i-- ) {
      while( !s.empty( ) && h[ s.top( ) ] <= h[ i ] ) {
        s.pop( );
      }
      nearest_right[ i ] = i;
      if( !s.empty( ) ) {
        nearest_right[ i ] = s.top( );
      }
      s.push( i );
    }
    bool is_first = true;
    for( int i = 1; i+1 < n; i++ ) {
      if( h[ i-1 ] < h[ i ] && h[ i ] > h[ i+1 ] ) {
        int best = 0;
        if( nearest_left[ i ] != i ) {
          best = max( best, st.query( nearest_left[ i ], i ) );
        }
        if( nearest_right[ i ] != i ) {
          best = max( best, st.query( i, nearest_right[ i ] ) );
        }
        if( h[ i ]-best >= 150000 ) {
          if( !is_first ) {
            cout << " ";
          }
          cout << i+1;
          is_first = false;
        }
      }
    }
    cout << "\n";
  }

  return 0;
}