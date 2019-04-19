#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e6 + 100;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

int n;
char str[MAXN];

int mx[MAXN], cnt[MAXN];

int main() {

  while( scanf( "%s", str ) == 1 ) {
    n = strlen(str);
    vector<int> p;
    int acc = 0;
    for( int i = 0; i < n; ++i ) {
      if( acc == 0 ) {
        p.push_back(i);
        mx[i] = cnt[i] = 0;
      }
      acc += str[i] == '(' ? 1 : -1;
      int id = p.back();
      if( acc > mx[id] ) {
        mx[id] = acc;
        cnt[id] = 0;
      }
      if( acc == mx[id] ) {
        cnt[id]++;
      }
    }
    for( auto& e : p ) cout << e << ' ' << mx[e] << ' ' << cnt[e] << '\n'; cout << endl;
  }

  return 0;
}