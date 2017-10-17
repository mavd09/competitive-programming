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

const int MAXN = int( 2e6 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int nxt[ MAXN ][ 11 ];

bool overflow( ull a, ull b ) {
  return a > LLONG_MAX-b;
}

string to_str( ull x ) {
  stringstream os; os << x;
  return os.str( ); 
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

  vector< ull > fib = { 1, 1 };
  for( int i = 2; ; i++ ) {
    if( overflow( fib[ i-2 ], fib[ i-1 ] ) ) {
      break;
    }
    fib.PB( fib[ i-2 ]+fib[ i-1 ] );
  }

  vector< string > fib_str;
  for( auto& e : fib ) {
    fib_str.PB( to_str( e ) );
  }

  //cout << SIZE( fib ) << "\n";

  for( string str; cin >> str; ) {
    str = " "+str;
    int n = SIZE( str );
    memset( nxt, -1, sizeof( nxt ) );
    for( int i = n-1; i >= 0; i-- ) {
      for( int j = 0; j < 10; j++ ) {
        nxt[ i ][ j ] = nxt[ i+1 ][ j ];
      }
      if( '0' <= str[ i+1 ] && str[ i+1 ] <= '9' ) {
        nxt[ i ][ str[ i+1 ]-'0' ] = i+1;
      }
    }
    set< string > ans;
    for( int i = 0; i < SIZE( fib_str ); i++ ) {
      for( int j = 0; j < SIZE( fib_str ); j++ ) {
        if( i == j ) continue;
        int id = 0;
        for( auto& e : fib_str[ i ] ) {
          if( id == -1 ) {
            break;
          }
          id = nxt[ id ][ e-'0' ];
        }
        for( auto& e : fib_str[ j ] ) {
          if( id == -1 ) {
            break;
          }
          id = nxt[ id ][ e-'0' ];
        }
        if( id != -1 ) {
          ans.insert( fib_str[ i ]+fib_str[ j ] );
        }  
      }
      
    }
    cout << SIZE( ans ) << "\n";
  }


  return 0;
}