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

const int MAXN = int( 1e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m;
vi graph[ MAXN ];
int color[ MAXN ];

bool dfs( int u, int p = -1 ) {
  color[ u ] = 1;
  bool ok = true;
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    if( color[v] == 0 ) {
      ok &= dfs( v, u );
    } else if( color[v] == 1 ) {
      ok = false;
      break;
    }
  }
  color[ u ] = 2;
  return ok;
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

  for( int tc = 1; n_test--; ++tc ) {
    cin >> n >> m;
    for( int i = 0; i < n; ++i ) {
      graph[i].clear();
      color[i] = 0;
    }
    bool ok = true;
    set< pii > edges;
    for( int i = 0; i < m; ++i ) {
      int u, v; cin >> u >> v;
      if( u > v ) swap( u, v );
      graph[u].PB(v);
      graph[v].PB(u);
      if( !ok || u == v || edges.count( {u, v} ) ) {
        ok = false;
      } else {
        edges.insert( {u, v} );
      }
    }
    for( int i = 0; i < n && ok; ++i ) {
      if( color[i] == 0 ) {
        ok &= dfs(i);
      }
    }
    cout << !ok << '\n';
  }

  return 0;
}

