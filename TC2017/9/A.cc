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

const int MAXN = (1<<19) + 10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

const int LOG2 = 21;

const lf PI = acos( -1.0 );

struct cp { lf r, i; };

cp operator + ( const cp& a, const cp& b ) { return { a.r+b.r, a.i+b.i }; }
cp operator - ( const cp& a, const cp& b ) { return { a.r-b.r, a.i-b.i }; }
cp operator * ( const cp& a, const cp& b ) { return { a.r*b.r-a.i*b.i, a.r*b.i+a.i*b.r }; }
cp operator * ( const cp& a, lf x ) { return { a.r*x, a.i*x }; }
cp operator * ( lf x, const cp& a ) { return { a.r*x, a.i*x }; }
cp operator / ( const cp& a, lf x ) { return { a.r/x, a.i/x }; }

ostream& operator << ( ostream& out, const cp& c ) {
  out << c.r << ' ' << c.i; 
  return out;
}

void rev( cp* a, int n ) {
  int i, j, k;
  for( i = 1, j = n>>1; i < n-1; ++i ) {
    if( i < j ) swap( a[ i ], a[ j ] );
    for( k = n>>1; j >= k; j -= k, k >>= 1 );
    j += k;
  }
}

void dft( cp* a, int n, int flag = 1 ) {
  rev( a, n );
  for( int m = 2; m <= n; m <<= 1 ) {
    cp wm = { cos( flag*2.0*PI/m ), sin( flag*2.0*PI/m ) };
    for( int k = 0; k < n; k += m ) {
      cp w = { 1.0, 0.0 };
      for( int j = k; j < k+(m>>1); ++j, w = w*wm ) {
        cp u = a[ j ], v = a[ j+(m>>1) ]*w;
        a[ j ] = u+v;
        a[ j+(m>>1) ] = u-v;
      }
    }
  }
}

void mul( ll* arr, cp* a, cp* b, int n ) {
  dft( a, n ); dft( b, n );
  for( int i = 0; i < n; ++i ) {
    a[ i ] = a[ i ]*b[ i ];
  }
  dft( a, n, -1 );
  for( int i = 0; i < n; ++i ) {
    arr[ i ] = round( a[ i ].r/lf(n) );
  }
}

int n;
ll arr[ (1<<20)+10 ];
cp a[ (1<<20)+10 ], b[ (1<<20)+10 ];

int st[ (1<<19)+10 ][ LOG2 ];

int query( int f, int t ) {
  int j = 31-__builtin_clz( t-f+1 );
  int ida = st[ f ][ j ];
  int idb = st[ t-(1<<j)+1 ][ j ];
  if( arr[ ida ] > arr[ idb ] ) {
    return ida;
  }
  return idb;
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

  for( int i = 1; i < (1<<19); ++i ) {
    for( int j = i; j < (1<<19); j += i ) {
      ++arr[ j ];
    }
  }

  for( int i = 0; i < (1<<20); ++i ) {
    a[ i ] = b[ i ] = { 0, 0 };
  }

  for( int i = 0; i < (1<<19); ++i ) {
    a[ i ] = b[ i ] = { lf(arr[ i ]), 0 };
  }

  mul( arr, a, b, 1<<20 );

  for( int i = 0; i < (1<<19); ++i ) {
    st[ i ][ 0 ] = i;
  }

  for( int j = 1; j < LOG2; ++j ) {
    for( int i = 0; i+(1<<j)-1 < (1<<19); ++i ) {
      int ida = st[ i ][ j-1 ];
      int idb = st[ i+(1<<(j-1)) ][ j-1 ];
      if( arr[ ida ] > arr[ idb ] ) {
        st[ i ][ j ] = ida;
      } else {
        st[ i ][ j ] = idb;
      }
    }
  }

  cin >> n;

  while( n-- ) {
    int f, t; cin >> f >> t;
    int idx = query( f, t );
    cout << idx << ' ' << arr[ idx ] << '\n';
  } 

  return 0;
}