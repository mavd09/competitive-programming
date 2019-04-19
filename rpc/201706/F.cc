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

const int MAXN = int( 3e3 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n, m;
string d[ MAXN ];
int g[ MAXN ];
set< int > v[ MAXN ];
int used[ MAXN ];

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
    cin >> n >> m;
    for( int i = 0; i < n; i++ ) {
      cin >> d[ i ];
    }
    sort( d, d+n );
    for( int i = 0; i < m; i++ ) {
      v[ i ].clear( ); g[ i ] = -1;
      int x; cin >> x;
      for( int j = 0; j < x; j++ ) {
        int t; string name; cin >> t >> name;
        int id = lower_bound( d, d+n, name )-d;
        if( t == 1 ) {
          g[ i ] = id;
        } else {
          v[ i ].insert( id );
        }
      }
    }
    bool ok = true;
    vector< string > ans;
    while( true ) {
      int id = -1;
      for( int i = 0; i < m; i++ ) {
        if( SIZE( v[ i ] ) == 0 ) {
          if( g[ i ] == -1 ) {
            ok = false;
            break;
          } else if( used[ g[ i ] ] != tc ) {
            id = g[ i ];
            used[ g[ i ] ] = tc;
            break;
          }
        }
      }
      if( id == -1 || !ok ) {
        break;
      }
      ans.PB( d[ id ] );
      for( int i = 0; i < m; i++ ) {
        if( SIZE( v[ i ] ) && v[ i ].count( id ) ) {
          v[ i ].erase( id );
        }
      }
    }
    if( !ok ) {
      cout << "Impossible\n";
    }
    else {
      sort( ALL( ans ) );
      cout << SIZE( ans ) << "\n";
      for( auto& e : ans ) {
        cout << e << "\n";
      }
    }
  }

  return 0;
}