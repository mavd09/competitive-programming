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

bool is_prime( int x ) {
  for( int i = 2; i*i <= x; i++ ) {
    if( x%i == 0 ) {
      return false;
    }
  }
  return true;
}

bool is_palindrome( int x ) {
  int y = 0;
  for( int i = x; i > 0; i /= 10 ) {
    y = y*10 + ( i%10 );
  }
  return x == y;
}

string f( int x ) {
  string r = "";
  set< int > seen;
  seen.insert( 1 );
  int a = 10, b = x;
  for( int i = 0; i < 100000; i++ ) {
    if( b > a ) {
      r.PB( '0' );
    } else {
      r.PB( (a/b)+'0' );
      a %= b;
    }
    if( a == 1 ) break;
    a *= 10;
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

  vi v;
  vector< string > vv;

  for( int i = 10; i < 100000; i++ ) {
    if( is_prime( i ) && is_palindrome( i ) ) {
      v.PB( i );
      vv.PB( f( i ) );
    }
  }

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    int x; cin >> x;
    for( int i = 0; i < SIZE( v ); i++ ) {
      if( x == v[ i ] ) {
        cout << "0." << vv[ i ] << "\n";
        break;
      }
    }
  }

  return 0;
}