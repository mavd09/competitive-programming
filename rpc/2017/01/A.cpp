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

typedef complex< lf >       pt;

const int MAXN = int( 1e3 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

const int dx[ ] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
const int dy[ ] = { -1, 0, 1, 1, 0, -1, -1, 0, 1 };

int n, m, b;
ll board[ 2 ][ MAXN ][ MAXN ];

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

  while( cin >> m >> n >> b ) {
    ll pot = 1;
    for( int i = 1; i <= b; i++ )
      pot *= 9LL;
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < m; j++ ) {
        cin >> board[ 0 ][ i ][ j ];
        board[ 0 ][ i ][ j ] *= pot;
      }
    }
    int id = 0;
    for( int it = 0; it < b; it++ ) {
      for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < m; j++ ) {
          board[ 1-id ][ i ][ j ] = 0;
          for( int k = 0; k < 9; k++ ) {
            int ni = ( i+dx[ k ]+n )%n;
            int nj = ( j+dy[ k ]+m )%m;
            board[ 1-id ][ i ][ j ] +=  board[ id ][ ni ][ nj ];
          }
          board[ 1-id ][ i ][ j ] /= 9LL;
        }
      }
      id = 1-id;
    }
    set< ll > all;
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < m; j++ ) {
        all.insert( board[ id ][ i ][ j ] );
      }
    }
    cout << SIZE( all ) << "\n";
  }

  return 0;
}
