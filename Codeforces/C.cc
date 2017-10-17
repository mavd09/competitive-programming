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

bool check( const vi& all, int mask ) {
  int t = __builtin_popcount(mask);
  for( int i = 0; i < k; ++i ) {
    int cnt = 0;
    for( int j = 0; j < SIZE(all); ++j ) {
      if( (mask>>j)&1 ) {
        cnt += ((all[j]>>i)&1);
      }
    }
    if( cnt*2 > t ) return false;
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

  while( cin >> n >> k ) {
    vi all;
    for( int i = 0; i < n; ++i ) {
      int mask = 0;
      for( int j = 0; j < k; ++j ) {
        int x; cin >> x;
        mask |= (x<<j);
      }
      all.PB( mask );
    }
    sort( ALL(all) );
    all.resize( unique( ALL(all) )-all.begin() );
    bool can = false;
    int sz = SIZE(all);
    for( int i = 1; i < (1<<sz); ++i ) {
      can |= check( all, i );
    }
    cout << (can?"YES":"NO") << '\n';
  }

  return 0;
}

