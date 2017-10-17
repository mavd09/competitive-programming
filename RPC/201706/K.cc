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

  cout << fixed << setprecision( 4 );

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    int n; cin >> n;
    int cnt = 0;
    double b = 0, h = 0, acc = 0;
    double tg = 0, sq = 0;
    for( int i = 0; i < n; i++ ) {
      char t; double k; cin >> t >> k;
      acc += k;
      if( t == 'T' ) {
        tg += k*k;
      } else {
        sq += k*k;
      }
      if( t == 'C' ) {
        if( cnt == 1 ) {
          b = acc;
        } else if( cnt == 2 ) {
          h = acc;
        }
        acc = k;
        cnt++;
      }
    }
    double ans = b*h - tg*sqrt( 3.0 )/4.0 - sq;
    cout << ans << "\n";
  }

  return 0;
}