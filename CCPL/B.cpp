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

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  vector<int> id(256);
  id['S'] = 0; id['H'] = 1;
  id['D'] = 2; id['C'] = 3;

  for(char ch = '2'; ch <= '9'; ++ch) {
    id[ch] = ch-'0';
  }
  id['A'] = 0; id['T'] = 10;
  id['J'] = 11; id['Q'] = 12;
  id['K'] = 13;

  string line;
  while(getline(cin, line)) {
    stringstream in(line);
    string card;
    vector<vector<int>> cnt(4, vector<int>(14));
    vector<vector<int>> suit(4);
    while(in >> card) {
      suit[id[card[1]]].push_back(id[card[0]]);
      cnt[id[card[1]]][id[card[0]]]++;
    }
    int p = 0;
    for(int i = 0; i < 4; ++i) {
      p += 4*cnt[i][id['A']];
      p += 3*cnt[i][id['K']];
      p += 2*cnt[i][id['Q']];
      p += 1*cnt[i][id['J']];
    }
    for(int i = 0; i < 4; ++i) {
      p -= (suit[i].size() <= 1 && cnt[i][id['K']] >= 1);
      p -= (suit[i].size() <= 2 && cnt[i][id['Q']] >= 1);
      p -= (suit[i].size() <= 3 && cnt[i][id['J']] >= 1);
    }
    int pp = p;
    for(int i = 0; i < 4; ++i) {
      p += 1*((int)suit[i].size() == 2);
      p += 2*((int)suit[i].size() <= 1);
    }
    int stopped = 0;
    for(int i = 0; i < 4; ++i) {
      if(cnt[i][0] == 1 || 
         (cnt[i][13] >= 1 && (int)suit[i].size()-cnt[i][13] >= 1) || 
         (cnt[i][12] >= 1 && (int)suit[i].size()-cnt[i][12] >= 2))
        stopped++;
    }
    // cout << pp << ' ' << p << endl;
    if(p < 14) cout << "PASS" << endl;
    else if(pp >= 16 && stopped == 4) cout << "BID NO-TRUMP" << endl;
    else {
      int best = -1; char ans;
      for(auto& s : "SHDC") {
        if(best < (int)suit[id[s]].size()) {
          best = (int)suit[id[s]].size();
          ans = s;
        }
      }
      cout << "BID " << ans << endl;
    }
  }

  return 0;
}