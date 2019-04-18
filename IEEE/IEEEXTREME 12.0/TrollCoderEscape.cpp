#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;

const int MAXN = 1e2 + 10;
const int MOD = 1e9 + 7;
const int oo = 1e9 + 100;
const lf EPS = 1e-9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int ans[MAXN];
vector<int> graph[MAXN];

int query( const vector<int>& v ) {
  printf( "Q" ); for( auto& e : v ) printf( " %d", e ); puts("");
  fflush(stdout);
  int x; scanf( "%d", &x );
  return x;
}

void paint( int u, int p = -1 ) {
  for( auto& v : graph[u] ) {
    if( v == p ) continue;
    ans[v] = 1-ans[u];
    paint(v, u);
  }
}

void solve( const int& base, vector<int> p ) {
  // cout << " Asking for: \n";
  // for( auto& e : p ) cout << e << ' '; cout << endl;
  vector<int> tmp(n);
  if( p.size() <= 1 ) {
    for( int i = 0; i < p.size(); ++i ) {
      tmp[ p[i] ] = 1;
      int t = query(tmp);
      if( t > base ) ans[p[i]] = 1;
      paint(p[i]);
      tmp[ p[i] ] = 0;
    }
    return ;
  }
  shuffle(p.begin(), p.end(), rng);
  vector<int> v;
  for( int i = 0; i+1 < p.size(); i += 2 ) {
    tmp[ p[i] ] = tmp[ p[i+1] ] = 1;
    int t = query(tmp);
    if( abs(t-base) == 2 ) {
      if( t > base ) ans[ p[i] ] = ans[ p[i+1] ] = 1;
      else ans[ p[i] ] = ans[ p[i+1] ] = 0;
      paint(p[i]); paint(p[i+1]);
    } else {
      v.push_back(p[i]);
      graph[p[i]].push_back(p[i+1]);
      graph[p[i+1]].push_back(p[i]);
    }
    tmp[ p[i] ] = tmp[ p[i+1] ] = 0;
  }
  if( p.size()%2 ) v.push_back(p.back());
  solve(base, v);
}

int main() {

  int n_test; scanf( "%d", &n_test );

  while( n_test-- ) {
    scanf( "%d", &n );
    for( int i = 0; i < n; ++i ) { graph[i].clear(); }
    memset( ans, 0, sizeof(ans) );
    vector<int> p(n), tmp(n, 0); iota(p.begin(), p.end(), 0);
    int base = query(tmp);
    solve(base, p);
    printf( "A" ); for( int i = 0; i < n; ++i ) printf( " %d", ans[i] ); puts("");
    fflush(stdout);
  }

  return 0;
}