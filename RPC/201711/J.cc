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

const int MAXN = int( 1e2 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n, m;
bool can[ MAXN ][ MAXN ];

string name[ MAXN ][ MAXN ];
int v[ MAXN ][ MAXN ];

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

int mbm( ) {
  int r = 0;
  memset( match, -1, sizeof(match) );
  for( int i = 0; i < m; ++i ) {
    memset( seen, false, sizeof(seen) );
    r += dfs( v[0][i] );
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

  while( cin >> n >> m ) {
    memset( can, true, sizeof(can) );
    vector< string > zip;
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        cin >> name[i][j];
        zip.PB( name[i][j] );
      }
    }
    sort( ALL(zip) );
    zip.resize( unique( ALL(zip) )-zip.begin() );
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < m; ++j ) {
        v[i][j] = lower_bound( ALL(zip), name[i][j] )-zip.begin();
        for( int k = 0; k < j; ++k ) {
          can[ v[i][k] ][ v[i][j] ] = can[ v[i][j] ][ v[i][k] ] = false;
        }
        can[ v[i][j] ][ v[i][j] ] = false;
      }
    }
    vi p;
    for( int i = 0; i < SIZE(zip); ++i ) {
      bool ok = true;
      for( int j = 0; j < m; ++j ) {
        ok &= v[0][j] != i;
      }
      if( ok ) {
        p.PB( i );
      }
    }
    bool ok = SIZE(zip) <= 2*m;
    if( ok ) {
      for( int i = 0; i < 2*m; ++i ) graph[i].clear();
      for( int i = 0; i < m; ++i ) {
        for( int j = 0; j < SIZE(p); ++j ) {
          if( can[ v[0][i] ][ p[j] ] ) {
            graph[ v[0][i] ].PB( p[j] );
          }
        }
      }
      ok &= mbm() == SIZE(p);
    }
    cout << (ok?'S':'N')  << '\n';
  }

  return 0;
}

