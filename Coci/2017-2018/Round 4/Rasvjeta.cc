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

int n, m, k;
bool ok[ MAXN ];

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d%d%d", &n, &m, &k ) == 3 ) {
    memset( ok, false, sizeof(ok) );
    for( int i = 0; i < m; ++i ) {
      int x; scanf( "%d", &x );
      for( int j = max(1,x-k); j <= min(n,x+k); ++j ) {
        ok[j] = true;
      }
    }
    int ans = 0;
    for( int i = 1; i <= n; ++i ) {
      if( ok[i] ) continue;
      for( int j = i; j <= min( n, i + 2*k ); ++j ) {
        ok[j] = true;
      }
      ans++;
    }
    printf( "%d\n", ans );
  }

  return 0;
}

