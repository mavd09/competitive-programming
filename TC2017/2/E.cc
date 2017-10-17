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

int tc, n;
int g[ MAXN ], seen[ MAXN ];
vi rg[ MAXN ];

int deg[ MAXN ], tp[ MAXN ];

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

  int n_test; cin >> n_test;

  for( tc = 1; n_test--; ++tc ) {
    cin >> n;
    for( int i = 0; i < n; ++i ) {
      rg[ i ].clear( );
      tp[ i ] = -1;
      deg[ i ] = 0;
    }
    for( int i = 0; i < n; ++i ) {
      cin >> g[ i ]; --g[ i ];
      rg[ g[ i ] ].PB( i );
      deg[ g[ i ] ]++;
    }
    queue< int > q;
    for( int i = 0; i < n; ++i ) {
      if( deg[ i ] == 0 ) {
        q.push( i );  
        seen[ i ] = tc;
      }
    }
    int ans = 0;
    while( !q.empty( ) ) {
      int u = q.front( ); q.pop( );
      if( tp[ u ] == -1 ) {
        tp[ u ] = 0;
        if( g[ u ] != -1 ) {
          tp[ g[ u ] ] = 1;
          q.push( g[ u ] );
          seen[ g[ u ] ] = tc;
          for( auto& v : rg[ g[ u ] ] ) {
            g[ v ] = -1;
          }
        }
      } else if( g[ u ] != -1 && --deg[ g[ u ] ] == 0 ) {
        q.push( g[ u ] );
        seen[ g[ u ] ] = tc;
      }
      ans += tp[ u ];
    }
    for( int i = 0; i < n; ++i ) {
      if( seen[ i ] != tc ) {
        int u = i, len = 0;
        while( seen[ u ] != tc ) {
          ++len;
          seen[ u ] = tc;
          u = g[ u ];
        }
        ans += (len+1)/2;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}