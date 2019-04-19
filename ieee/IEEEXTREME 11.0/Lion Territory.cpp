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
const int MAXX = 3002;
const int MAXY = 4002;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const int DELTAX = 1000;
const int DELTAY = 2000;

int n, m, k;
int x[ MAXN ], y[ MAXN ], t[ MAXN ];

int bit[ MAXX ][ MAXY ];

void update( int x, int y, int v ) {
  for( int i = x; i < MAXX; i += i&-i ) {
    for( int j = y; j < MAXY; j += j&-j ) {
       ( v  == 1 ? ++bit[i][j] : --bit[i][j] );
    }
  }
}

void update( int fx, int fy, int tx, int ty ) {
  update( fx, fy, 1 );
  update( fx, ty+1, -1 );
  update( tx+1, fy, -1 );
  update( tx+1, ty+1, 1 );
}

int query( int x, int y ) {
  int sum = 0;
  for( int i = x; i > 0; i -= i&-i ) {
    for( int j = y; j > 0; j -= j&-j ) {
      sum += bit[i][j];
    }
  }
  return sum;
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

  cin >> n >> m >> k;

  for( int i = 0; i < k; ++i ) {
    int d; cin >> x[i] >> y[i] >> d;
    int mxx = x[i]+y[i]+d + DELTAX, mnx = x[i]+y[i]-d + DELTAX;
    int mxy = y[i]-x[i]+d + DELTAY, mny = y[i]-x[i]-d + DELTAY;
    update( mnx, mny, mxx, mxy );
  }

  int ans = 0;
  for( int i = 0; i < k; ++i ) {
    t[ i ] = query( x[i]+y[i] + DELTAX, y[i]-x[i] + DELTAY );
    if( t[ans] < t[i] ) {
      ans = i;
    }
  }

  cout << ans+1 << ' ' << t[ans]-1 << '\n';

  return 0;
}

