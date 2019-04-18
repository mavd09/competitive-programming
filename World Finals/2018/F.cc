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

const int MAXN = int( 3e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int arr[ MAXN ];

char buff[ MAXN ];
string str;

deque< int > to_set[ 2 ];
int dp[ 2 ][ MAXN*90 ];

void clr( int idx ) {
  for( ; !to_set[idx].empty(); to_set[idx].pop_front() )  {
    dp[idx][to_set[idx].front()] = 0;
  }
}

int get_best( int r, int c ) {
  return max( dp[r][c-1], max( dp[r][c], dp[r][c+1] ) );
}

int solve( int width ) {
  clr(0); clr(1);
  int idx = 0, cur_width = arr[0], best_river = 0;
  if( cur_width > width ) return 0;
  for( int i = 1; i < n; ++i ) {
    if( cur_width+1+arr[i] <= width ) {
      dp[idx][cur_width+1] = get_best(idx^1,cur_width+1) + 1;
      best_river = max( best_river, dp[idx][cur_width+1] );
      to_set[idx].push_back(cur_width+1);
      cur_width = cur_width+1+arr[i];
    } else if( arr[i] <= width ) {
      cur_width = arr[i];
      idx ^= 1;
      clr(idx);
    } else {
      return -1;
    }
  }
  return best_river;
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d", &n ) == 1 ) {
    for( int i = 0; i < n; ++i ) {
      scanf( "%s", buff );
      arr[i] = strlen(buff);
    }
    arr[n] = 0;
    int ans_river = 0, ans_width = oo, acc = 0;
    for( int i = 1; i <= n; ++i ) {
      acc += arr[i-1];
      for( int j = 0; j <= arr[i]; ++j ) {
        int cur_width = acc+i-1+j;
        int cur_river = solve(cur_width);
        if( cur_river > ans_river || ( cur_river == ans_river && cur_width < ans_width ) ) {
          ans_river = cur_river;
          ans_width = cur_width;
        }
      }
    }
    printf( "%d %d\n", ans_width, ans_river );
  }

  return 0;
}

