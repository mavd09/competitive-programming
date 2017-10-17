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

const int MAXN = int( 2e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

#define int ll

int n, k;
int arr[ MAXN ];

bool seen[ MAXN ];
int x[ MAXN ], acc[ MAXN ];

main( ) {

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
    for( int i = 0; i < n; ++i ) {
      cin >> arr[i];
    }
    memset( seen, false, sizeof(seen) );
    memset( x, 0, sizeof(x) );
    bool ok = true;
    vi v;
    for( int i = 0; i < n; ++i ) {
      if( seen[i] ) continue;
      v.PB( i );
      int cur = i, acc = 0;
      do {
        acc += -arr[cur]+arr[(cur-1+n)%n];
        cur = ( cur-k+n )%n;
        x[ cur ] = acc;
        seen[ cur ] = true;
      } while( cur != i );
     // ok &= acc == 0;
    }
    acc[ 0 ] = x[ 0 ];
    for( int i = 1; i < 2*n; ++i ) {
      acc[ i ] = acc[i-1]+x[i%n];
    }
    for( int i : v ) {
      int c = arr[i] - (acc[ i+n ]-acc[ i+n-k ]);
      if( c%k == 0 ) {
        c /= k;
      } else {
        ok = false;
      }
      int cur = i;
      do {
        cur = (cur-k+n)%n;
        int cc = arr[cur] - (acc[cur+n]-acc[cur+n-k]);
        if( cc%k == 0 ) cc /= k;
        else ok = false;
        ok &= cc == c;
        x[ cur ] += c;
      } while( cur != i );
    }
    acc[0] = x[0];
    for( int i = 1; i < 2*n; ++i ) {
      acc[i] = acc[i-1] + x[i%n];
    }
    for( int i = 0; i < n; ++i ) {
      ok &= x[i] >= 0;
      ok &= arr[i] == acc[ i+n ]-acc[ i+n-k ];
    }
    cout << "NS"[ok] << '\n';
  }

  return 0;
}

