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

void print( vi& v ) {
  for( int i = 0; i < 11; ++i ) {
    cout << v[i] << ' ';
  }
  cout << endl;
}

int f( int x, int t ) {
  vi v(20);
  v[x] = 1;
  while( t-- ) {
    for( int i = 0; i+1 <= x; ++i ) {
      v[i] += v[i+1];
    }
  }
  return v[0];
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

  int ans = 0;
  for( int i = 1; i <= 10; ++i ) {
    int best = 0;
    for( int j = 0; j <= 10; ++j ) {
      best = max( best, f( j, 10-i ) );
    }
    ans += best;
  }

  cout << ans << '\n';

  return 0;
}

