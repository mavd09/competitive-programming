#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
  #define dbg(args...) { err("[dbg] ", args); }
#else
  #define dbg(args...)
#endif

void err() { cerr << endl; }
template<typename T, typename... Args>
void err(T a, Args... args) { cerr << a; err(args...); }

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e5 + 100;
const int oo = 1e9 + 100;
const int MOD = 1e9 + 9;
const lf EPS = 1e-9;

int tc;
int seen[13][64][1<<13];
int dp[13][64][1<<13];

int get_points(int cs, vector<int>& d) {
  int ans = 0;
  if(1 <= cs && cs <= 6) {
    int target = cs;
    for(auto& e : d)
      if(e == target)
        ans += e;
  }
  if(cs == 7) {
    for(auto& e : d)
      ans += e;
  }
  if(cs == 8 || cs == 9 || cs == 10) {
    int target = cs-5;
    for(int i = 1; i <= 6; ++i) {
      int t = 0;
      for(auto& e : d) {
        t += (e == i);
      }
      if(t >= target) {
        ans = target == 5 ? 50 : get_points(7, d);
        break;
      }
    }
  }
  if(cs == 11) {
    sort(d.begin(), d.end());
    for(int m = 0; m < 5; ++m) {
      bool cb = true;
      for(int i = 0, lst = -1; i < 5; ++i) {
        if(i == m) continue;
        if(lst == -1 || lst+1 == d[i]) {
          lst = d[i];
        } else {
          cb = false;
          break;
        }
      }
      if(cb) ans = 25;
    }
  }
  if(cs == 12) {
    sort(d.begin(), d.end());
    ans = 35;
    for(int i = 1; i < 5; ++i) {
      if(d[i] != d[i-1]+1) {
        ans = 0;
      }
    }
  }
  if(cs == 13) {
    sort(d.begin(), d.end());
    if(d[0] == d[1] && d[2] == d[3] && d[3] == d[4])
      ans = 40;
    if(d[0] == d[1] && d[1] == d[2] && d[3] == d[4])
      ans = 40;
  }
  return ans;
}

int go(vector<vector<int>>& all, int idx, int mask, int rm) {
  rm = min(63, rm);
  if(idx == 13) return rm == 63 ? 35 : 0;
  int& s = seen[idx][rm][mask];
  int& r = dp[idx][rm][mask];
  if(s == tc) return r;
  s = tc; r = 0;
  for(int i = 0; i < 13; ++i) {
    if((mask>>i)&1) continue;
    int p = get_points(i+1, all[idx]);
    r = max(r, go(all, idx+1, mask|(1<<i), rm + (i < 6 ? p : 0))+p);
  }
  return r;
}

void build(vector<vector<int>>& all, vector<int>& ans, int idx, int mask, int rm) {
  rm = min(63, rm);
  if(idx == 13) {
    if(rm == 63) {
      ans[0] += 35;
      ans[14] = 35;
    }
    return ;
  }
  for(int i = 0; i < 13; ++i) {
    if((mask>>i)&1) continue;
    int p = get_points(i+1, all[idx]);
    if(go(all, idx+1, mask|(1<<i), rm + (i < 6 ? p : 0))+p == go(all, idx, mask, rm)) {
      ans[0] += p;
      ans[i+1] = p;
      build(all, ans, idx+1, mask|(1<<i), rm + (i < 6 ? p : 0));
      return ;
    }
  }
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  vector<int> d(5);
  for(tc = 1; cin >> d[0]; ++tc) {
    vector<vector<int>> all;
    for(int i = 0; i < 13; ++i) {
      for(int j = (i == 0 ? 1 : 0); j < 5; ++j) {
        cin >> d[j];
      }
      all.push_back(d);
    }
    vector<int> ans(15);
    build(all, ans, 0, 0, 0);
    for(int i = 1; i <= 14; ++i) {
      cout << ans[i] << " ";
    }
    cout << ans[0] << endl;
  }

  return 0;
}