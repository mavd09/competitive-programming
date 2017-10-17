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

const int MAXN = int( 5e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int arr[ MAXN ], cnt[ MAXN ];

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
    memset( cnt, 0, sizeof(cnt) );
    for( int i = 0; i+2 < n; ++i ) {
      cin >> arr[i];
      cnt[ arr[i] ]++;
    }
    priority_queue< int, vi, greater<int> > pq;
    for( int i = 1; i <= n; ++i ) {
      if( cnt[i] == 0 ) {
        pq.push( i );
      }
    }
    set< pii > edge;
    bool ok = true;
    for( int i = 0; i+2 < n; ++i ) {
      if( pq.empty() ) {
        ok = false;
        break;
      }
      int u = pq.top(); pq.pop();
      int v = arr[i];
      if( u > v ) swap( u, v );
      edge.insert( { u, v } );
      if( --cnt[ arr[i] ] == 0 ) {
        pq.push( arr[i] );
      }
    }
    ok &= ( SIZE(pq) == 2 );
    if( ok ) {
      int u = pq.top(); pq.pop();
      int v = pq.top(); pq.pop();
      if( u > v ) swap( u, v );
      edge.insert( {u, v} );
    }
    if( ok ) {
      for( auto& e : edge )
        cout << e.FI << ' ' << e.SE << '\n';
    } else {
      cout << -1 << '\n';
    }
  }

  return 0;
}

