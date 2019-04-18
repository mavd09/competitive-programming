#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e5 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

int main() {

  int n_test; scanf( "%d", &n_test );

  for( int tc = 1; n_test--; ++tc ) {
    ll e; int n; scanf( "%lld %d", &e, &n );
    deque<int> dq;
    for( int i = 0; i < n; ++i ) {
      int a; scanf( "%d", &a );
      dq.push_back(a);
    }
    sort( dq.begin(), dq.end() );
    int ans = 0, cur = 0;
    while( !dq.empty() ) {
      if( e > dq.front() ) {
        cur++;
        e -= dq.front();
        dq.pop_front();
      } else if( cur > 0 ) {
        cur--;
        e += dq.back();
        dq.pop_back();
      } else {
        dq.pop_front();
      }
      ans = max( ans, cur );
    }
    printf( "Case #%d: %d\n", tc, ans );
  }

  return 0;
}