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

const int MAXN = 256 + 10;
const int MOD  = int( 1e9 )+7;
const ll  oo   = ll( 1e16 );

int d, k;
int r[ MAXN ], p[ MAXN ];

ll cost[ MAXN ][ MAXN ];
ll dp[ MAXN ][ MAXN ];

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d %d", &d, &k ) == 2 ) {
    for( int i = 0; i < d; ++i ) {
      scanf( "%d %d", &r[i], &p[i] );
    }
    for( int i = 0; i < d; ++i ) {
      for( int j = i; j < d; ++j ) {
        ll L = 0, R = 0;
        cost[i][j] = 0;
        for( int m = i; m <= j; ++m ) {
          cost[i][j] += 1LL * p[m] * (r[m]-r[i]+1);
          R += p[m];
        }
        ll cur_cost = cost[i][j];
        int idx = i;
        for( int m = r[i]; m <= r[j]; ++m ) {
          ll eq = 0;
          if( idx <= j && r[idx] == m ) {
            eq += p[idx++];
          }
          cur_cost = cur_cost + L - R;
          if( cur_cost < cost[i][j] ) {
            cost[i][j] = cur_cost;
          }
          L += eq;
          R -= eq;
        }
        cout << i << ' ' << j << ' ' << cost[i][j] << endl;
      }
    }
    for( int i = 0; i < d; ++i ) {
      for( int j = 0; j < k; ++j ) {
        dp[i][j] = oo;
      }
    }
    dp[0][0] = 0;
    for( int i = 1; i <= d; ++i ) {
      for( int lst = 0; lst < i; ++lst ) {
        for( int j = 0; j < k; ++j ) {
          dp[i][j+1] = min( dp[i][j+1], dp[lst][j]+cost[lst+1][i] );
        }
      }
    }
    ll ans = oo;
    for( int i = 0; i <= k; ++i ) {
      ans = min( ans, dp[d][i] );
    }
    printf( "%lld\n", ans );
  }

  return 0;
}

