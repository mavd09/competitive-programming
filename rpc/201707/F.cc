#include <bits/stdc++.h>

using namespace std;

const int MAX  = int( 1e3 )+10;
const int MAXN = int( 1e2 )+10;
const int oo   = INT_MAX;

int n, tc;
int arr[ MAXN ];

int seen[ MAXN ][ MAXN ];
int dp[ MAXN ][ MAXN ];

inline int add( int a, int b ) { return ( a+b >= n ? a+b-n : a+b ); }

int go( int f, int t ) {
  if( add( f, 1 ) == t ) {
    return 0;
  }
  int& r = dp[ f ][ t ];
  if( seen[ f ][ t ] == tc ) {
    return r;
  }
  seen[ f ][ t ] = tc;
  r = oo;
  for( int i = add( f, 1 ); i != t; i = add( i, 1 ) ) {
    r = min( r, go( f, i )+go( i, t )+__gcd( arr[f], arr[t] ) );
  }
  return r;
}

int main( ) {

  for( tc = 1; scanf( "%d", &n ) == 1; ++tc ) {
    if( n == 0 ) {
      break;
    }
    for( int i = 0; i < n; ++i ) {
      scanf( "%d", &arr[ i ] );
    }
    for( int i = 0; i < n; ++i ) {
      dp[ i ][ add( i, 1 ) ] = 0;
    }
    for( int len = 2; len < n; ++len ) {
      for( int i = 0; i < n; ++i ) {
        int j = (i+len)%n;
        int& r = dp[ i ][ j ];
        r = oo;
        for( int k = add( i, 1 ); k != j; k = add( k, 1 ) ) {
          r = min( r, dp[ i ][ k ]+dp[ k ][ j ]+__gcd( arr[i], arr[j] ) );
        }
      }
    }
    int ans = oo;
    for( int i = 0; i < n; ++i ) {
      for( int j = i+1; j < n; ++j ) {
        ans = min( ans, dp[ i ][ j ]+dp[ j ][ i ]+__gcd( arr[i], arr[j] ) );
      }
    }
    printf( "%d\n", ans );
  }

  return 0;
}