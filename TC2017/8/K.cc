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

const int MAXN = int( 2e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, k;
ll arr[ MAXN ];
ll acc_l[ MAXN ], acc_r[ MAXN ], acc[ MAXN ];

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

  while( cin >> n >> k ) {
    acc[ 0 ] = 0;
    for( int i = 1; i <= n; ++i ) {
      cin >> arr[ i ];
      acc[ i ] = acc[ i-1 ]+arr[ i ];
    }
    acc_l[ 0 ] = 0;
    for( int i = 1; i <= n; ++i ) {
      acc_l[ i ] = acc_l[ i-1 ] + ( arr[ i ] > 0 ? arr[ i ] : 0 );
    }
    acc_r[ n+1 ] = 0;
    for( int i = n; i > 0; --i ) {
      acc_r[ i ] = acc_r[ i+1 ] + ( arr[ i ] > 0 ? arr[ i ] : 0 );
    }
    ll ans = 0;
    for( int i = 1; i+k-1 <= n; ++i ) {
      ll cur = acc_l[ i-1 ]+acc_r[ i+k ];
      ll val = acc[ i+k-1 ]-acc[ i-1 ];
      if( val > 0 ) {
        cur += val;
      }
      ans = max( ans, cur );
    }
    cout << ans << '\n';
  }

  return 0;
}