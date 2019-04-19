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

const int MAXN = int( 5e4 )+10;
const int MAXM = int( 1e4 )+1;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const int LOG2 = 16;

int n;
vi graph[ MAXN ], costs[ MAXN ], idx[ MAXN ];
int arr[ MAXN ], base_array[ MAXN ], ptr;
int n_chain, chain_ind[ MAXN ], chain_head[ MAXN ], pos_base[ MAXN ];
int depth[ MAXN ], dp[ LOG2 ][ MAXN ], other_end[ MAXN ], subsize[ MAXN ];
int st[ MAXN*4 ];

int dp_gcd[ MAXM ][ MAXM ];

void init( ) {
  for( int i = 0; i < n; ++i ) {
    graph[i].clear();
    chain_head[i] = -1;
    for( int j = 0; j < LOG2; ++j ) {
      dp[j][i] = -1;
    }
  }
}

int gcd( int a, int b ) {
  if( a == 0 || b == 0 ) return max( a, b );
  if( dp_gcd[a][b] != 0 ) return dp_gcd[a][b];
  return dp_gcd[a][b] = dp_gcd[b][a] = __gcd(a,b);
}

#define LEFT(x)       ((x<<1)|0)
#define RIGHT(x)      ((x<<1)|1)
void make_tree( int node, int s, int e ) {
  if( s == e ) {
    st[ node ] = base_array[s];
    return ;
  }
  int m = (s+e)>>1;
  make_tree( LEFT(node), s, m );
  make_tree( RIGHT(node), m+1, e );
  st[ node ] = gcd( st[LEFT(node)], st[RIGHT(node)] );
}

void update_tree( int node, int s, int e, int x, int val ) {
  if( s == e ) {
    st[ node ] = val;
    return;
  }
  int m = (s+e)>>1;
  if( x <= m ) {
    update_tree( LEFT(node), s, m, x, val );
  } else {
    update_tree( RIGHT(node), m+1, e, x, val );
  }
  st[ node ] = gcd( st[LEFT(node)], st[RIGHT(node)] );
}

int query_tree( int node, int s, int e, int l, int r ) {
  if( s == l && e == r ) {
    return st[node];
  }
  int m = (s+e)>>1;
  if( r <= m ) {
    return query_tree( LEFT(node), s, m, l, r );
  }
  if( l > m ) {
    return query_tree( RIGHT(node), m+1, e, l, r );
  }
  return gcd( query_tree( LEFT(node), s, m, l, m ), query_tree( RIGHT(node), m+1, e, m+1, r ) );
}

int query_up( int u, int v ) {
  if( u == v ) return arr[u];
  int uchain, vchain = chain_ind[v], ans = 0;
  while( true ) {
    uchain = chain_ind[u];
    if( uchain == vchain ) {
      ans = gcd( ans, query_tree( 1, 0, n-1, pos_base[v], pos_base[u] ) );
      return ans;
    }
    ans = gcd( ans, query_tree( 1, 0, n-1, pos_base[ chain_head[uchain] ], pos_base[u] ) );
    u = chain_head[uchain];
    u = dp[0][u];
  }
  return -1;
}

int LCA( int u, int v ) {
  if( depth[u] > depth[v] ) swap( u, v );
  int diff = depth[v]-depth[u];
  for( int i = 0; i < LOG2; ++i ) {
    if( (diff>>i)&1 ) {
      v = dp[i][v];
    }
  } 
  if( u == v ) return u;
  for( int i = LOG2-1; i >= 0; --i ) {
    if( dp[i][u] != dp[i][v] ) {
      u = dp[i][u];
      v = dp[i][v];
    }
  }
  return dp[0][u];
}

void query( int u, int v ) {
  int lca = LCA( u, v );
  int ans = gcd( query_up( u, lca ), query_up( v, lca ) );
  printf("%d\n", ans);
}

void change( int u, int val ) {
  update_tree( 1, 0, n-1, pos_base[u], val );
}

void HLD( int u, int p = -1 ) {
  if( chain_head[n_chain] == -1 ) {
    chain_head[n_chain] = u;
  }
  chain_ind[u] = n_chain;
  pos_base[u] = ptr;
  base_array[ptr++] = arr[u];
  int child = -1;
  for( int i = 0; i < SIZE(graph[u]); ++i ) {
    int v = graph[u][i];
    if( v == p ) continue;
    if( child == -1 || subsize[child] < subsize[v] ) {
      child = v;
    }
  }
  if( child != -1 ) {
    HLD( child, u );
  }
  for( int i = 0; i < SIZE(graph[u]); ++i ) {
    int v = graph[u][i];
    if( v == p || v == child ) continue;
    n_chain++;
    HLD( v, u );
  }
}

void dfs( int u, int p = -1 ) {
  dp[0][u] = p;
  depth[u] = ( p == -1 ? 0 : depth[p]+1 );
  subsize[u] = 1;
  for( int i = 0; i < SIZE(graph[u]); ++i ) {
    int v = graph[u][i];
    if( v == p ) continue;
    dfs( v, u );
    subsize[u] += subsize[v];
  }
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif
  
  while( scanf( "%d", &n ) == 1 ) {
    init( );
    for( int i = 0; i < n; ++i ) {
      scanf( "%d", &arr[i] );
    }
    for( int i = 1; i < n; ++i ) {
      int u, v; scanf( "%d%d", &u, &v );
      graph[u].PB(v);
      graph[v].PB(u);
    }

    n_chain = ptr = 0;
    dfs( 0 );
    HLD( 0 );
    make_tree( 1, 0, n-1 );

    for( int i = 1; i < LOG2; ++i ) {
      for( int j = 0; j < n; ++j ) {
        if( dp[ i-1 ][ j ] != -1 ) {
          dp[ i ][ j ] = dp[ i-1 ][ dp[i-1][j] ];
        }
      }
    }

    int q; scanf( "%d", &q );
    while( q-- ) {
      int tp, a, b; scanf( "%d%d%d", &tp, &a, &b );
      if( tp == 1 ) {
        query( a, b );
      } else {
        change( a, b );
      }
    }
  }

  return 0;
}
