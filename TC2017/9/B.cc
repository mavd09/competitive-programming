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
const int MOD  = int( 360 );
const int oo   = INT_MAX;

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

void mul( ll* r, cp* a, cp* b, int n ) {
  dft( a, n ); dft( b, n );
  for( int i = 0; i < n; ++i ) {
    a[ i ] = a[ i ]*b[ i ];
  }
  dft( a, n, -1 );
  for( int i = 0; i < n; ++i ) {
    r[ i ] = round( a[ i ].r/lf(n) );
  }
}

int n;
int arr[ MAXN ];

ll cnt_a[ 1<<15 ], cnt_b[ 1<<15 ];

cp a[ 1<<16 ], b[ 1<<16 ];
ll r[ 1<<16 ];

void init( ) {
  memset( cnt_a, 0, sizeof( cnt_a ) );
  memset( cnt_b, 0, sizeof( cnt_b ) );
  for( int i = 0; i < (1<<16); ++i ) {
    a[ i ] = b[ i ] = { 0, 0 };
  }
} 

ll solve( int f, int t ) {
  if( t-f+1 <= 2 ) {
    return 0;
  }
  int m = ( f+t )>>1;
  ll ways = solve( f, m ) + solve( m+1, t );
  init( );
  for( int i = f; i <= m; ++i ) {
    a[ arr[ i ] ].r += 1.0;
    cnt_a[ arr[ i ] ]++;
  }
  for( int i = m+1; i <= t; ++i ) {
    b[ arr[ i ] ].r += 1.0;
    cnt_b[ arr[ i ] ]++;
  }
  mul( r, a, b, 1<<16 );
  cnt_a[ arr[ f ] ]--;
  for( int i = f+1; i <= m; ++i ) {
    cout << arr[ i ] << "**** " << r[ 2*arr[ i ] ] << '\n';
    ways += r[ 2*arr[ i ] ] - cnt_a[ arr[ i ] ]*cnt_b[ arr[ i ] ];
    cnt_a[ arr[ i ] ]--;
  }
  for( int i = f; i <= m; ++i ) {
    cnt_a[ arr[ i ] ]++;
  }
  for( int i = m+1; i < t; ++i ) {
    cout << arr[ i ] << "**** " << r[ 2*arr[ i ] ] << '\n';
    ways += r[ 2*arr[ i ] ] - cnt_b[ arr[ i ] ]*cnt_a[ arr[ i ] ];
    cnt_b[ arr[ i ] ]--;
  }
  cout << f << ' ' << t << '=' << ways << '\n';
  for( int i = 0; i < 18; ++i ) {
    cout << r[ i ] << ' ';
  }
  cout << endl;
  return ways;
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

  while( cin >> n ) {
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
    }
    cout << solve( 0, n-1 ) << '\n';
  }

  return 0;
}