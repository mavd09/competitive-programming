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

string a, b;

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

  while( getline( cin, a ) ) {
    getline( cin, b );
    int aa = 0, bb = 0;
    for( int i = 0; i < SIZE(a); i++ ) {
      if( a[i] == b[i] ) continue;
      if( a[i] == '8' && b[i] == '[' ) aa++;
      if( a[i] == '[' && b[i] == '(' ) aa++;
      if( a[i] == '(' && b[i] == '8' ) aa++;
      if( b[i] == '8' && a[i] == '[' ) bb++;
      if( b[i] == '[' && a[i] == '(' ) bb++;
      if( b[i] == '(' && a[i] == '8' ) bb++;
    }
    if( aa > bb ) cout << "TEAM 1 WINS\n";
    if( aa < bb ) cout << "TEAM 2 WINS\n";
    if( aa == bb ) cout << "TIE\n";
  }

  return 0;
}

