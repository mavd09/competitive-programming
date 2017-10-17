#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 4e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int arr[ MAXN ];

int cost[ MAXN ][ MAXN ];
int dp[ MAXN ][ MAXN ];

int calc( int i, int j ) {
  if( j < i ) {
    return 0;
  }
  return cost[ i ][ j ];
}

int go( int i, int j ) {
  if( j == n ) {
    return calc( i, j-1 );
  }
  int& r = dp[ i ][ j ];
  if( r != -1 ) {
    return r;
  }
  return r = min( go( i, j+1 ), calc( i, j-1 )+go( j, j+1 ) );
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( ".in", "r", stdin );
    //freopen( ".out", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  while( cin >> n ) {
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
    }
    for( int i = 0; i < n; ++i ) {
      int t = arr[ i ]+1800;
      int c = 120;
      for( int j = i; j < n; ++j ) {
        if( arr[ j ] <= t ) {
          t += 20;
          c += 20;
        } else {
          c += arr[ j ]-t;
          t = arr[ j ]+20;
          c += 20;
        }
        cost[ i ][ j ] = c;
      }
    }
    memset( dp, -1, sizeof( dp ) );
    cout << go( 0, 1 ) << '\n';
  }

  return 0;
}