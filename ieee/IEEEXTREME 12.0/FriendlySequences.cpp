#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 310;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

int n;
int arr[MAXN];

int dp[MAXN][MAXN][MAXN];

int add( int a, int b ) { return a+b >= MOD ? a+b-MOD : a+b; }

int go( int sum, int lst, int idx ) {
  if( idx == n ) return 1;
  if( sum+lst > arr[idx] ) return 0;
  int& r = dp[sum][lst][idx];
  if( r != -1 ) return r;
  r = go( sum, lst+1, idx );
  if( sum+lst <= arr[idx] ) 
    r = add( r, go(sum+lst, lst, idx+1) );
  return r;
}

int main() {

  while( scanf( "%d", &n ) == 1 ) {
    for( int i = 0; i < n; ++i ) scanf( "%d", arr+i );
    for( int i = n-2; i >= 0; --i ) arr[i] = min( arr[i], arr[i+1] );
    // n = arr[n-1] <= n ? arr[n-1] : 0;
    memset( dp, -1, sizeof(dp) );
    printf( "%d\n", go(0,0,0) ); 
  }

  return 0;
}