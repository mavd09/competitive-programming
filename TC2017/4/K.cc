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

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 360 );
const int oo   = int( 2e8 );

const int LOG2 = 22;

int tc, n, a, b;
int val[ MAXN ];
int prv[ MAXN ];

vi graph[ MAXN ];
vi path;
int ok[ MAXN ];

int best[ MAXN ];

int acc[ 2 ][ MAXN ];
int st[ 2 ][ MAXN ][ LOG2 ];

void build_st( int id ) {
  for( int i = 0; i < SIZE( path ); ++i ) {
    st[ id ][ i ][ 0 ] = acc[ id ][ i ]+best[ i ];
  }
  for( int j = 1, sz = 2; j < LOG2; ++j, sz <<= 1 ) {
    for( int i = 0; i+sz-1 < SIZE( path ); ++i ) {
      st[ id ][ i ][ j ] = max( st[ id ][ i ][ j-1 ], st[ id ][ i+(sz >> 1) ][ j-1 ] );
    }
  }
}

int query( int id, int f, int t ) {
  if( f > t ) {
    assert( false );
    return 0;
  }
  int j = 31-__builtin_clz( t-f+1 );
  return max( st[ id ][ f ][ j ], st[ id ][ t-(1<<j)+1 ][ j ] );
}

void find_path( int a, int b ) {
  memset( prv, -1, sizeof( prv ) );
  queue< int > q;
  q.push( a ); prv[ a ] = -2;
  while( !q.empty( ) ) {
    int u = q.front( ); q.pop( );
    for( auto& v : graph[ u ] ) {
      if( prv[ v ] == -1 ) {
        prv[ v ] = u;
        q.push( v );
      }
    }
  }
  path.clear( );
  for( int u = b; u != -2; u = prv[ u ] ) {
    path.PB( u );
    ok[ u ] = tc;
  }
  reverse( ALL( path ) );
}

int dfs( int p, int u ) {
  int r = 0;
  for( auto& v : graph[ u ] ) {
    if( v == p || ok[ v ] == tc ) {
      continue;
    }
    r = max( r, dfs( u, v )+val[ v ] );
  }
  return r;
}

map< ll, int > dp;

int go( int i, int j, int t ) {
  ll state = (ll(i)<<30)|(ll(j)<<5)|(t);
  if( i == j ) {
    assert( false );
    return 0;
  }
  
  if( dp.count( state ) ) {
    return dp[ state ];
  }
  int& r = dp[ state ];
  
  r = -oo;
  if( t == 0 ) {
    if( i+1 < j ) {
      r = max( r, val[ path[ i ] ]-go( i+1, j, 1 ) );
    }
    r = max( r, val[ path[ i ] ]+best[ i ] - ( query( 1, i+1, j ) - ( j+1 < SIZE( path ) ? acc[ 1 ][ j+1 ] : 0 ) ) );
  } else {
    if( i < j-1 ) {
      r = max( r, val[ path[ j ] ]-go( i, j-1, 0 ) );
    }
    r = max( r, val[ path[ j ] ]+best[ j ] - ( query( 0, i, j-1 ) - ( i-1 >= 0 ? acc[ 0 ][ i-1 ] : 0 ) ) );
  }
  return r;
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

  for( tc = 1; cin >> n >> a >> b; ++tc ) {
    assert( 2 <= n && n <= 100000 );
    --a; --b;
    for( int i = 0; i < n; ++i ) {
      cin >> val[ i ];
      assert( 1 <= val[ i ] && val[ i ] <= 100 );
      graph[ i ].clear( );
    }
    for( int i = 1; i < n; ++i ) {
      int u, v; cin >> u >> v; --u; --v;
      graph[ u ].PB( v );
      graph[ v ].PB( u );
    }
    find_path( a, b );
    for( int i = 0; i < SIZE( path ); ++i ) {
      best[ i ] = dfs( -1, path[ i ] );
      //cout << path[ i ]+1 << ' ' << best[ i ] << endl;
    }
    acc[ 0 ][ 0 ] = val[ a ];
    for( int i = 1; i < SIZE( path ); ++i ) {
      acc[ 0 ][ i ] = acc[ 0 ][ i-1 ]+val[ path[ i ] ];
    }
    build_st( 0 );
    acc[ 1 ][ SIZE( path )-1 ] = val[ b ];
    for( int i = SIZE( path )-2; i >= 0; --i ) {
      acc[ 1 ][ i ] = acc[ 1 ][ i+1 ]+val[ path[ i ] ];
    }
    build_st( 1 );
    dp.clear( );
    cout << go( 0, SIZE( path )-1, 0 ) << '\n';
  } 

  return 0;
}