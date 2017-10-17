#include <bits/stdc++.h>

using namespace std;

const int MAXN = int( 3e4 )+10;
const int MAXM = int( 2e5 )+10;
const int MAXA = int( 1e6 )+10;

int B;

int n, m;
int arr[ MAXN ], q[ MAXM ];
int b[ MAXM ];
int f[ MAXM ], t[ MAXM ];

int ans[ MAXM ];

int cnt;
int val[ MAXA ];

bool cmp( const int& idx1, const int& idx2 ) {
  if( b[ idx1 ] != b[ idx2 ] ) {
    return b[ idx1 ] < b[ idx2 ];
  }
  return t[ idx1 ] < t[ idx2 ];
}

inline void add( int x ) {
  if( val[ x ] == 0 ) {
    ++cnt;
  }
  val[ x ]++;
}

inline void del( int x ) {
  if( val[ x ] == 1 ) {
    --cnt;
  }
  val[ x ]--;
}

int main( ) {

  scanf( "%d", &n );
  B = sqrt( n );
  for( int i = 0; i < n; ++i ) {
    scanf( "%d", &arr[ i ] );
  }
  scanf( "%d", &m );
  for( int i = 1; i <= m; ++i ) {
    scanf( "%d %d", &f[ i ], &t[ i ] );
    q[ i ] = i;
    ans[ i ] = 0;
    b[ i ] = f[ i ]/B;
  }
  sort( q, q+m );
  for( int i = 0, l = 1, r = 0; i < m; ++i ) {
    while( r < t[ q[ i ] ] ) add( arr[ ++r ] );
    while( l > f[ q[ i ] ] ) add( arr[ --l ] );
    while( r > t[ q[ i ] ] ) del( arr[ r-- ] );
    while( l < f[ q[ i ] ] ) del( arr[ l++ ] );
    ans[ q[ i ] ] = cnt;
  }
  for( int i = 0; i < m; ++i ) {
    printf( "%d\n", ans[ i ] );
  }

  return 0;
}