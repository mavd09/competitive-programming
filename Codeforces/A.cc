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

const int MAXN = int( 1e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

string target;
int n;
string dict[ MAXN ];

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

  while( cin >> target >> n ) {
    bool ok = false;
    for( int i = 0; i < n; ++i ) {
      cin >> dict[i];
      ok |= dict[i] == target;
    }
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        if( dict[i][1] == target[0] && dict[j][0] == target[1] ) {
          ok = true;
        }
      }
    }
    cout << (ok?"YES":"NO") << '\n';
  }

  return 0;
}

