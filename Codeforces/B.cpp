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
const ll  oo   = LLONG_MAX;

ll ts, tf, t;
int n;
vector< pll > a;
ll ans, best;

void update( ll w, ll x ) {
  if( x+t <= tf && best > w ) {
    best = w;
    ans = x;
  }
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

  while( cin >> ts >> tf >> t >> n ) {
    a.clear( );
    for( int i = 0; i < n; i++ ) {
      ll x; cin >> x;
      if( a.empty( ) || a.back( ).FI != x )
        a.PB( { x, 0 } );
      a.back( ).SE++;
    }
    ll curt = ts;
    ans = -1; best = oo;
    update( ts, 0 );
    if( n ) {
      if( ts < a[ 0 ].FI )
        update( 0, ts );
      else
        update( ts-a[ 0 ].FI+1, a[ 0 ].FI-1 );
    }
    else
      update( 0, ts );
    for( int i = 0; i < SIZE( a ); i++ ) {
      ll t1 = a[ i ].FI-1;
      if( curt <= t1 )
        update( 0, curt );
      else
        update( curt-t1, t1 );
      curt = max( curt, a[ i ].FI );
      curt += a[ i ].SE*t;
      update( curt-a[ i ].FI, a[ i ].FI );
    }
    update( 0, curt );
    cout << ans << "\n";
  }

  return 0;
}