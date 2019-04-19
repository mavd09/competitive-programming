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

const int MAXN = int( 100 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

struct Hopcroft_Karp {

  const static int max_n1 = 110;
  const static int max_n2 = 110;
  const static int max_m  = max_n1*max_n2;

  int n1, n2, edges;
  vi last, prev, head, matching, dist, q;
  vb used, vis;

  Hopcroft_Karp( ) :
    last( max_n1 ), prev( max_m ), head( max_m ),
    matching( max_n2 ), dist( max_n1 ), q( max_n1 ),
    used( max_n1 ), vis( max_n1 ) {
  }

  void init( int n1, int n2 ) {
    this->n1 = n1;
    this->n2 = n2;
    edges = 0;
    fill( last.begin( ), last.begin( )+n1, -1 );
  }

  void add_edge( int u, int v ) {
    head[ edges ] = v;
    prev[ edges ] = last[ u ];
    last[ u ] = edges++;
  }

  void bfs( ) {
    fill( dist.begin( ), dist.begin( )+n1, -1 );
    int size_q = 0;
    for( int u = 0; u < n1; u++ ) {
      if( !used[ u ] ) {
        q[ size_q++ ] = u;
        dist[ u ] = 0;
      }
    }
    for( int i = 0; i < size_q; i++ ) {
      int u1 = q[ i ];
      for( int e = last[ u1 ]; e >= 0; e = prev[ e ] ) {
        int u2 = matching[ head[ e ] ];
        if( u2 >= 0 && dist[ u2 ] < 0 ) {
          dist[ u2 ] = dist[ u1 ] + 1;
          q[ size_q++ ] = u2;
        }
      }
    }
  }

  bool dfs( int u1 ) {
    vis[ u1 ] = true;
    for( int e = last[ u1 ]; e >= 0; e = prev[ e ] ) {
      int v = head[ e ];
      int u2 = matching[ v ];
      if( u2 < 0 || ( !vis[ u2 ] && dist[ u2 ] == dist[ u1 ]+1 && dfs( u2 ) ) ) {
        matching[ v ] = u1;
        used[ u1 ] = true;
        return true;
      }
    }
    return false;
  }

  int max_matching( ) {
    fill( used.begin( ), used.begin( )+n1, false );
    fill( matching.begin( ), matching.begin( )+n2, -1 );
    int ans = 0;
    while( true ) {
      bfs( );
      fill( vis.begin( ), vis.begin( )+n1, false );
      int f = 0;
      for( int u = 0; u < n1; u++ ) {
        if( !used[ u ] && dfs( u ) ) {
          f++;
        }
      }
      if( f == 0 ) {
        return ans;
      }
      ans += f;
    }
    return 0;
  }

}hk;

int n;
int xs[ MAXN ], ys[ MAXN ];
int xt[ MAXN ], yt[ MAXN ];

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
      cin >> xs[ i ] >> ys[ i ];
    }
    for( int i = 0; i < n; ++i ) {
      cin >> xt[ i ] >> yt[ i ];
    }
    int lo = 0, hi = int( 1e9 ), mi;
    while( lo <= hi ) {
      mi = ( lo+hi )>>1;
      hk.init( n, n );
      for( int i = 0; i < n; ++i ) {
        for( int j = 0; j < n; ++j ) {
          if( abs( xs[ i ]-xt[ j ] )+abs( ys[ i ]-yt[ j ] ) <= mi ) {
            hk.add_edge( i, j );
          }
        }
      }
      if( hk.max_matching( ) == n ) {
        hi = mi-1;
      } else {
        lo = mi+1;
      }
    }
    cout << lo << '\n';
  }

  return 0;
}