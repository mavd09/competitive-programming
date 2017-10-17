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

const int MAXN = 200;
const int MAXA = 400;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, r;
int acc[MAXN][MAXA*2];

int get_sum( int fx, int fy, int tx, int ty ) {
  int sum = acc[tx][ty];
  if(fx) sum -= acc[fx-1][ty];
  if(fy) sum -= acc[tx][fy-1];
  if(fx && fy ) sum += acc[fx-1][fy-1];
  return sum;
}

int f( int h, int H, int A ) {
  int ans = 0;
  for( int i = 0; i+A < 720; ++i ) {
    ans = max( ans, get_sum(h, i, h+H-1, i+A) );
  }
  return ans;
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

  while( cin >> n >> r ) {
    if( n == 0 && r == 0 ) break;
    memset( acc, 0, sizeof(acc) );
    for( int i = 0; i < n; ++i ) {
      int r, t; cin >> r >> t;
      acc[r][t]++;
      acc[r][t+360]++;
    }
    for( int i = 0; i <= r; ++i ) {
      for( int j = 0; j < 720; ++j ) {
        if(i) acc[i][j] += acc[i-1][j];
        if(j) acc[i][j] += acc[i][j-1];
        if(i && j) acc[i][j] -= acc[i-1][j-1];
      }
    }
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      int H, A; cin >> H >> A;
      int ans = 0;
      for( int h = 0; h+H-1 <= r; ++h ) {
        ans = max( ans, f( h, H, A ) );
      }
      cout << ans << '\n';
    }
  }

  return 0;
}

