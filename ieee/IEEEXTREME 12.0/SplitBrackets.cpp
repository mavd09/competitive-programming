#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e5 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

int n;
char buff[MAXN];

bool seen[36][9][1<<9][9][1<<9];
int dp[36][9][1<<9][9][1<<9];

int go( int idx, int A, int a, int B, int b ) {
  if( idx == n ) return 0;
  int& r = dp[idx][a][A][b][B];
  if( seen[idx][a][A][b][B] ) return r;
  seen[idx][a][A][b][B] = true;
  r = 0;
  bool open = buff[idx] == '(' || buff[idx] == '[';
  bool sq = buff[idx] == '[' || buff[idx] == ']';
  if( open ) {
    if( a+1 <= n/4 ) r 
  } else {

  }
  return r;
}

int main() {

  scanf( "%s", buff );
  n = strlen(buff);



  return 0;
}