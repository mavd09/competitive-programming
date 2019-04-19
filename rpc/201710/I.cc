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
const int MAXM = int( 1e4 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

struct Edge { int u, v, c; };

bool cmp_edge( const Edge& a, const Edge& b ) {
  return a.c > b.c;
}

int n, m;
Edge edge[ MAXM ];

int p[MAXN];

void init( int n ) {
  for( int i = 0; i < n; ++i ) {
    p[i] = i;
  }
}

int find_set( int x ) {
  if( x == p[x] ) return x;
  return p[x] = find_set( p[x] );
}

int union_set( int a, int b, int c ) {
  a = find_set(a);
  b = find_set(b);
  if( a == b ) return oo;
  p[b] = a;
  return c;
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

  for( int tc = 1; tc <= n_test; ++tc ) {
    cin >> n >> m;
    for( int i = 0; i < m; ++i ) {
      cin >> edge[i].u >> edge[i].v >> edge[i].c;
    }
    sort( edge, edge+m, cmp_edge );
    init( n );
    int ans = oo;
    for( int i = 0; i < m; ++i ) {
      if( edge[i].u == edge[i].v ) continue;
      ans = min( ans, union_set( edge[i].u, edge[i].v, edge[i].c ) );
    }
    cout << "Case #" << tc << ": " << ans << '\n';
  }

  return 0;
}

