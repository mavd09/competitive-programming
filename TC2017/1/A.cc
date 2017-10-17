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

const int MAXN = int( 63 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int tc, n;
int arr[ MAXN ];
int seen[ MAXN ][ MAXN ][ MAXN ][ MAXN ];
ll dp[ MAXN ][ MAXN ][ MAXN ][ MAXN ];

ll go( int a, int b, int c, int d ) {
  int i = max( a, d )+1;
  if( i == n ) {
    return 1;
  }
  ll& r = dp[ a ][ b ][ c ][ d ];
  if( seen[ a ][ b ][ c ][ d ] == tc ) {
    return r;
  }
  seen[ a ][ b ][ c ][ d ] = tc;
  r = 0;
  ll mx;
  mx = 2LL*arr[ a ]-arr[ b ];
  if( a == b || arr[ i ] < mx ) {
    r += go( i, a, c, d );
  }
  mx = 2LL*arr[ d ]-arr[ c ];
  if( c == d || arr[ i ] < mx ) {
    r += go( a, b, d, i );
  }
  return r;
}

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

  for( tc = 1; cin >> n; ++tc ) {
    if( n == -1 ) {
      break;
    }
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
    }
    sort( arr, arr+n );
    reverse( arr, arr+n );
    arr[ n++ ] = 0; arr[ n++ ] = 0;
    ll ans = -1;
    for( int i = 1; i+1 < n; ++i ) {
      if( arr[ i ] == arr[ i-1 ] && arr[ i ] == arr[ i+1 ] ) {
        ans = 0;
        break;
      }
    }
    if( ans == -1 ) {
      ans = go( 0, 0, 0, 0 );
      for( int i = 0; i+1 < n; ++i ) {
        if( arr[ i ] == arr[ i+1 ] ) {
          ans >>= 1;
          ++i;
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}