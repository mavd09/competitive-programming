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

const int MAXN = int( 1e4 )+10;
const int MOD  = int( 360 );
const ll oo   = ll(1e18)+10;

int n,m, st, fn;
map<ll,int> mp;
ll gold[ MAXN ];
vector<pii> graph[ MAXN ];
bool visited[ MAXN ];

bitset<210> bs;
ll _sieve_size;
vector<int> primes;
void sieve( ll upperbound ) {
  _sieve_size = upperbound+1;
  bs.set( );
  bs[ 0 ] = bs[ 1 ] = 0;
  for( ll i = 2; i <= _sieve_size; i++ )
    if( bs[ i ] ) {
      for( ll j = i*i; j <= _sieve_size; j += i ) bs[ j ] = 0;
        primes.PB( (int)i );
    }
}

int get_id( ll x ) {
  if( !mp.count(x) ) {
    mp[x] = SIZE(mp)-1;
  }
  return mp[x];
}

int dijkstra() {
  priority_queue<pair<ll,pii>, vector<pair<ll,pii>>, greater<pair<ll,pii>> > pq;
  pq.push( MP( 0, make_pair(st, gold[st]) ) );
  int ans = 0;
  ll end_dist = oo;
  while( !pq.empty() ) {
    ll dist = pq.top().FI;
    int node = pq.top().SE.FI;
    int gain = pq.top().SE.SE;
    pq.pop();
    //cout << node << endl;
    if( node == fn ) {
      end_dist = min( end_dist, dist );
      ans = max( ans, gain );
      continue;
    }
    if( end_dist < dist ) break;
    visited[ node ] = true;
    for( int i = 0; i < SIZE(graph[node]); ++i ) {
      int v = graph[node][i].FI;
      ll c = ll(graph[node][i].SE);
      if( visited[v] ) continue;
      pq.push( MP(dist+c, MP(v, gain+gold[v])) );
    }
  }
  return ans;
}

int get_gold( ll x ) {
  if( x == 1LL ) return 0;
  ll cur = 2LL;
  int r = 1;
  for( int i = 1; cur*ll(primes[i]) <= x && cur*ll(primes[i]) > 0; cur *= ll(primes[i++]) ) {
    ++r;
  }
  return r;
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
  #endif

  cin >> n >> m;
  ll mn = oo, mx = -1;
  sieve(200);
  for( int i = 0; i < n; ++i ) {
    ll x; cin >> x;
    gold[ get_id(x) ] = get_gold(x);
    //cout << "-->" << gold[ get_id(x) ] << endl;
    if( x < mn ) {
      mn = x;
      st = get_id(x);
    }
    if( x > mx ) {
      mx = x;
      fn = get_id(x);
    }
  }
  for( int i = 0; i < m; ++i ) {
    ll u, v, c; cin >> u >> v >> c;
    u = get_id(u);
    v = get_id(v);
    graph[u].push_back( MP(v,c) );
    graph[v].push_back( MP(u,c) );
  }
  cout << dijkstra() << '\n';
  return 0;
}
