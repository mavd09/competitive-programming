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
const int oo   = INT_MAX;

int n, m;

int p[ MAXN ], sz[ MAXN ];

void init( int n ) {
  for( int i = 0; i < n; ++i ) {
    p[i] = i;
  }
}

int find_set( int i ) {
  if( p[i] == i ) return i;
  return p[i] = find_set(p[i]);
}

void union_set( int i, int j ) {
  i = find_set( i );
  j = find_set( j );
  if( i == j ) return ;
  p[ j ] = i;
  sz[ i ] += sz[ j ];
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

  int n_test; cin >> n_test;

  while( n_test-- ) {
    cin >> n >> m;
    init( n );
    for( int i = 0; i < n; ++i ) {
      cin >> sz[i];
    }
    for( int i = 0; i < m; ++i ) {
      int u, v; cin >> u >> v;
      union_set( u, v );
    }
    bool ok = true;
    for( int i = 0; i < n; ++i ) {
      if( p[i] == i ) {
        ok &= ( sz[i] == 0 );
      }
    }
    cout << (!ok?"IM":"") << "POSSIBLE\n";
  }

  return 0;
}

