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
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
ll w[ MAXN ];
vpii graph[ MAXN ];

ll sumw[ MAXN ], val[ MAXN ];

void dfs_up( int u, int p = -1 ) {
  for( auto& e : graph[u] ) {
    int v = e.FI, d = e.SE;
    if( v == p ) continue;
    dfs_up( v, u );
    val[u] += val[v]+ll(d)*sumw[v];
    sumw[u] += sumw[v];
  }
  sumw[u] += w[u];
//  cout << u+1 << ' ' << val[u] << ' ' << sumw[u] << '\n';
}

void dfs_down( int u, int p = -1, int pw = 0 ) {
  if( p != -1 ) {
    ll cur = val[p] - ( val[u]+ll(pw)*sumw[u] );
    val[ u ] += cur + ll(pw)*( sumw[0]-sumw[u] );
  }
  for( auto& e : graph[u] ) {
    int v = e.FI, d = e.SE;
    if( v == p ) continue;
    dfs_down( v, u, d );
  }
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  freopen( "house.in", "r", stdin );
  freopen( "house.out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  while( cin >> n ) {
    for( int i = 0; i < n; ++i ) {
      cin >> w[i];
      graph[i].clear();
      sumw[i] = val[i] = 0;
    }
    for( int i = 1; i < n; ++i ) {
      int u, v, d; cin >> u >> v >> d; --u; --v;
      graph[u].PB( {v, d} );
      graph[v].PB( {u, d} );
    }
    dfs_up( 0 );
    dfs_down( 0 );
    int ans = 0;
    for( int i = 1; i < n; ++i ) {
      if( val[i] < val[ans] ) {
        ans = i;
      }
    }
    cout << ans+1 << ' ' << val[ans] << '\n';
  }

  return 0;
}

