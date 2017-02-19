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

const int MAXN = int( 4e5 );
const int MAXM = int( 4e6 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

struct Event { ll m, f, w; };
bool cmp_event( const Event& a, const Event& b ) {
  return a.m < b.m;
}

int n;
Event event[ MAXN ];
ll dp[ MAXM ];

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
    for( int i = 0; i < n; i++ ) {
      cin >> event[ i ].m >> event[ i ].f >> event[ i ].w;
    }
    sort( event, event+n, cmp_event );
    int id = n-1;
    dp[ MAXM-1 ] = 0;
    for( int i = MAXM-2; i >= 0; i-- ) {
      dp[ i ] = 0;
      if( id >= 0 && event[ id ].m == i ) {
        dp[ i ] = event[ id ].f+dp[ i+event[ id ].w ];
        id--;
      }
      dp[ i ] = max( dp[ i ], dp[ i+1 ] );
    }
    cout << dp[ 0 ] << "\n";
  }

  return 0;
}
