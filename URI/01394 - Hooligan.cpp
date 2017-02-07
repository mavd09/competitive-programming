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

const int MAXN = int( 1e7 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

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

int n, m, g;

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

  while( cin >> n >> m >> g ) {
    Network netw(  );
  }

  return 0;
}