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

const int MAXN = int( 2e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int seen[ MAXN ];

int doit( int p, int sz, int d = 0 ) {
  if( seen[p] != -1 ) return d-seen[p];
  seen[p] = d;
  if( p*2 >= sz ) return doit( (p-sz/2)*2, sz, d+1 );
  return doit( p*2+1, sz, d+1 );
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

  //memset( seen, -1, sizeof(seen) );
  //cout << doit( 0,  100002 ) << '\n';
  //for( int i = 2; i <= 200; i += 2 ) {
    //memset( seen, -1, sizeof(seen) );
    //cout << i << " = " << doit( 0, i ) << '\n';
    //doit( 0, i );
  //}

  while( cin >> n ) {
    memset( seen, -1, sizeof(seen) );
    cout << doit( 0, n ) << '\n';
  }

  return 0;
}

