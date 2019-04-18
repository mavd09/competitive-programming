#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int, int> pii;

const int MAXN = 3e2 + 10;
const int MOD = 1e9 + 7;
const int oo = 1e9;

int n, m;
char b[MAXN][MAXN];

ll ans[MAXN+MAXN];
int acc[3*MAXN][3*MAXN];

int get_sum( int fx, int fy, int tx, int ty ) {
  int r = acc[tx][ty];
  if(fx) r -= acc[fx-1][ty];
  if(fy) r -= acc[tx][fy-1];
  if(fx && fy) r += acc[fx-1][fy-1];
  return r;
}

int main() {

  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
  #endif // LOCAL

  int n_test; scanf( "%d", &n_test );

  while( n_test-- ) {
    scanf( "%d %d", &n, &m );
    for( int i = 0; i < n; ++i ) {
      scanf( "%s", b[i] );
    }
    memset(ans, 0, sizeof(ans));
    memset(acc, 0, sizeof(acc));
    int mn_x = oo, mx_x = 0, mn_y = oo, mx_y = 0;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        acc[i-j+m][i+j] = b[i][j]-'0';
        mn_x = min( mn_x, i-j+m );
        mx_x = max( mx_x, i-j+m );
        mn_y = min( mn_y, i+j );
        mx_y = max( mx_y, i+j );
      }
    }

    for( int i = mn_x; i <= mx_x; ++i ) {
      for( int j = mn_y; j <= mx_y; ++j ) {
        cout << ( acc[i][j] ? '1' : '_' ) << ' ';
      }
      cout << endl;
    }

    for( int i = 0; i < 3*MAXN; ++i ) {
      for( int j = 0; j < 3*MAXN; ++j ) {
        if(i) acc[i][j] += acc[i-1][j];
        if(j) acc[i][j] += acc[i][j-1];
        if(i && j) acc[i][j] -= acc[i-1][j-1];
      }
    }

    int tot = n+m-2;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        if( b[i][j] == '0' ) continue;
        int ni = i-j+m, nj = i+j;
        int cur = 1;
        for( int k = 1; k <= tot; ++k ) {
          int fx = max(ni-k,mn_x), fy = max(nj-k,mn_y);
          int tx = min(ni+k,mx_x), ty = min(nj+k,mx_y);
          int cur_sum = get_sum(fx,fy,tx,ty);
          ans[k] += cur_sum-cur;
          cur = cur_sum;
        }
      }
    }
    for( int i = 1; i <= tot; ++i ) {
      printf( "%lld%c", ans[i]>>1, " \n"[i==tot] );
    }
  }

  return 0;
}
