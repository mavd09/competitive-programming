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
int cnt[ MAXN ];

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

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; ++tc ) {
    cin >> n;
    memset( cnt, 0, sizeof(cnt) );
    for( int i = 0; i < n; ++i ) {
      cin >> arr[i];
      cnt[ arr[i] ]++;
    }
    vi v;
    for( int i = 1;  i < MAXN; ++i ) {
      if( cnt[i] ) {
        v.PB( i );
        cnt[i]--;
      }
      if( cnt[i] ) {
        v.PB( i );
        cnt[i]--;
      }
    }
    bool flag = true;
    vi l, r;
    for( int i = 0; i < SIZE(v); ) {
      if( i+1 < SIZE(v) && v[i] == v[i+1] ) {
        l.PB( v[i] );
        r.PB( v[i] );
        i += 2;
        flag = true;
      } else {
        if( flag ) l.PB( v[i] );
        else r.PB( v[i] );
        i++;
        flag = !flag;
      }
    }
    vi ans;
    for( int i = 0; i < MAXN; ++i ) {
      while( cnt[i] ) {
        ans.PB( i );
        cnt[i]--;
      }
    }
    for( auto& e : l ) ans.PB( e );
    sort( ALL(ans) );
    reverse( ALL(r) );
    for( auto& e : r ) ans.PB( e );
    ll sum = 0;
    for( int i = 1; i < SIZE(ans); ++i ) {
      sum += ll(ans[i-1])*ll(ans[i]);
    }
    cout << sum << '\n';
    for( int i = 0; i < SIZE(ans); ++i ) {
      cout << ans[i] << " \n"[i+1==n];
    }
    assert( SIZE(ans) == n );
  }

  return 0;
}

