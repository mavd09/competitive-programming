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

void doit( vi& v, vi& a, int cost, ll& ans ) {
  int id = 0;
  while( id < n && v[id] != a[0] ) id++;
  while( id != 0 ) {
    for( int j = 0; j < n; ++j ) {
      if( v[j] == a[id] ) {
        if( v[j]+v[id] == cost ) ans -= cost;
        else ans += v[j]+v[id];
        swap( v[j], v[id] );
        id = j;
        break;
      }
    }
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

  while( cin >> n ) {
    if( n == 0 ) break;
    vi v(n);
    for( auto& e : v ) cin >> e;
    vi a = v;
    sort( ALL(a) );
    ll ans = 0;
    doit( v, a, 0, ans );
    for( int i = n-1; i >= 0; --i ) {
      if( v[i] == a[i] ) continue;
      swap( v[0], v[i] );
      ans += v[0]+v[i];
      doit( v, a, v[0]+v[i], ans );
    }
    cout << ans << '\n';
  }

  return 0;
}

