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

const int MAXN = int( 2e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

string t, p;
int k;
int z[2][MAXN];

void z_algorithm( int* z, string str ) {
  int len = SIZE(str);
  z[0] = 0;
  for( int i = 1, l = 0, r = 0; i < len; ++i ) {
    z[i] = 0;
    if( i <= r ) z[i] = min( r-i+1, z[i-l] );
    while( i+z[i] < len && str[ z[i] ] == str[ i+z[i] ] ) z[i]++;
    if( i+z[i]-1 > r ) {
      l = i;
      r = i+z[i]-1;
    }
  }
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

  while( n_test-- ) {
    cin >> t >> p >> k;
    int n = SIZE(t), m = SIZE(p);
    z_algorithm( z[0], p+"$"+t );
    reverse( ALL(t) ); reverse( ALL(p) );
    z_algorithm( z[1], p+"$"+t );
    reverse( z[1]+m+1, z[1]+m+1+n );
    int ans = 0;
    for( int i = m+1; i+m-1 < n+m+1; ++i ) {
      if( z[0][i]+z[1][i+m-1]+k >= m ) {
        ans++;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}

