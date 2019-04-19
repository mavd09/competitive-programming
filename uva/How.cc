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

const int MAXN = int( 2e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
vi graph[ MAXN ];
int seen[ MAXN ];

void dfs( int u ) {
  if( seen[u] ) return ;
  seen[u] = 1;
  for( auto& v : graph[u] ) {
    dfs( v );
  }
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

  while( cin >> n ) {
    if( n == 0 ) break;
    for( int i = 0; i < n; ++i ) {
      graph[i].clear();
    }
    for( int i = 0; i < n; ++i ) {
      int m; cin >> m;
      for( int j = 0; j < m; ++j ) {
        int u; cin >> u; u--;
        graph[ i ].PB( u );
      }
    }
    int best = -1, ans = -1;
    for( int i = 0; i < n; ++i ) {
      memset( seen, 0, sizeof(seen) );
      dfs( i );
      int cur = 0;
      for( int j = 0; j < n; ++j ) {
        cur += seen[j];
      }
      if( cur > best ) {
        best = cur;
        ans = i+1;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

