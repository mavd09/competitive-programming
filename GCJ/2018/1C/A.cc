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

const int MAXN = 2010;
const int MAXL = 20;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int tc;
int N, L;

char str[ MAXN ][ MAXL ];
set< char > letters_per_pos[ MAXL ];

int ok[ MAXN ];

int main( ) {

  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );

  int n_test; scanf( "%d", &n_test );

  for( tc = 1; n_test--; ++tc ) {
    scanf( "%d %d", &N, &L );
    for( int i = 0; i < L; ++i ) letters_per_pos[i].clear();
    for( int i = 0; i < N; ++i ) {
      scanf( "%s", str[i] );
      for( int j = 0; j < L; ++j ) {
        letters_per_pos[j].insert(str[i][j]);
      }
    }
    ll total = 1LL;
    for( int i = 0; i < L; ++i ) {
      total *= 1LL*SIZE(letters_per_pos[i]);
    }
    printf( "Case #%d: ", tc );
    if( total == N ) {
      puts( "-" );
    } else {
      string ans = "";
      for( int i = 0; i < L; ++i ) {
        total /= SIZE(letters_per_pos[i]);
        vi cnt(256);
        for( int j = 0; j < N; ++j ) {
          if( ok[j] == tc ) continue;
          cnt[ str[j][i] ]++;
        }
        for( auto& ch : letters_per_pos[i] ) {
          if( cnt[ch] == total ) continue;
          ans.PB( ch );
          break;
        }
        for( int j = 0; j < N; ++j ) {
          if( ok[j] == tc ) continue;
          if( str[j][i] != ans.back() ) {
            ok[j] = tc;
          }
        }
      }
      printf( "%s\n", ans.c_str() );
    }
  }

  return 0;
}

