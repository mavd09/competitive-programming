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

const int MAXN = 513;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;

int s[ MAXN*MAXN ];
int ans[ MAXN ];

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

  for( int i = 1; i < MAXN; ++i ) {
    s[ i*i ] = i;
  }

  for( int a = 1; a < MAXN; ++a ) {
    for( int b = a; b < MAXN; ++b ) {
      int c2 = a*a + b*b;
      if( c2 < MAXN*MAXN && s[ c2 ] != 0 ) {
        ans[ s[c2] ]++;
      }
    }
  }

  for( int i = 1; i < MAXN; ++i ) {
    ans[ i ] += ans[i-1];
  }


  while( cin >> n ) {
    if( n == 0 ) break;
    cout << ans[n] << '\n';
  }

  return 0;
}

