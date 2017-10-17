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

int n, k;
int pref[ MAXN ][ 4 ], suff[ MAXN ][ 4 ];

int id[ 255 ];

int dp[ MAXN ];

bool can( int f, int t ) {
  return suff[f][0] == pref[t][0] &&
         suff[f][1] == pref[t][1] &&
         suff[f][2] == pref[t][2] &&
         suff[f][3] == pref[t][3];
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  id[ 'A' ] = 0; id[ 'C' ] = 1; id[ 'G' ] = 2; id[ 'T' ] = 3;

  int n_test; cin >> n_test;

  for( int tc = 1; tc <= n_test; ++tc ) {
    cin >> n >> k;
    int ans = 0;
    for( int i = 0; i <= n; ++i ) {
      string s; cin >> s;
      for( int j = 0; j < 4; ++j ) {
        pref[ i ][ j ] = 0;
        suff[ i ][ j ] = 0;
      }
      for( int j = 0; j < k; ++j ) {
        pref[ i ][ id[s[j]] ]++;
        suff[ i ][ id[s[SIZE(s)-1-j]] ]++;
      }
    }
    for( int i = n; i > 0; --i ) {
      dp[ i ] = 1;
      for( int j = i+1; j <= n; ++j ) {
        if( can(i, j) ) {
          dp[i] = max( dp[i], dp[j]+1 );
        }
      }
      if( can(0, i) ) ans = max( ans, dp[i] );
    }
    cout << ans << '\n';
  }

  return 0;
}

