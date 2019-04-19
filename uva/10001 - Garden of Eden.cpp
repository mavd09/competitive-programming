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

typedef complex< lf >       pt;

const int MAXN = int( 2e5 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, mask;
string m;
int dp[ 50 ][ 10 ][ 10 ];

int go( int x, int lst, int fst ) {
  if( x == n-1 ) {
    if( ((fst>>2)&1) == ((lst>>0)&1) ) {
      int cur = ((lst<<1)&7) | ((fst>>1)&7);
      if( ((mask>>cur)&1) == ( m[ x ]-'0' ) )
        return 1;
    }
    return 0;
  }
  int& r = dp[ x ][ lst ][ fst ];
  if( r != -1 ) return r;
  r = 0;
  if( x == 0 ) {
    for( int i = 0; i < 8; i++ ) {
      int cur = i;
      if( ((mask>>cur)&1) == ( m[ x ]-'0' ) )
        r |= go( x+1, cur, cur );
    }
  }
  else {
    for( int i = 0; i < 2; i++ ) {
      int cur = ((lst<<1)&7)|i;
      if( ((mask>>cur)&1) == ( m[ x ]-'0' ) )
        r |= go( x+1, cur, fst );
    }
  }
  return r;
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

  while( cin >> mask >> n >> m ) {
    memset( dp, -1, sizeof( dp ) );
    if( go( 0, 0, 0 ) ) cout << "REACHABLE\n";
    else                cout << "GARDEN OF EDEN\n";
  }

  return 0;
}
