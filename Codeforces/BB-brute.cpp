#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;

const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};

int n, m, k;

int main() {

  // ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    assert(n <= 10000 && m <= 10000);
    bool seen[n][m];
    memset(seen, false, sizeof(seen));
    for(int i = 0; i < k; ++i) {
      int t, x, y; cin >> t >> x >> y;
      x--; y--;
      if(t == 1 || t == 3) {
        for(int j = 0; j < 4; ++j) {
          int xx = x, yy = y;
          while(0 <= xx && xx < n && 0 <= yy && yy < m) {
            seen[xx][yy] = true;
            xx += dx[j]; yy += dy[j];
          }
        }
      } 
      if(t == 2 || t == 3) {
        for(int j = 4; j < 8; ++j) {
          int xx = x, yy = y;
          while(0 <= xx && xx < n && 0 <= yy && yy < m) {
            seen[xx][yy] = true;
            xx += dx[j]; yy += dy[j];
          }
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        ans += !seen[i][j];
      }
    }
    cout << ans << endl;
  

  return 0;
}