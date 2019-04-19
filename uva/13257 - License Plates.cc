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

int nxt[ 26 ][ MAXN ];

int mov( int fr, int ch ) {
  if( fr == -1 ) return -1;
  return nxt[ch][fr];
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

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; ++tc ) {
    string str; cin >> str;
    int n = SIZE(str);
    for( int i = 0; i < 26; ++i ) {
      nxt[i][n] = -1;
      for( int j = n-1; j >= 0; --j ) {
        nxt[i][j] = nxt[i][j+1];
        if( i == str[j]-'A' ) {
          nxt[i][j] = j+1;
        }
      }
    }
    int ans = 0;
    for( int i = 0; i < 26; ++i ) {
      for( int j = 0; j < 26; ++j ) {
        for( int k = 0; k < 26; ++k ) {
          if( mov(mov(mov(0,i), j), k) != -1 ) {
            ans++;
          }
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

