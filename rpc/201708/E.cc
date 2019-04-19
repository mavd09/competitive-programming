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

const int MAXN = int( 1e4 )+10;
const int MOD  = int( 1e9 )+7;
const ll  oo   = LLONG_MAX;

int n, m, x;
vpii graph[ MAXN ];
ll min_dist[ MAXN ];

void init( ) {
  for( int i = 0; i < n; ++i ) {
    graph[ i ].clear( );
  }
}

ll dijkstra( int f, int t, ll mx ) {
  for( int i = 0; i < n; ++i ) {
    min_dist[ i ] = oo;
  }
  priority_queue< pair< ll, int >, vector< pair< ll, int > >, greater< pair< ll, int > > > pq;
  pq.push( { 0, f } );
  min_dist[ f ] = 0;
  while( !pq.empty( ) ) {
    ll d = pq.top( ).FI;
    int u = pq.top( ).SE;
    pq.pop( );
    if( min_dist[ u ] != d ) {
      continue;
    }
    for( auto& e : graph[ u ] ) {
      int v = e.FI;
      ll w = e.SE;
      if( w <= mx && min_dist[ u ]+w < min_dist[ v ] ) {
        min_dist[ v ] = min_dist[ u ]+w;
        pq.push( { min_dist[ v ], v } );
      }
    }
  }
  return min_dist[ t ];
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

  while( cin >> n >> m >> x ) {
    #ifdef LOCAL
      init( );
    #endif
    for( int i = 0; i < m; ++i ) {
      int u, v, t; cin >> u >> v >> t;
      u--; v--;
      graph[ u ].PB( { v, t } );
      graph[ v ].PB( { u, t } );
    }
    ll lim = dijkstra( 0, n-1, ll( 1e14 ) );
    lim = lim*( 100LL+ll(x) );
    ll lo = 1, hi = ll( 1e14 ), mi;
    while( lo <= hi ) {
      mi = ( lo+hi )>>1;
      ll ans = dijkstra( 0, n-1, mi );
      if( ans == oo || ans*100LL > lim ) {
        lo = mi+1;
      } else {
        hi = mi-1;
      }
    }
    cout << lo << '\n';
  }

  return 0;
}