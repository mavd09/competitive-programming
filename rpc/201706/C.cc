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

const int MAXN = int( 2e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

struct M { int x, a, d; };
bool operator < ( const M& m1, const M& m2 ) {
  if( m1.x != m2.x ) return m1.x < m2.x;
  if( m1.a != m2.a ) return m1.a < m2.a;
  return m1.d < m2.d;
}
bool operator == ( const M& m1, const M& m2 ) {
  return m1.x == m2.x && m1.a == m2.a && m1.d == m2.d;
}

int x, a, d;

vector< M > doit( vector< M >& s ) {
  int n = SIZE( s );
  vector< M > r;
  for( int mask = 0; mask < (1<<n); mask++ ) {
    int x = 0, a = 0, d = 0;
    for( int j = 0; j < n; j++ ) {
      if( (mask>>j)&1 ) {
        x += s[ j ].x;
        a += s[ j ].a;
        d += s[ j ].d;
      }
    }
    r.PB( { x, a, d } );
  }
  sort( ALL( r ) );
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

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    int m; cin >> x >> a >> d >> m;
    vector< M > sa, sb;  
    for( int i = 0; i < m; i++ ) {
      string name; int x, a, d;
      cin >> name >> x >> a >> d;
      if( 2*i < m ) {
        sa.PB( { x, a, d } );
      } else {
        sb.PB( { x, a, d } );
      }
    }
    sa = doit( sa ); sb = doit( sb );
    bool can = false;
    for( auto& e : sa ) {
      M cur = { x-e.x, a-e.a, d-e.d };
      if( cur.x < 0 || cur.a < 0 || cur.d < 0 ) {
        continue;
      }
      int id = lower_bound( ALL( sb ), cur )-sb.begin( );
      if( id < SIZE( sb ) && cur == sb[ id ] ) {
        can = true;
        break;
      }
    }
    if( !can ) cout << "IM";
    cout << "POSSIBLE\n";
  }

  return 0;
}