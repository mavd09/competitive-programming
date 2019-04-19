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

const int MAXN = int( 500 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const int MASK = (1<<21)-1;

int n, k;
int b[ MAXN ][ MAXN ];

int t[ 4 ];

int get_hash( ) {
  int hash = 0;
  for( int i = 0; i < 4; ++i ) {
    hash <<= 7;
    hash |= t[i];
  }
  int r = oo;
  for( int i = 0; i < 4; ++i ) {
    hash = (hash&MASK)<<7;
    hash |= t[i];
    r = min( r, hash );
  }
  return r;
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

  while( cin >> n >> k ) {
    if( n == 0 && k == 0 ) break;
    vector< pair< int, ll > > v1;
    for( int i = 0; i < k; ++i ) {
      cin >> t[0] >> t[1] >> t[3] >> t[2];
      ll p; cin >> p;
      int hash = get_hash();
      v1.PB( {hash, p} );
    }
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        cin >> b[i][j];
      }
    }
    vi v2;
    for( int i = 0; i < n; i += 2 ) {
      for( int j = 0; j < n; j += 2 ) {
        t[0] = b[i][j]; t[1] = b[i][j+1];
        t[2] = b[i+1][j+1]; t[3] = b[i+1][j];
        int hash = get_hash();
        v2.PB( hash );
      }
    }
    sort( ALL(v1) );
    sort( ALL(v2) );
    bool ok = true;
    ll ans = 0;
    for( int i = 0, j = 0; i < SIZE(v2); ++i ) {
      while( j < SIZE(v1) && v1[j].FI != v2[i] ) j++;
      if( j == SIZE(v1) ) {
        ok = false;
        break;
      }
      ans += v1[j].SE;
      j++;
    }
    if( !ok ) ans = -1;
    cout << ans << '\n';
  }

  return 0;
}

