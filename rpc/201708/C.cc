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

const int MAXN = int( 2e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m, x, y;
int deg[ MAXN ];
vi graph[ MAXN ];

void init( ) {
  for( int i = 0; i < n; ++i ) {
    graph[ i ].clear( );
    deg[ i ] = 0;
  }
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

  while( cin >> n >> m >> x >> y ) {
    x--; y--;
    #ifdef LOCAL
      init( );
    #endif
    for( int i = 0; i < m; ++i ) {
      int u, v; cin >> u >> v; --u; --v;
      graph[ u ].PB( v );
      graph[ v ].PB( u );
      deg[ u ]++;
      deg[ v ]++;
    }
    queue< int > q;
    q.push( y );
    deg[ y ] = -1;
    while( !q.empty( ) ) {
      int u = q.front( ); q.pop( );
      for( auto& v : graph[ u ] ) {
        if( deg[ v ] == -1 ) {
          continue;
        }
        deg[ v ]--;
        if( deg[ v ] <= SIZE( graph[ v ] )/2 ) {
          q.push( v );
          deg[ v ] = -1;
        }
      }
    }
    if( deg[ x ] == -1 ) {
      cout << "leave\n";
    } else {
      cout << "stay\n";
    }
  }
 
  return 0;
}