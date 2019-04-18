#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e5 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

ll solve( int len, ll* arr ) {
  ll mx = arr[0], cur = 0;
  for( int i = 0; i < len; ++i ) {
    if( cur < 0 || cur+arr[i] < 0 ) {
      cur = 0;
    }
    cur += arr[i];
    mx = max( mx, cur );
  }
  return mx;
}

int n, m;
ll a[MAXN], b[MAXN];

int main() {

  cin >> n >> m;
  for( int i = 0; i < n; ++i ) scanf( "%lld", a+i );
  for( int i = 0; i < m; ++i ) scanf( "%lld", b+i );

  ll ans = 1LL * solve(n, a) * solve(m, b);

  for( int i = 0; i < n; ++i ) a[i] = -a[i];
  for( int i = 0; i < m; ++i ) b[i] = -b[i];

  ans = max( ans, 1LL * solve(n, a) * solve(m, b) );

  sort( a, a+n ); sort( b, b+m );

  ans = max( ans, max(a[0]*b[m-1], a[n-1]*b[0]) );

  printf( "%lld\n", ans );

  return 0;
}