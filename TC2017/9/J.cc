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

const int MAXN = int( 2e4 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n;
int arr[ MAXN ], lst[ MAXN ];

inline int add( int a, int b ) { return ( a+b )%n; }

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

  while( cin >> n ) {
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
      lst[ i ] = -1;
    }
    int fr, to;
    int acc = 0;
    for( int i = 0; i < n; ++i ) {
      acc = add( acc, arr[ i ] );
      if( acc == 0 ) {
        fr = 0;
        to = i;
        break;
      }
      if( lst[ acc ] == -1 ) {
        lst[ acc ] = i;
      } else {
        fr = lst[ acc ]+1;
        to = i;
        break;
      }
    }
    cout << to-fr+1 << '\n';
    for( int i = fr; i <= to; ++i ) {
      cout << arr[ i ] << '\n';
    }
  }

  return 0;
}