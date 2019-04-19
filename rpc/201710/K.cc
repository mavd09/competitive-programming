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

const int MAXN = 11;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
set< int > graph[ MAXN ];

int ok[ MAXN ], color[ MAXN ];
queue< int > q;

void mark( int u ) {
  for( auto& v : graph[u] ) {
    ok[ v ] |= 1<<color[u];
    if( color[v] == -1 ) {
      q.push( v );
      color[ v ] = 0;
    }
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
    for( int i = 0; i < n; ++i ) {
      color[i] = -1;
      ok[ i ] = 0;
      graph[i].clear();
    }
    for( int i = 0; i < n; ++i ) {
      int x; cin >> x;
      for( int j = 0; j < x; ++j ) {
        int v; cin >> v; v--;
        graph[i].insert(v);
        graph[v].insert(i);
      }
    }
    int ans = 0;
    q.push( 0 ); color[ 0 ] = 0;
    while( !q.empty() ) {
      int u = q.front(); q.pop();
      while( (ok[u]>>color[u])&1 ) color[u]++;
      ans = max( ans, color[u] );
      mark( u );
    } 
    cout << ans+1 << '\n';
  }

  return 0;
}

