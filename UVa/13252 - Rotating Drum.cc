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

int k, n; 
deque< pii > graph[ MAXN ];
string ans;

int bin_pow( int b, int e ) {
  int r = 1;
  while( e ) {
    if( e&1 ) r = r*b;
    b = b*b;
    e >>= 1;
  }
  return r;
}

void go( int u ) {
  while( !graph[u].empty() ) {
    pii edge = graph[u].front();
    graph[u].pop_front();
    go( edge.FI );
    ans.PB( edge.SE+'A' );
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

  while( cin >> k >> n ) {
    if( k == 1 ) {
      cout << string( n, 'A' ) << '\n';
      continue;
    }
    int m = bin_pow( k, n );
    int mod = m/k;
    for( int u = 0; u < mod; ++u ) {
      for( int i = 0; i < k; ++i ) {
        graph[u].PB( {(u*k+i)%mod,i} );
      }
    }
    ans = string( n-1, 'A' );
    go( 0 );
    reverse( ans.begin()+n-1, ans.end() );
    cout << ans.substr(0,m) << '\n';
  }

  return 0;
}

