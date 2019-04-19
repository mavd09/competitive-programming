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

int n;

vi graph[ MAXN ];

int p[ MAXN ];
int d[ MAXN ];

int find_set( int x ) {
  if( x == p[x] ) return x;
  return p[x] = find_set( p[x] );
}

bool union_set( int x, int y ) {
  x = find_set(x);
  y = find_set(y);
  if( x == y ) return false;
  p[y] = x;
  return true;
}

void dfs( int u, int p = -1 ) {
  d[u] = ( p==-1 ? 0 : d[p]+1 );
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    dfs( v, u );
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
  
  cin >> n;

  for( int i = 0; i < n; ++i ) {
    p[i] = i;
  }

  for( int u, v; cin >> u >> v; ) {
    u--; v--;
    if( union_set( u, v ) ) {
      graph[u].PB(v);
      graph[v].PB(u);
      cout << 1 << endl;
    } else {
      dfs( u );
      if( d[v]%2 == 0 ) {
        cout << 0 << endl;
        break;
      } else {
        cout << 1 << endl;
      }
    }
  } 

  return 0;
}

