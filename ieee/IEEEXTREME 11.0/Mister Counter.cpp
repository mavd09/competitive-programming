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

const int MAXN = int( 3e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int arr[ MAXN ];

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

  cin >> n;
  for( int i = 1; i <= n; ++i ) {
    cin >> arr[i];
  }
  arr[0] = oo;

  vi inv;
  for( int i = 1; i <= n; ++i ) {
    if( arr[i-1] < arr[i] ) {
      inv.PB( i );
    }
  }

  int q; cin >> q;
  while( q-- ) {
    int l, r; cin >> l >> r;
    int id = upper_bound( ALL(inv), r )-inv.begin();
    id--;
    if( 0 <= id && id < SIZE(inv) && inv[id] > l ) {
      int ans = r-inv[id]+1;
      if( (ans&1) != 0 ) ans--;
      int lo = inv[id], hi = r;
      while( lo <= hi ) {
        int mi = (lo+hi)>>1;
        if( arr[mi] > arr[ inv[id]-1 ] ) lo = mi+1;
        else hi = mi-1;
      }
      ans++;
      if( r-hi == hi-inv[id] ) ans++;
      cout << ans << '\n';
    } else {
      cout << 0 << '\n';
    }
  }

  return 0;
}

