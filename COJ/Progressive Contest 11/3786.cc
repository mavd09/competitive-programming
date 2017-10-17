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

const int MAXN = int( 2e3 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int a, c, m, x, q, n;
int tt[ MAXN ], cnt[ MAXN ];

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  while( cin >> a >> c >> m >> x >> q >> n ) {
    memset( tt, -1, sizeof( tt ) );
    memset( cnt, 0, sizeof( cnt ) );
    int id = -1, sz = -1;
    for( int cur = x, t = 0; ; cur = ( a*cur + c )%m, t++ ) {
      if( tt[ cur ] != -1 ) {
        id = cur; sz = t-tt[ cur ];
        break;
      }
      if( n ) {
        cnt[ cur ]++;
        n--;
      }
      tt[ cur ] = t;
    }
    int cur = id;
    do {
      cnt[ cur ] += n/sz;
      cur = ( a*cur + c )%m;
    } while( cur != id );
    n %= sz;
    cur = id;
    while( n ) {
      cnt[ cur ]++;
      n--;
      cur = ( a*cur + c )%m;
    }
    for( int i = 1; i < m; i++ ) {
      cnt[ i ] += cnt[ i-1 ];
    }
    for( int i = 0; i < q; i++ ) {
      int pos; cin >> pos;
      int ans = lower_bound( cnt, cnt+m, pos )-cnt;
      cout << ans << "\n";
    }
  }

  return 0;
}