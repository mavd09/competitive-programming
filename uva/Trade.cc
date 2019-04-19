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
set< int > s;

void dfs( vector< vi >& all, int i, int j ) {
  if( i == n ) {
    s.insert( j );
    return ;
  }
  if( SIZE(all[i]) == 0 ) dfs( all, i+1, j );
  else {
    for( int k = 0; k < SIZE(all[i]); ++k ) {
      dfs( all, i+1, j+all[i][k] );
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

  for( int tc = 1; cin >> n; ++tc ) {
    if( n == 0 ) break;
    int ans = 0;
    vector< vi > all;
    for( int i = 0; i < n; ++i ) {
      int m; cin >> m;
      vi cur;
      int best = -oo, acc = 0;
      for( int j = 0; j < m; ++j ) {
        int x; cin >> x;
        acc += (10-x);
        if( acc > best ) {
          best = acc;
          cur.clear();
        }
        if( acc == best ) {
          cur.PB( j+1 );
        }
      }
      if( best < 0 ) {
        cur.clear();
        best = 0;
      } else if( best == 0 ) {
        cur.PB( 0 );
      }
      ans += best;
      all.PB( cur );
    }
    if( tc > 1 ) cout << '\n';
    cout << "Workyards " << tc << '\n';
    cout << "Maximum profit is " << ans << ".\n";
    s.clear();
    dfs( all, 0, 0 );
    cout << "Number of pruls to buy:";
    int cnt = 0;
    for( auto& e : s ) {
       if( cnt == 10 ) break;
       cout << " " << e;
       cnt++;
    }
    cout << '\n';
  }

  return 0;
}

