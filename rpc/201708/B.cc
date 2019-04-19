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

char rev[ 255 ];
string str;

bool check( char a, char b, char c ) {
  return ( a != b && a != c && b != c );
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

  rev[ 'R' ] = 'S';
  rev[ 'B' ] = 'K';
  rev[ 'L' ] = 'H';

  while( cin >> str ) {
    string ans = "";
    for( int i = 0; i < SIZE( str ); ) {
      if( i+2 < SIZE( str ) && check( str[ i ], str[ i+1 ], str[ i+2 ] ) ) {
        ans.PB( 'C' );
        i += 3;
      } else {
        ans.PB( rev[ str[ i ] ] );
        ++i;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}