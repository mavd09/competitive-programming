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
ll s, arr[ MAXN ];

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

  while( cin >> n >> s ) {
    for( int i = 0; i < n; ++i ) {
      cin >> arr[i];
    }
    bool ok = false;
    ll sum = 0;
    for( int i = 0, j = 0; i < n; ++i ) {
      if( i == j ) sum += arr[j++];
      while( j < n && sum+arr[j] <= s ) {
        sum += arr[j++];
      }
      if( sum == s ) {
        ok = true;
        cout << i+1 << ' ' << j << '\n';
        break;
      }
      sum -= arr[i];
    }
    if( !ok ) cout << -1 << '\n';
  }

  return 0;
}

