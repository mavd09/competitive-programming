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

const int MAXN = int( 2e2 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, m;
map< string, int > id;
vpii graph[ MAXN ];

int min_dist[ MAXN ];
int min_cost[ MAXN ];

void init( ) {
  id.clear( );
  for( int i = 0; i < MAXN; ++i ) {
    graph[ i ].clear( );
    min_cost[ i ] = oo;
    min_dist[ i ] = -1;
  }
}

int add( string s ) {
  if( !id.count( s ) ) {
    id[ s ] = SIZE( id )-1;
  }
  return id[ s ];
}

int solve( int u ) {
  queue< int > q;
  q.push( u );
  min_cost[ u ] = 0;
  min_dist[ u ] = 0;
  while( !q.empty( ) ) {
    int u = q.front( ); q.pop( );
    for( auto& e : graph[ u ] ) {
      int v = e.FI, c = e.SE;
      if( min_dist[ v ] == -1 ) {
        min_dist[ v ] = min_dist[ u ]+1;
        q.push( v );
      }
      if( min_dist[ u ]+1 == min_dist[ v ] ) {
        min_cost[ v ] = min( min_cost[ v ], c );
      }
    }
  }
  int ans = 0;
  for( int i = 0; i < n; ++i ) {
    if( min_dist[ i ] == -1 ) {
      return -1;
    }
    ans += min_cost[ i ];
  }
  return ans;
}

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

  while( cin >> n >> m ) {
    init( );
    for( int i = 0; i < n; ++i ) {
      string s; cin >> s;
      add( s );
    }
    int fr = add( "English" );
    for( int i = 0; i < m; ++i ) {
      string u, v; int c; cin >> u >> v >> c;
      int uu = add( u ), vv = add( v );
      graph[ uu ].PB( { vv, c } );
      graph[ vv ].PB( { uu, c } );
    }
    int ans = solve( fr );
    if( ans == -1 ) {
      cout << "Impossible\n";
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}