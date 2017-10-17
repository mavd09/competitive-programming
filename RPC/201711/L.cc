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

const int T[6][4] = { {0,4,0,0}, {2,2,0,0}, {4,0,0,0}, {1,0,1,2}, {2,0,2,0}, {0,0,0,4} };

int arr[4], cur[4];

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

  vi p(6);
  for( int i = 0; i < 6; ++i ) {
    p[i] = i;
  }

  while( cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] ) {
    int ans = 0;
    do {
      int cnt = 0;
      memcpy( cur, arr, sizeof(int)*4 );
      for( int i = 0; i < 6; ++i ) {
        int mn = oo;
        for( int j = 0; j < 4; ++j ) {
          if( T[p[i]][j] == 0 ) continue;
          mn = min( mn, cur[j]/T[p[i]][j] );
        }
        cnt += mn;
        for( int j = 0; j < 4; ++j ) {
          cur[j] -= mn*T[p[i]][j];
        }
      }
      ans = max( ans, cnt );
    } while( next_permutation( ALL(p) ) );
    cout << ans << '\n'; 
  }

  return 0;
}

