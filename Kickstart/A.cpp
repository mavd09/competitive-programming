#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 5e3 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

int main() {

  int n_test; scanf( "%d", &n_test );

  for( int tc = 1; n_test--; ++tc ) {
    int n; scanf( "%d", &n );
    vector<int> cnt(MAXN);
    for( int i = 0; i < n; ++i ) {
      int a, b; scanf( "%d %d", &a, &b );
      cnt[a]++; cnt[b+1]--;
    }
    vector<int> ans(MAXN);
    int acc = 0;
    for( int i = 1; i < MAXN; ++i ) {
      acc += cnt[i];
      ans[i] = acc;
    }
    int p; scanf( "%d", &p );
    printf( "Case #%d:", tc );
    for( int i = 0; i < p; ++i ) {
      int a; scanf( "%d", &a );
      printf( " %d", ans[a] );
    }
    puts( "" );
  }

  return 0;
}