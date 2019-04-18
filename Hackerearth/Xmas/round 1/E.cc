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
ll x[ MAXN ], y[ MAXN ];

inline ll add( ll a, ll b ) {
  if( a <= LLONG_MAX-b ) {
    return a+b;
  }
  assert( false );
}

inline ll mul( ll a, ll b ) {
  if( a <= LLONG_MAX/b ) {
    return a*b;
  }
  assert( false );
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

  while( cin >> n ) {
    for( int i = 0; i < n; ++i ) {
      cin >> x[i] >> y[i];
    }
    sort( x, x+n );
    sort( y, y+n );
    ull ans = 0;
    ull acc_x = 0, acc_y = 0;
    for( int i = 1; i < n; ++i ) {
      acc_x = add( acc_x, mul( x[i]-x[i-1], i ) );
      ans = add( ans, acc_x );
      acc_y = add( acc_y, mul( y[i]-y[i-1], i ) );
      ans = add( ans, acc_y );
    }
    cout << ans << '\n';
  }

  return 0;
}

