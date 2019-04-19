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

string s;
int cnt[ 255 ][ 255 ];

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


  while( cin >> s ) {
    string t = s;
    sort( ALL(t) );
    memset( cnt, 0, sizeof(cnt) );
    for( int i = 1; i < SIZE(s); ++i ) {
      cnt[ t[i] ][ s[i] ]++;
    }
    string ans = "";
    char cur = '$';
    for( int i = 1; i < SIZE(s); ++i ) {
      ans.PB( cur );
      for( int j = 0; j < 255; ++j ) {
        if( cnt[j][cur] ) {
          cnt[j][cur]--;
          cur = j;
          break;
        }
      }   
    }
    if( s[0] != '$' ) {
      ans.PB( s[0] );
    }
    for( int i = 1; i < SIZE(ans); ++i ) {
      cout << ans[i];
    }
    cout << '\n';
  }

  return 0;
}

