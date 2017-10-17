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

const int MAXN = int( 5e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

struct Query { int b, l, r, id; };

int SZ = 700;

bool cmp( const Query& q1, const Query& q2 ) {
  if( q1.b != q2.b ) {
    return q1.b < q2.b;
  }
  return q1.r < q2.r;
}

inline int add( int a, int b ) { return a+b >= MOD ? a+b-MOD : a+b; }
inline int sub( int a, int b ) { return a < b ? a-b+MOD : a-b; }
inline int mul( int a, int b ) { return ( ll(a)*ll(b) )%ll(MOD); }

int mod_pow( int b, int e ) {
  int r = 1;
  while( e ) {
    if( e&1 ) {
      r = mul( r, b );
    }
    b = mul( b, b );
    e /= 2;
  }
  return r;
}

int n, p, q;
int a[ MAXN ], pot[ MAXN ], ipot[ MAXN ], ans[ MAXN ];
Query query[ MAXN ];

int res;

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

  while( cin >> n >> p ) {
    SZ = sqrt( n )+1;
    for( int i = 0; i < n; ++i ) {
      cin >> a[ i ];
      pot[ i ] = mod_pow( p, a[ i ] );
      ipot[ i ] = mod_pow( add( pot[ i ], 1 ), MOD-2 );
    }
    cin >> q;
    for( int i = 0; i < q; ++i ) {
      int l, r; cin >> l >> r; --l; --r;
      query[ i ] = { l/SZ, l, r, i };
    }
    sort( query, query+q, cmp );
    int lst = -1, L, R;
    res = 0;
    for( int i = 0; i < q; ++i ) {
      auto& e = query[ i ];
      if( e.b != lst ) {
        res = 0;
        L = e.l;
        R = L-1;
        lst = e.b;
      }
      while( R < e.r ) {
        ++R;
        res = add( res, mul( add( res, 1 ), pot[ R ] ) );
      }
      while( L > e.l ) {
        --L;
        res = add( res, mul( add( res, 1 ), pot[ L ] ) );
      }
      while( R > e.r ) {
        res = mul( sub( res, pot[ R ] ), ipot[ R ] );
        --R;
      }
      while( L < e.l ) {
        res = mul( sub( res, pot[ L ] ), ipot[ L ] );
        ++L;
      }
      ans[ e.id ] = res;
    }
    for( int i = 0; i < q; i++ )
      cout << ans[ i ] << "\n";
  }

  return 0;
}