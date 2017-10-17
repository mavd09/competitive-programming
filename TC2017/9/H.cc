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

const int MAXN = int( 1e2 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

 /// (s1 ^ a2) V (a1 ^ s2) is the same as
 /// (s1 v s2) ^ (a1 v a2) ^ (s1 v a1) ^ (s2 v a2)
 /// (a v b v c) is the same as ~a -> (b v c)
 ///            and the same as ~a -> (~b -> c)
 ///            and the same as (~a ^ ~b) -> c
struct SAT {
  int n;
  vector< vector< vi > > graph;
  vi tag;
  vb seen, value;
  stack< int > st;
  SAT( int n ) : n( n ), graph( 2, vector< vi >( 2*n ) ), tag( 2*n ), seen( 2*n ), value( 2*n ) { }
  int neg( int x ) {
    return 2*n-x-1;
  }
  ///We give u v v and it makes ¬u -> v and ¬v -> u
  void make_implication( int u, int v ) {
    implication( neg(u), v );
    implication( neg(v), u );
  }
  void make_true( int u ) {
    add_edge( neg(u), u );
  }
  void make_false( int u ) {
    make_true( neg(u) );
  }
  void eq( int u, int v ) {
    implication( u, v );
    implication( v, u );
  }
  void diff( int u, int v ) {
    eq( u, neg(v) );
  }
  void implication( int u, int v ) {
    add_edge( u, v );
    add_edge( neg(v), neg(u) );
  }
  void add_edge( int u, int v ) {
    graph[ 0 ][ u ].push_back( v );
    graph[ 1 ][ v ].push_back( u );
  }
  void dfs( int id, int u, int t = 0 ) {
    seen[ u ] = true;
    for( auto& v : graph[ id ][ u ] )
      if( !seen[ v ] )
        dfs( id, v, t );
    if( id == 0 )
      st.push( u );
    else
      tag[ u ] = t;
  }
  void kosaraju( ) {
    for( int u = 0; u < n; u++ ) {
      if( !seen[ u ] )
        dfs( 0, u );
      if( !seen[ neg(u) ] )
        dfs( 0, neg(u) );
    }
    fill( seen.begin( ), seen.end( ), false );
    int t = 0;
    while( !st.empty( ) ) {
      int u = st.top( ); st.pop( );
      if( !seen[ u ] )
        dfs( 1, u, t++ );
    }
  }
  bool satisfiable( ) {
    kosaraju();
    for( int i = 0; i < n; i++ ) {
      if( tag[ i ] == tag[ neg(i) ] ) return false;
      value[ i ] = tag[ i ] > tag[ neg(i) ];
    }
    return true;
  }
};

int r, c;
string b[ MAXN ];
int id[ MAXN ][ MAXN ];

bool is_valid( int x, int y ) {
  return 0 <= x && x < r && 0 <= y && y < c && b[ x ][ y ] != '#';
}

int search_t( int x, int y, int dx, int dy ) {
  do {
    x += dx;
    y += dy;
  } while( is_valid( x, y ) && ( b[ x ][ y ] != 'T' ) );
  if( is_valid( x, y ) ) {
    return id[ x ][ y ];
  }
  return -1;
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

  while( cin >> r >> c ) {
    for( int i = 0; i < r; ++i ) {
      cin >> b[ i ];
    }
    int t = 0;
    for( int i = 0; i < r; ++i ) {
      for( int j = 0; j < c; ++j ) {
        if( b[ i ][ j ] == 'T' ) {
          id[ i ][ j ] = t++;
        }
      }
    }
    SAT sat( 2*t );
    // 2*k   -> up( true ), down( false )
    // 2*k+1 -> right( true ), left( false )
    for( int i = 0; i < r; ++i ) {
      for( int j = 0; j < c; ++j ) { 
        int l, r, u, d;
        if( b[ i ][ j ] == 'n' || b[ i ][ j ] == 'T' ) {
          l = search_t( i, j, 0, -1 );
          r = search_t( i, j, 0, 1 );
          u = search_t( i, j, -1, 0 );
          d = search_t( i, j, 1, 0 );
        }
        if( b[ i ][ j ] == 'n' ) {
          if( ( l == -1 && r == -1 ) || ( l != -1 && r != -1 ) ) {
            if( u != -1 ) sat.make_false( 2*u );
            else          sat.make_true( 2*d );
          } else if( ( u == -1 && d == -1 ) || ( u != -1 && d != -1 ) ) {
            if( l != -1 ) sat.make_true( 2*l+1 );
            else          sat.make_false( 2*r+1 );
          } else {
            if( u != -1 && r != -1 ) sat.make_implication( sat.neg( 2*u ), sat.neg( 2*r+1 ) );
            if( u != -1 && l != -1 ) sat.make_implication( sat.neg( 2*u ), 2*l+1 );
            if( d != -1 && r != -1 ) sat.make_implication( 2*d, sat.neg( 2*r+1 ) );
            if( d != -1 && l != -1 ) sat.make_implication( 2*d, 2*l+1 );
          }
        }
        if( b[ i ][ j ] == 'T' ) {
          if( u != -1 ) sat.make_false( 2*id[ i ][ j ] );
          if( d != -1 ) sat.make_true( 2*id[ i ][ j ] );
          if( r != -1 ) sat.make_false( 2*id[ i ][ j ]+1 );
          if( l != -1 ) sat.make_true( 2*id[ i ][ j ]+1 );
        }
      }
    }
    if( sat.satisfiable( ) ) {
      for( int i = 0; i < r; ++i ) {
        for( int j = 0; j < c; ++j ) {
          if( b[ i ][ j ] == 'T' ) {
            int cur = id[ i ][ j ];
            if( !sat.value[ 2*cur ] && !sat.value[ 2*cur+1 ] ) cout << 1;
            if( !sat.value[ 2*cur ] && sat.value[ 2*cur+1 ] )  cout << 2;
            if( sat.value[ 2*cur ] && sat.value[ 2*cur+1 ] )   cout << 3;
            if( sat.value[ 2*cur ] && !sat.value[ 2*cur+1 ] )  cout << 4;
          } else {
            cout << b[ i ][ j ];
          }
        }
        cout << '\n';
      }
    } else {
      assert( false );
    }
  }

  return 0;
}