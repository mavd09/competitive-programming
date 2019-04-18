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

  cout << fixed << setprecision(3);

  int n_test; cin >> n_test;

  while( n_test-- ) {
    lf A; cin >> A;
    lf lo = 0, hi = A;
    for( int it = 0; it < 164; ++it ) {
      lf mi1 = lo + (hi-lo)/3.0;
      lf mi2 = hi - (hi-lo)/3.0;
      lf p1 = mi1 + (A/mi1);
      lf p2 = mi2 + (A/mi2);
      if( p1 <= p2 ) hi = mi2;
      if( p2 <= p1 ) lo = mi1; 
    }
    lf a = (lo+hi)/2.0;
    lf b = A/a;
    cout << a << ' ' << b << ' ' << 2.0*(a+b) << '\n';
  }

  return 0;
}

