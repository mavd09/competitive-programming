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
const int MAXM = 20;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m, k;
int pref[ MAXN ][ MAXM ];

int f( int mask ) {
  vi score(m, 0);
  int mx = 0;
  for( int i = 0; i < n; ++i ) {
    int cur = 0;
    while( (mask>>pref[i][cur])&1 ) cur++;
    score[ pref[i][cur] ]++;
    mx = max( mx, score[ pref[i][cur] ] );
  }
  for( int i = 0; i < m; ++i ) {
    if( mx == score[i] ) {
      return i;
    }
  }
  assert(false);
  return -1;
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d%d%d", &n, &m, &k ) == 3 ) {
    k--;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        cin >> pref[i][j];
        pref[i][j]--;
      }
    }
    printf( "%d\n", f(0)+1 );
    int mn = oo;
    for( int mask = 0; mask < (1<<m); ++mask ) {
      if( (mask>>k)&1 ) continue;
      if( f(mask) == k ) {
        mn = min( mn, __builtin_popcount(mask) );
      }
    }
    if( m == 1 ) mn = 0;
    printf( "%d\n", mn );
  }

  return 0;
}

