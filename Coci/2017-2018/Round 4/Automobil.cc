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

const int MAXN = int( 1e6 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

inline int add( int a, int b ) { return (a+b >= MOD ? a+b-MOD : a+b); }
inline int sbt( int a, int b ) { return (a-b < 0 ? a-b+MOD : a-b); }
inline int mul( int a, int b ) { return ll(a)*ll(b) % ll(MOD); }

inline int mod_mul( int a, int b ) {
  int x = 0, y = a;
  while( b ) {
    if( b&1 ) x = add( x, y );
    y = add( y, y );
    b >>= 1; 
  }
  return x;
}

inline int mod_pow( int b, int e ) {
  int r = 1;
  while( e ) {
    if( e&1 ) r = mul( r, b );
    b = mul( b, b );
    e >>= 1;
  }
  return r;
}

inline int inv( int x ) {
  return mod_pow( x, MOD-2 );
}

int g( int x ) {
  if( x < 0 ) return 0;
  return mul( mul(x,add(x,1)), inv(2) );
} 

int n, m, k;
int row[ MAXN ], col[ MAXN ];
int mrow[ MAXN ], mcol[ MAXN ];

int get_row( int r ) {
  return add( g(m), mul( mul(r-1,m), m ) );
}

int get_col( int c ) {
  return add( mul(n,c), mul( g(n-1), m ) );
}

int get_value( int r, int c ) {
  return add( c, mul( r-1, m ) );
}

int get_row_range( int r, int fc, int tc ) {
  return sbt( g(tc), g(fc-1) );
}

int get_square( int fr, int tr, int fc, int tc ) { 
  if( fr > tr || fc > tc ) return 0;
  int sum = get_row_range( fr, fc, tc );
  return add( mul(tr-fr+1,sum), mul( mul(m,tc-fc+1), sbt(g(tr-1), g(fr-2)) ) );
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d%d%d", &n, &m, &k ) == 3 ) {
    for( int i = 0; i < MAXN; ++i ) {
      mrow[i] = mcol[i] = 1;
    }
    vi sr, sc;
    sr.PB( 0 ); sr.PB( n+1 );
    sc.PB( 0 ); sc.PB( m+1 );
    for( int i = 0; i < k; ++i ) {
      char cmd; int x, y;
      scanf( " %c%d%d", &cmd, &x, &y );
      if( cmd == 'R' ) {
        sr.PB( x );
        mrow[x] = mul( mrow[x], y );
      } else {
        sc.PB( x );
        mcol[x] = mul( mcol[x], y );
      }
    }
    sort( ALL(sr) ); sr.resize( unique(ALL(sr))-sr.begin() );
    sort( ALL(sc) ); sc.resize( unique(ALL(sc))-sc.begin() );
    int ans = 0;
    for( int i = 0; i+1 < SIZE(sr); ++i ) {
      for( int j = 0; j+1 < SIZE(sc); ++j ) {
        int cur = get_square( sr[i]+1, sr[i+1]-1, sc[j]+1, sc[j+1]-1 );
        ans = add( ans, cur );
      }
    }
    for( int i = 1; i+1 < SIZE(sr); ++i ) {
      int sum = get_row(sr[i]);
      for( int j = 1; j+1 < SIZE(sc); ++j ) {
        sum = sbt( sum, get_value(sr[i],sc[j]) );
      }
      ans = add( ans, mul(mrow[sr[i]],sum) );
    }
    for( int j = 1; j+1 < SIZE(sc); ++j ) {
      int sum = get_col(sc[j]);
      for( int i = 1; i+1 < SIZE(sr); ++i ) {
        sum = sbt( sum, get_value(sr[i], sc[j]) );
      }
      ans = add( ans, mul(mcol[sc[j]],sum) );
    }
    for( int i = 1; i+1 < SIZE(sr); ++i ) {
      for( int j = 1; j+1 < SIZE(sc); ++j ) {
        ans = add( ans, mul( mul(mrow[sr[i]],mcol[sc[j]]), get_value(sr[i],sc[j]) ) );
      }
    }
    printf( "%d\n", ans );
  }

  return 0;
}

