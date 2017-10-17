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
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const lf EPS = 1e-7;

lf a, b, c, d, L;

lf sqr( lf x ) { return x*x; };

lf dist( lf a, lf b, lf c, lf d ) {
  return sqrt( sqr(c-a) + sqr(d-b) );
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

  cout << fixed << setprecision(10);

  while( cin >> a >> b >> c >> d >> L ) {
    if( a+EPS > c && c+EPS > a ) {
      if( d+EPS > b ) swap( b, d );
      lf y = d-((L-b+d)/2.0);
      cout << a << ' ' << y << '\n';
      continue;
    }
    if( c+EPS < a ) {
      swap( c, a );
      swap( b, d );
    }
    lf e = (a+c)/2.0;
    lf f = min(b, d)-sqrt( sqr(L/2.0) - sqr((c-a)/2.0) );
    lf x, y;
    if( (d-b) > EPS ) {
      lf lo = a, hi = e;
      for( int it = 0; it < 100; ++it ) {
        lf x = (lo+hi)/2.0;
        lf y = (x*(f-b))/(e-a) + (b - (a*(f-b))/(e-a));
        lf l = dist( a, b, x, y )+dist( x, y, c, d );
        if( l-L < -EPS ) lo = x;
        else hi = x;
      }
      x = (lo+hi)/2.0; y = (x*(f-b))/(e-a) + (b - (a*(f-b))/(e-a));
    } else {
      lf lo = e, hi = c;
      for( int it = 0; it < 100; ++it ) {
        lf x = (lo+hi)/2.0;
        lf y = (x*(f-d))/(e-c) + (d - (c*(f-d))/(e-c));
        lf l = dist( a, b, x, y )+dist( x, y, c, d );
        if( l-L > EPS ) lo = x;
        else hi = x;
      }
      x = (lo+hi)/2.0; y = (x*(f-d))/(e-c) + (d - (c*(f-d))/(e-c)); 
    }
    cout << x << ' ' << y << '\n';
  }

  return 0;
}

