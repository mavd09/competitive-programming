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

  while( n_test-- ) {
    memset( cnt, 0, sizeof(cnt) );
    cin >> n;
    ll acc = 0;
    for( int i = 0; i < n; ++i ) {
      int x; cin >> x;
      cnt[x]++;
      acc--;
    }
    priority_queue< pii, vpii, greater<pii> > pq;
    for( int i = 1; i <= n; ++i ) {
      if( cnt[i] == 0 ) continue;
      pq.push( { 2LL*cnt[i], i } );
    }
    vi ans;
    while( !pq.empty() ) {
      pii cur = pq.top(); pq.pop();
      if( acc+cur.FI > 0 ) break;
      acc += cur.FI;
      ans.PB( cur.SE );
    }
    cout << SIZE(ans) << '\n';
    sort( ALL(ans) );
    for( int i = 0; i < SIZE(ans); ++i ) {
      if( i ) cout << ' ';
      cout << ans[i];
    }
    cout << '\n';
  }

  return 0;
}

