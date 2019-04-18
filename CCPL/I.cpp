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

char cmd[MAXN];

vector<int> get_digits(ll x) {
  vector<int> digits;
  while(x) {
    digits.push_back(x%10);
    x /= 10;
  }
  reverse(digits.begin(), digits.end());
  return digits;
}

string transform(ll x) {
  if(x == 0) return "a";
  vector<int> digits = get_digits(x);
  vector<char> id(10);
  char cur = 'a';
  string ret = "";
  for(auto& e : digits) {
    if(!id[e]) id[e] = cur++;
    ret += id[e];
  }
  return ret;
}

ll get_size(ll x) {
  vector<int> digits = get_digits(x);
  if(digits.size() == 1) return 10;
  sort(digits.begin(), digits.end());
  digits.resize(unique(digits.begin(), digits.end())-digits.begin());
  ll ret = 1;
  for(int i = 1; i <= digits.size(); ++i) {
    ret *= min(11-i, 9);
  }
  return ret;
}

string verify(ll x, ll y) {
  string a = transform(x);
  string b = transform(y);
  return a == b ? "true" : "false";
}

int main() {
  #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
  #else
    // ios::sync_with_stdio(0); cin.tie(0);
    #define endl '\n'
  #endif

  for(int tc = 1; scanf("%s", cmd) == 1; ++tc) {
    if(cmd[0] == 'V') {
      ll x, y; scanf("%lld %lld", &x, &y);
      printf("%d. %s\n", tc, verify(x, y).c_str());
    } else if(cmd[0] == 'S') {
      ll x; scanf("%lld", &x);
      printf("%d. %lld\n", tc, get_size(x));
    } else {
      break;
    }
  }

  return 0;
}