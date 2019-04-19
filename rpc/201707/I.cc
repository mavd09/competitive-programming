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
const int oo   = int( 1e7 );

int n, m, p;
bool used[ MAXN ];

struct Edge {
  int from, to, cap, flow, index;
  Edge( int from, int to, int cap, int flow, int index ) :
  from( from ), to( to ), cap( cap ), flow( flow ), index( index ) { }
};

struct Network {
    
  int n;
  vector< vector< Edge > > G;
  vector< ll > excess;
  vector< int > dist, active, count;
  queue< int > Q;
  
  Network( int n ) : n( n ), G( n ), excess( n ), dist( n ), active( n ), count( 2*n ) { }
  
  void addDirEdge( int from, int to, int cap ) {
    G[ from ].PB( Edge( from, to, cap, 0, int( G[ to ].size( ) ) ) );
    if( from == to ) G[ from ].back( ).index++;
    G[ to ].PB( Edge( to, from, 0, 0, int( G[ from ].size( ) )-1 ) );
  }
  
  void Enqueue( int v ) {
    if( !active[ v ] && excess[ v ] > 0 ) {
      active[ v ] = true;
      Q.push( v );
    }
  }
  
  void Push( Edge &e ) {
    int amt = int( min( excess[ e.from ], ll( e.cap - e.flow ) ) );
    if( dist[ e.from ] <= dist[ e.to ] || amt == 0 ) return ;
    e.flow += amt;
    G[ e.to ][ e.index ].flow -= amt;
    excess[ e.to ] += amt;
    excess[ e.from ] -= amt;
    Enqueue( e.to );
  }
  
  void Gap( int k ) {
    for( int v = 0; v < n; v++ ) {
      if( dist[ v ] < k ) continue;
      count[ dist[ v ] ]--;
      dist[ v ] = max( dist[ v ], n+1 );
      count[ dist[ v ] ]++;
      Enqueue( v );
    }
  }
  
  void Relabel( int v ) {
    count[ dist[ v ] ]--;
    dist[ v ] = 2*n;
    for( int i = 0; i < int( G[ v ].size( ) ); i++ )
      if( G[ v ][ i ].cap-G[ v ][ i ].flow > 0 )
        dist[ v ] = min( dist[ v ], dist[ G[ v ][ i ].to ]+1 );
    count[ dist[ v ] ]++;
    Enqueue( v );
  }
  
  void Discharge( int v ) {
    for( int i = 0; excess[ v ] > 0 && i < int( G[ v ].size( ) ); i++ )
      Push( G[ v ][ i ]);
    if( excess[ v ] > 0 ) {
      if( count[ dist[ v ] ] == 1 )
        Gap( dist[ v ] );
      else
        Relabel( v );
    }
  }
  
  ll maxFlow( int s, int t ) {
    count[ 0 ] = n-1;
    count[ n ] = 1;
    dist[ s ] = n;
    active[ s ] = active[ t ] = true;
    for( int i = 0; i < int( G[ s ].size( ) ); i++ ) {
      excess[ s ] += G[ s ][ i ].cap;
      Push( G[ s ][ i ] );
    }
    while( !Q.empty( ) ) {
      int v = Q.front( );
      Q.pop( );
      active[ v ] = false;
      Discharge( v );
    }
    ll totflow = 0;
    for (int i = 0; i < int( G[ s ].size( ) ); i++ )
      totflow += G[ s ][ i ].flow;
    return totflow;
  }
};

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

  while( cin >> n >> m >> p ) {
    Network netw( n+m+m+2 );
    memset( used, false, sizeof( used ) );
    int source = n+m+m, sink = source+1;
    for( int i = 0; i < n; ++i ) {
      netw.addDirEdge( source, i, 1 );
    }
    for( int i = 0; i < n; ++i ) {
      int k; cin >> k;
      for( int j = 0; j < k; ++j ) {
        int x; cin >> x; x--;
        netw.addDirEdge( i, n+x, oo );
      }
    }
    for( int i = 0; i < p; ++i ) {
      int k; cin >> k;
      for( int j = 0; j < k; ++j ) {
        int x; cin >> x; x--;
        used[ x ] = true;
        netw.addDirEdge( n+x, n+m+i, 1 );
      }
      int c; cin >> c;
      netw.addDirEdge( n+m+i, sink, c );
    }
    for( int i = 0; i < m; ++i ) {
      if( !used[ i ] ) {
        netw.addDirEdge( n+i, sink, 1 );
      }
    }
    cout << netw.maxFlow( source, sink ) << '\n';
  }

  return 0;
}