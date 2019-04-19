#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 2e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
vi graph[ MAXN ];
int match[ MAXN ];
bool seen[ MAXN ];

bool dfs( int u ) {
  for( auto& v : graph[u] ) {
    if( seen[v] ) continue;
    seen[v] = true;
    if( match[v] == -1 || dfs( match[v] ) ) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

int mbm() {
  memset( match, -1, sizeof(match) );
  int r = 0;
  for( int i = 0; i < n; ++i ) {
    memset( seen, false, sizeof(seen) );
    r += dfs(i);
  }
  return r;
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  cin >> n; cin.ignore();
 
  for( int i = 0; i < n; ++i ) {
    string line; getline( cin, line );
    stringstream in(line);
    vb ok( n, true );
    for( int x; in >> x; ) {
     ok[ x ] = false;
    }
    ok[i] = false;
    for( int j = 0; j < n; ++j ) {
      if( ok[j] ) {
        graph[i].PB(j);
      }
    }
  }

  cout << n-mbm() << '\n';

  return 0;
}
