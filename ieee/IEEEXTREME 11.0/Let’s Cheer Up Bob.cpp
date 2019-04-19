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

const pii w[8][3] = { { {0,0}, {0,1}, {0,2} },
                      { {1,0}, {1,1}, {1,2} },
                      { {2,0}, {2,1}, {2,2} },
                      { {0,0}, {1,0}, {2,0} },
                      { {0,1}, {1,1}, {2,1} },
                      { {0,2}, {1,2}, {2,2} },
                      { {0,0}, {1,1}, {2,2} },
                      { {0,2}, {1,1}, {2,0} } };

int board[3][3];
int x[9], y[9];

vpii ans, cur;

bool win() {
  for( int i = 0; i < 8; ++i ) {
    bool ok = true;
    for( int j = 0; j < 3; ++j ) {
      ok &= board[ w[i][j].FI ][ w[i][j].SE ] == board[ w[i][0].FI ][ w[i][0].SE ];
    }
    if( ok && board[ w[i][0].FI ][ w[i][0].SE ] != 0 ) return true;
  }
  return false;
}

void dfs( int t ) {
  if( win() ) {
    if( t == 1 && ( SIZE(ans) == 0 || SIZE(cur) < SIZE(ans) || ( SIZE(cur) == SIZE(ans) && cur < ans ) ) ) {
      ans = cur;
    }
    return ;
  }
  if( t == 0 ) {
    for( int i = 0; i < 9; ++i ) {
      if( !board[ x[i] ][ y[i] ] ) {
        board[ x[i] ][ y[i] ] = 1;
        dfs( 1 );
        board[ x[i] ][ y[i] ] = 0;
        break;
      }
    }
  } else {
    for( int i = 0; i < 3; ++i ) {
      for( int j = 0; j < 3; ++j ) {
        if( !board[i][j] ) {
          board[ i ][ j ] = 2;
          cur.PB( {i,j} );
          dfs( 0 );
          cur.pop_back();
          board[ i ][ j ] = 0;
        }
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

  for( int i = 0; i < 9; ++i ) {
    cin >> x[i]  >> y[i];
    x[i]--; y[i]--;
  }

  dfs( 0 );  

  for( auto& e : ans ) {
    cout << e.FI+1 << ' ' << e.SE+1 << '\n';
  }

  return 0;
}

