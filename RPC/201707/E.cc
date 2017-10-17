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

int phi[ MAXN ];

int solve( string t, string p ) {
  phi[ 0 ] = -1;
  for( int i = 1, j = -1; i <= SIZE( p ); ++i ) {
    while( j >= 0 && p[ j ] != p[ i-1 ] ) {
      j = phi[ j ];
    }
    phi[ i ] = ++j;
  }
  int r = 0;
  for( int i = 0, j = 0; i < SIZE( t ); ++i ) {
    while( j >= 0 && t[ i ] != p[ j ] ) {
      j = phi[ j ];
    }
    j++;
    if( j == SIZE( p ) ) {
      r++;
      j = 0;
    }
  }
  return SIZE( t )-r*SIZE( p )+r;
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

  for( string msg; cin >> msg; ) {
    int ans = SIZE( msg );
    for( int i = 0; i < SIZE( msg ); ++i ) {
      for( int j = i; j < SIZE( msg ); ++j ) {
        int len_m = j-i+1;
        string m = msg.substr( i, len_m );
        ans = min( ans, solve( msg, m )+len_m );
      } 
    }
    cout << ans << '\n';
  }

  return 0;
}