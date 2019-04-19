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

const int MAXN = int( 5e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const int LOG2 = 62;

int n;

int f[ MAXN ][ LOG2 ];
lf dp[ MAXN ][ LOG2 ];

pair< lf, pii > query( int id, int u, ll k ) {
  lf r = 0;
  for( int i = LOG2-1; i >= 0; --i ) {
    if( (k>>i)&1 ) {
      r += dp[ u ][ i ];
      u = f[u][i];
    }
  }
  return { r, { id, u } };
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d", &n ) == 1 ) {
    for( int i = 0; i < n; ++i ) {
      ll d; scanf( "%d%lld", &f[i][0], &d ); 
      f[i][0]--;
      dp[i][0] = d*d*d;
    }
    for( int j = 1; j < LOG2; ++j ) {
      for( int i = 0; i < n; ++i ) {
        f[ i ][ j ] = f[ f[i][j-1] ][ j-1 ];
        dp[ i ][ j ] = dp[ i ][ j-1 ]+dp[ f[i][j-1] ][ j-1 ];
      }
    }
    int p, q; scanf( "%d%d", &p, &q );
    for( int i = 0; i < q; ++i ) {
      pair< lf, pii > best = { 0.0, { 0, 0 } };
      for( int j = 0; j < p; ++j ) {
        int u; ll k; scanf( "%d%lld", &u, &k );
        u--;
        best = max( best, query( j, u, k ) );
      }
      double score = pow( best.FI, 1.l / 3 );
      printf( "%d %d %.10lf\n", best.SE.FI+1, best.SE.SE+1, score );
    }
  }
   

  return 0;
}

