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

const int MAXN = int( 1e4 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

vi graph[ MAXN ];

string rid[ MAXN ];
map< string, int > id;

int get_id( string s ) {
 if( !id.count(s) ) {
  id[s] = SIZE(id)-1;
  rid[ SIZE(id)-1 ] = s;
 }
 return id[s]; 
}

int d[ MAXN ];
void bfs( int u ) {
  queue< int > q;
  q.push( u );
  d[u] = 0;
  while( !q.empty() ) {
    u = q.front(); q.pop();
    for( auto& v : graph[u] ){
      if( d[v] == -1 ) {
        d[v] = d[u]+1;
        q.push(v);
      }
    }
  }
}

int main( ) {

#ifdef LOCAL
  freopen( "associations.txt", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  get_id( "airplane" );
  get_id( "basket" );
  get_id( "plastic" );
  get_id( "spirit" );
  get_id( "meltdown" );
  get_id( "festival" );
  get_id( "quarter" );
  get_id( "pink" );
  get_id( "earth" );

  cout << SIZE(id) << '\n';

  get_id( "pilot" );
  get_id( "zoo" );
  get_id( "battery" );
  get_id( "mortgage" );
  get_id( "water" );
  get_id( "egg" );
  get_id( "vacation" );
  get_id( "officer" );
  get_id( "judge" );
  get_id( "fate" );
  get_id( "truck" );
  get_id( "cross" );
  get_id( "kilometer" );
  get_id( "radio" );
  get_id( "cargo" );
  get_id( "diamond" );

  cout << SIZE(id) <<'\n';

  string line, word;
  while( getline( cin, line ) ) {
    for( auto& e : line ) {
      if( e == ':' || e == ',' ) {
        e = ' ';
      }
    }
    stringstream in(line);
    in >> word;
    int u = get_id( word );
    while( in >> word ) {
      int v = get_id(word);
      graph[ u ].PB( v );
    }
  }
  
  vector< string > ans;
  int t = oo;
  for( int i = 9; i < SIZE(id); ++i ) {
    memset( d, -1, sizeof(d) );
    bfs( i );
    bool ok = true;
    int mx = 0;
    for( int j = 0; j < 9; ++j ) {
      if( d[j] == -1 ) {
        ok = false;
      }
      mx = max( mx, d[j] );
    }
    int mn = oo;
    for( int j = 9; j < 25; ++j ) {
      if( d[j] == -1 ) {
        ok = false;
      }
      mn = min( mn, d[j] );
    }
    if( ok && mx < mn && mx < t ) {
      t = mx;
      ans.clear();
    }
    if( ok && mx == t ) {
      ans.PB( rid[i] );
    }
  }
  cout << SIZE(ans) << '\n';
  for( auto& e : ans )
    cout << e << '\n';

  return 0;
}

