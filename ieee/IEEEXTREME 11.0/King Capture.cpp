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
typedef double              lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e2 )+10;
const int MOD  = int( 360 );
const int oo   = int( 1e7 );

int n, m;
int dist[ MAXN ][ MAXN ];
int ways[ MAXN ][ MAXN ];
int acc[ MAXN ];
bitset<100> bits[ MAXN ][ MAXN ];
vector<int> graph[ MAXN ];

int GetBlack() {
    int black_king_node;
    cin >> black_king_node;
    return black_king_node-1;
}

void SetWhite(int node) {
    cout << node+1 << endl;
}

int dijkstra( int st, int fn ) {
  bool visited[ MAXN ];
  memset( visited, 0, sizeof(visited) );
  int ans = 0, max_dist = oo;
  priority_queue< pii, vector<pii>, greater<pii> > pq;
  pq.push( MP(0,st) );
  while( !pq.empty() ) {
    int dist = pq.top().FI;
    int node = pq.top().SE;
    pq.pop();
    if( max_dist < dist ) break;
    if( node == fn ) {
      if( max_dist == oo )
        max_dist = dist;
      ++ans;
      continue;
    }
    if( visited[node] ) continue;
    visited[ node ] = true;
    for( int i = 0; i < SIZE(graph[node]); ++i ) {
      int u = graph[node][i];
      if( !visited[u] ) {
        pq.push( MP(dist+1, u) );
      }
    }
  }
  return ans;
}

int main( ) {

  #ifdef LOCAL
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  for( int i = 0; i < MAXN; ++i ) {
    for( int j = 0; j < MAXN; ++j ) {
      if( i == j ) continue;
      dist[i][j] = oo;
    }
  }
  cin >> n >> m;
  for( int i = 0; i < m; ++i ) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].PB(v);
    graph[v].PB(u);
    dist[u][v] = dist[v][u] = 1;
    bits[u][0].set(v);
    bits[v][0].set(u);
  }
  
  for( int i = 0; i < n; ++i ) {
    bits[i][0].set(i);
  }
  
  for( int k = 1; k < n; ++k ) {
    for( int i = 0; i < n; ++i ) {
      bits[i][k] = bits[i][k-1];
      for( auto& j : graph[i] ) {
        bits[i][k] |= bits[j][k-1];
      }
    }
  }

  for( int k = 0; k < n; ++k ) {
    for( int i = 0; i < n; ++i ) {
      for( int j = 0; j < n; ++j ) {
        dist[i][j] = min( dist[i][j], dist[i][k]+dist[k][j] );
      }
    }
  }
  
  int white = 0, mn_dist = oo, sum_dist = oo;
  for(int i = 0; i < n; ++i ) {
    int mx = 0, sum = 0;
    for( int j = 0; j < n; ++j ) {
      mx = max( mx, dist[i][j] );
      sum += dist[i][j];
    }
    if( mx < mn_dist ) {
      mn_dist = mx;
      sum_dist = sum;
      white = i;
    } else if( mx == mn_dist && sum < sum_dist ) {
      sum_dist = sum;
      white = i;
    }
  }
  
  SetWhite( white );
  for( int black = GetBlack();  black != white; black = GetBlack() ) {
    if( dist[white][black] == 1 ) {
      white = black;
    } else {
      int c = 0, d = oo, idx = -1;
      for( auto& adj : graph[white] ) {
        int nc = ( bits[adj][ dist[adj][black]-1 ]&bits[black][ dist[adj][black]-1 ] ).count();
        int nd = dist[adj][black]-1;
        if( nd < d ) {
          c = nc;
          d = nd;
          idx = adj;
        } else if( nd == d && nc > c ) {
          c = nc;
          idx = adj;
        }
      }
      white = idx;
    }
    SetWhite( white );
  }
  return 0;
}
