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

int n;

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

  while( cin >> n ) {
    set< pii > ans;
    for( int y = n+1; y <= 2*n; ++y ) {
      int den = n*y, num = n-y;
      int gcd = __gcd( num, den );
      den /= gcd; num /= gcd;
      if( num == 1 ) {
        ans.insert( {y, -den} );
      }
    }
    cout << SIZE(ans) << '\n';
    for( auto& e : ans ) {
      cout << "1/" << n << " = " << "1/" << e.SE << " + " << "1/" << e.FI << '\n';
    } 
  }

  return 0;
}

