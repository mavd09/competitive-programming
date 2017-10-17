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

int n;
int arr[ MAXN ];

bool check( ) {
  for( int i = 0; i < n; ++i ) {
    if( arr[i] != i ) {
      return false;
    }
  }
  return true;
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

  while( cin >> n ) {
    vi zip;
    for( int i = 0; i < n; ++i ) {
      cin >> arr[i];
      zip.PB( arr[i] );
    }
    sort( ALL(zip) );
    vi wrong;
    for( int i = 0; i < n; ++i ) {
      arr[i] = lower_bound( ALL(zip), arr[i] )-zip.begin();
      if( arr[i] != i ) {
        wrong.PB( i );
      }
    }
    if( SIZE(wrong) == 0 ) {
      cout << "yes\n";
    } else {   
      if( SIZE(wrong) == 2 ) {
        cout << "yes\n";
        cout << "swap " << wrong[0]+1 << ' ' << wrong[1]+1 << '\n';
      } else {
        reverse( arr+wrong[0], arr+wrong[SIZE(wrong)-1]+1 );
        if( check() ) {
          cout << "yes\n";
          cout << "reverse " << wrong[0]+1 << ' ' << wrong[SIZE(wrong)-1]+1 << '\n';
        } else {
          cout << "no\n";
        }
      }
    }
  } 

  return 0;
}

