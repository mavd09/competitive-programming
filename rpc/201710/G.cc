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

  int n_test; cin >> n_test; cin.ignore( );

  for( int tc = 1; tc <= n_test; ++tc ) {
    string line; getline( cin, line );
    stringstream in(line);
    ll mx = -1, cnt = 0;
    vll h;
    for( ll x; in >> x; ) {
      h.PB( x );
      if( x > mx ) {
        mx = x;
        cnt = 0;
      }
      if( x == mx ) {
        cnt++;
      }
    }
    int ans = 0;
    if( cnt == 1 ) {
      for( int i = 0; i < SIZE(h); ++i ) {
        if( mx == h[i] ) {
          ans = SIZE(h)-i-1;
        }
      }
    } else {
      for( int i = 0; i < SIZE(h); ) {
        while( i < SIZE(h) && h[i] != mx ) i++;
        if( i < SIZE(h) && h[i] == mx ) {
          int j = i+1;
          while( j < SIZE(h) && h[j] != mx ) j++;
          if( j != SIZE(h) ) ans++;
          ans += j-i;
          i = j+1;
        }
      }
    }
    cout << ans << '\n';
  }  

  return 0;
}

