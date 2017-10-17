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

const int MAXN = int( 2e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m;
int f[ MAXN ];
string arr[ MAXN ];

bool can( const string& str, int k ) {
  if( SIZE(str) < (1<<k) ) return false;
  set< int > s;
  int mod = (1<<k)-1, cur = 0;
  for( int i = 0; i < k; ++i ) {
    cur = (cur<<1)|(str[i]=='1');
    cur &= mod;
  }
  s.insert( cur );
  for( int i = k; i < SIZE(str); ++i ) {
    cur = (cur<<1)|(str[i]=='1');
    cur &= mod;
    s.insert( cur );
  }
  return SIZE(s) == (1<<k);
}

int doit( int i ) {
  int lo = 1, hi = 30;
  while( lo <= hi ) {
    int mi = (lo+hi)>>1;
    if( can( arr[i], mi ) ) {
      lo = mi+1;
    } else {
      hi = mi-1;
    }
  }
  return f[i] = max( f[i], hi );
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
    memset( f, 0, sizeof(f) );
    for( int i = 0; i < n; ++i ) {
      cin >> arr[i];
      doit( i );
    }
    cin >> m;
    for( int i = 0; i < m; ++i ) {
      int a, b; cin >> a >> b; a--; b--;
      f[n+i] = max( f[a], f[b] );
      if( SIZE(arr[a])+SIZE(arr[b]) < 2e6 ) {
        arr[n+i] = arr[a]+arr[b];
        doit(n+i);
      }
      cout << f[n+i] << '\n';
    }
  }

  return 0;
}

