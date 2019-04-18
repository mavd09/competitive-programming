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

int d;
char p[ MAXN ];

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  int n_test; scanf( "%d", &n_test );
  
  for( int tc = 1; n_test--; ++tc ) {
    scanf( "%d %s", &d, p );
    int len = strlen(p), damage = 0, charge = 0;
    for( int i = 0; i < len; ++i ) {
      if( p[i] == 'C' ) charge++;
      if( p[i] == 'S' ) damage += (1<<charge);
    } 
    int ans = 0;
    while( damage > d ) {
      int idx = -1, cnt_charge = -1, cur_charge = 0;
      for( int i = 0; i+1 < len; ++i ) {
        if( p[i] == 'C' ) cur_charge++;
        if( p[i] == 'C' && p[i+1] == 'S' ) {
          idx = i+1;
          cnt_charge = cur_charge;
        }
      }
      if( idx == -1 ) break;
      while( damage > d ) {
        if( p[idx-1] != 'C' ) break;
        swap( p[idx-1], p[idx] );
        cnt_charge--; idx--;
        damage -= (1<<cnt_charge);
        ans++;
      }
    }
    printf( "Case #%d: ", tc );
    if( damage <= d ) printf( "%d\n", ans );
    else puts( "IMPOSSIBLE" );
  }

  return 0;
}

