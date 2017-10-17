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

const double PI = acos( -1.0 );
const double A  = -4.9;
const double D  = PI/180.0;

const double F  = 100.0;

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

  cout << fixed << setprecision( 2 );

  double x0, y0, x1, y1, v;

  while( cin >> x0 >> y0 >> x1 >> y1 >> v ) {
    bool ok = false;
    double ans = -1;
    double c = y0-y1;
    for( int angle = 0; angle <= 9000; angle++ ) {
      for( int j = 0; j < 2; j++ ) {
        double b = v*sin( ( angle/F + ( j*0.5 ) )*D );
        double f = b*b - 4.0*A*c;
        //cout << A << " " << b << " " << c << endl; 
        if( f >= 0.0 ) {
          f = sqrt( f );
          double t1 = ( -b + f )/( 2.0*A );
          double t2 = ( -b - f )/( 2.0*A );
          if( t1 >= 0.0 ) {
            if( x1 == int( v*cos( angle*D/F )*t1 + x0 ) ) {
              ans = ( angle/F + ( j*0.5 ) );
              ok = true;
              break;
            }
          }
          if( t2 >= 0.0 ) {
            if( x1 == int( v*cos( angle*D/F )*t2 + x0 ) ) {
              ans = ( angle/F + ( j*0.5 ) );
              ok = true;
              break;
            }
          }
        }
      }
      if( ok ) break;
    }
    if( ans == -1 ) {
      cout << "Impossible\n";
    } else {
      cout << ans << "\n";
    }
  }

  return 0;
}