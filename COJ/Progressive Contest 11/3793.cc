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

const int MAXN = int( 5e3 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, k;
string name[ MAXN ];
int freq[ MAXN ];

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

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    cin >> n >> k;
    priority_queue< pii, vector< pii >, greater< pii > > pq;
    for( int i = 0; i < n; i++ ) {
      cin >> name[ i ] >> freq[ i ];
      pq.push( { freq[ i ], i } );
    }
    for( int i = 0; i < k; i++ ) {
      pii cur = pq.top( ); pq.pop( );
      cout << cur.FI << " " << name[ cur.SE ] << "\n";
      cur.FI += freq[ cur.SE ];
      pq.push( cur );
    }
  }

  return 0;
}