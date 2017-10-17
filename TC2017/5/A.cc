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

const int MAXN = int( 1e3 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n;
ll x[ MAXN ], y[ MAXN ];

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
      cin >> x[ i ] >> y[ i ];
    }
    map< pll, set< int > > cnt;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        if( i == j || y[ i ] == y[ j ] ) {
          continue;
        }
        pll b;
        if( x[ i ] == x[ j ] ) {
          b = { x[ i ], 1 };
        } else {
          ll dx = x[ i ]-x[ j ], dy = y[ i ]-y[ j ];
          b = { -y[ i ]*dx + dy*x[ i ], dy };
          ll gcd = __gcd( abs(b.FI), abs(b.SE) );
          b.FI /= gcd; b.SE /= gcd;
          ll sgn = 1;
          if( b.FI*b.SE < 0 ) {
            sgn = -1;
          } 
          b.FI = abs( b.FI )*sgn;
          b.SE = abs( b.SE );
        }
        cnt[ b ].insert( y[ i ] > y[ j ] ? i : j );
      }
    }
    set< int > ans;
    for( auto& k : cnt ) {
      //cout << k.FI.FI << ' ' << k.FI.SE << ' ' << SIZE( k.SE ) << endl;
      ans.insert( SIZE( k.SE ) );
    }
    cout << SIZE( ans )+1 << '\n';
  }

  return 0;
}