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

int n;
ll l, d, a;
ll x[ MAXN ], mn[ MAXN ], mx[ MAXN ];

lf solve( lf a, lf b, lf c ) {
  lf d = b*b - 4.0*a*c;
  if( d < 0 ) {
    assert( false );
    return -1.0;
  }
  d = sqrt( d );
  return max( (-b+d)/(2.0*a), (-b-d)/(2.0*a) );
}

int main( ) {

  /*#ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );*/
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  //#endif

  cout << fixed << setprecision(2);
  while( cin >> n >> l >> a >> d ) {
    if( n == -1 ) {
      break;
    }
    d = -d;
    lf t = 0;
    ll curv = 0LL, curx = 0LL;
    bool flag = true;
    for( int i = 0; i < n; ++i ) {
      cin >> x[ i ] >> mn[ i ] >> mx[ i ];
      mx[ i ] *= mx[ i ];
      mn[ i ] *= mn[ i ];
      mx[ i ] = min( mx[ i ], curv + 2*a*(x[i]-curx) );
      curv = mx[ i ];
      curx = x[ i ];
    }
    curv = mx[ n-1 ];
    curx = l;
    for( int i = n-2; i >= 0; --i ) {
      mx[ i ] = min( mx[ i ], curv - 2*d*(curx-x[i]) );
      curv = mx[ i ];
      curx = x[ i ];
    }
    for( int i = 0; i < n; ++i ) {
        if( mx[ i ] < mn[ i ] )
          flag = false;
    }
    if( flag ) {
      lf time = 0.0, curv = 0, curx = 0;
      for( int i = 0; i < n; ++i ) {
        lf sqmx = sqrt( lf(mx[i]) );
        lf dx = x[i] - curx;
        lf dist = ( mx[i] - curv - 2.0*d*dx ) / ( 2.0*a - 2.0*d );
        lf v = sqrt(curv + 2.0*a*dist);
        time += ( v-sqrt(curv) )/lf(a);
        time += (sqmx-v)/lf(d);
        curv = mx[i];
        curx = x[i];
      }
      lf vf = mx[ n-1 ] + 2.0*a*( l-curx );
      time += (sqrt(vf) - sqrt(mx[ n-1 ])) / lf(a);
      //time += solve( 0.5*a, curv, curx-l );
      cout << time << '\n';
    }
    else {
      cout << "*\n";
    }
  }

  return 0;
}