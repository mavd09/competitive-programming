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

typedef complex< lf >       pt;

const int MAXN = int( 2e6 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, sum;
int p[ MAXN ], deg[ MAXN ];
int val[ MAXN ];

void init( ) {
  sum = 0;
  memset( deg, 0, sizeof( deg ) );
}

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

  while( cin >> n ) {
    init( );
    for( int i = 1; i <= n; i++ ) {
      cin >> p[ i ] >> val[ i ];
      deg[ p[ i ] ]++;
      sum += val[ i ];
    }
    if( sum%3 ) {
      cout << -1 << "\n";
    }
    else {
      sum /= 3;
      queue< int > q;
      for( int i = 1; i <= n; i++ ) {
        if( deg[ i ] == 0 )
          q.push( i );
      }
      vi ans;
      while( !q.empty( ) ) {
        int u = q.front( ); q.pop( );
        if( p[ u ] == 0 ) continue;
        if( val[ u ] == sum )
          ans.PB( u );
        else
          val[ p[ u ] ] += val[ u ];
        deg[ p[ u ] ]--;
        if( deg[ p[ u ] ] == 0 )
          q.push( p[ u ] );
        if( SIZE( ans ) == 2 ) break;
      }
      if( SIZE( ans ) != 2 )
        cout << -1 << "\n";
      else
        cout << ans[ 0 ] << " " << ans[ 1 ] << "\n";
    }
  }

  return 0;
}
