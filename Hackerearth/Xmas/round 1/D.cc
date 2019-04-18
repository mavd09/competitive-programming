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

struct Data { int value, tp; };

stack<Data> st;

bool is_number( string str ) {
  for( int i = 0; i < SIZE(str); ++i ) {
    if( !( '0' <= str[i] && str[i] <= '9' ) ) {
      return false;
    }
  }
  return true;
}

bool is_boolean( string str ) {
  return str == "true" || str == "false";
}

int to_int( string str ) {
  stringstream ss(str);
  int x; ss >> x;
  return x;
}

int to_bool( string str ) {
  return str == "true";
}

void print( string msg ) {
  cout << msg << '\n';
  exit(0);
}

void doit( int tp ) {
  if( SIZE(st) < 2 ) print( "SYNTAX ERROR" );

  Data a = st.top(); st.pop();
  Data b = st.top(); st.pop();
  if( a.tp != b.tp ) print( "TYPE ERROR" );

  if( tp == 0 ) {
    if( a.tp == 1 ) print( "TYPE ERROR" );
    st.push( {a.value+b.value, 0} );
  } else if( tp == 1 ) {
    if( a.tp == 1 ) print( "TYPE ERROR" );
    st.push( {a.value*b.value, 0} );
  } else if( tp == 2 ) {
    if( a.tp == 1 ) print( "TYPE ERROR" );
    st.push( {a.value == b.value, 1} );
  } else if( tp == 3 ) {
    if( a.tp == 0 ) print( "TYPE ERROR" );
    st.push( {a.value && b.value, 1} );
  } else if( tp == 4 ) {
    if( a.tp == 0 ) print( "TYPE ERROR" );
    st.push( {a.value || b.value, 1} );
  } else {
    assert( false );
  }
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

  for( string str; cin >> str; ) {
    if( is_number(str) ) {
      st.push( {to_int(str), 0} );
    } else if( is_boolean(str) ) {
      st.push( {to_bool(str), 1} );
    } else if( str == "+" ) {
      doit( 0 );
    } else if( str == "*" ) {
      doit( 1 );
    } else if( str == "==" ) {
      doit( 2 );
    } else if( str == "and" ) {
      doit( 3 );
    } else if( str == "or" ) {
      doit( 4 );
    } else {
      assert( false );
    }
  }

  if( SIZE(st) != 1 ) print( "SYNTAX ERROR" );

  Data ans = st.top(); st.pop();
  if( ans.tp == 0 ) cout << ans.value << '\n';
  else cout << ( ans.value ? "true" : "false" ) << '\n';

  return 0;
}

