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

int n, k;
int arr[ MAXN ];

bool can( ll t ) {
  int r = 0;
  for( int i = 0; i < n; ) {
    int j = i+1;
    ll sum = arr[i];
    while( j < n && sum+arr[j] <= t ) {
      sum += arr[j];
      j++;
    }
    if( sum > t ) 
      return false;
    r++;
    i = j;
  }
  return r <= k;
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

  while( cin >> n >> k ) {
    for( int i = 0; i < n; ++i ) {
      cin >> arr[i];
    }
    ll lo = 0, hi = 1e15;
    while( lo <= hi ) {
      ll mi = (lo+hi)>>1;
      if( !can( mi ) ) lo = mi+1;
      else hi = mi-1;
    }
    cout << lo << '\n';
  }

  return 0;
}

