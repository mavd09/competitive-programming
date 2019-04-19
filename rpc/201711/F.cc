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
const int MAXQ = int( 2e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int bit[ MAXN ];
int f[ MAXQ ], t[ MAXQ ], v[ MAXQ ];

void update( int i, int v ) {
  for( ; i < MAXN; i += (i&-i) ) {
    bit[i] += v;
  }
}

int query( int i ) {
  int r = 0;
  for( ; i > 0; i -= (i&-i) ) {
    r += bit[i];
  }
  return r;
}

int query( int f, int t ) {
  return query(t) - query(f);
}

int q;

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

  while( cin >> q ) {
    memset( bit, 0, sizeof(bit) );
    int k = 0;
    set< pii > s;
    for( int i = 0; i < q; ++i ) {
      int tp; cin >> tp;
      if( tp == 1 ) {
        cin >> f[k] >> t[k] >> v[k];
        update( t[k], v[k] );
        s.insert( {f[k], k} );
        k++;
      } else if( tp == 2 ) {
        int x; cin >> x; x--;
        s.erase( {f[x], x} );
        update( t[x], -v[x] );
      } else {
        int a, b; cin >> a >> b;
        auto it = s.upper_bound( {b, oo} );
        if( it != s.begin() ) {
          it--;
          int idx = it->SE;
          if( f[idx] < b && t[idx] >= b ) b = t[idx];
        }
        cout << query( a, b ) << '\n';
      }
    }
  }

  return 0;
}

