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

  const ll LIMIT = ll( 1e12 );

  vll acc;
  acc.PB( 4LL );
  for( int lvl = 1; acc.back( ) < LIMIT; lvl++ )
    acc.PB( acc.back( ) + 4LL+8LL*lvl );

  int n_test;
  cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    ll n; cin >> n; n--;
    int lvl = upper_bound( ALL( acc ), n )-acc.begin( );
    if( lvl ) n -= acc[ lvl-1 ];
    ll t = 2LL + 4LL*lvl;
    if( n < t ) cout << t/2LL-1LL - n << " " << -lvl << "\n";
    else {
      n -= t; t /= 2LL;
      if( n < t ) cout << -t+n+1LL << " " << -lvl+n+1LL << "\n";
      else {
        n -= t;
        cout << n+1LL << " " << lvl-n << "\n";
      }
    }
  }

  return 0;
}