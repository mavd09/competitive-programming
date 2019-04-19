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

const int MAXN = int( 2e2 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

int n;
string player[ MAXN ];
int best;
vpii ans;

void update( pii team, int points ) {
  if( points > best ) {
    best = points;
    ans.clear( );  
  } 
  if( points == best ) {
    if( team.SE < team.FI ) {
      swap( team.SE, team.FI );
    }
    team.FI *= -1; 
    ans.PB( team );
  }
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

  while( cin >> n ) {
    best = 0;
    ans.clear( );
    queue< int > q;
    for( int i = 0; i < n; ++i ) {
      cin >> player[ i ];
      q.push( i );
    }
    string game; cin >> game;
    pii b, w;
    w.FI = -q.front( ); q.pop( );
    b.FI = -q.front( ); q.pop( );
    w.SE = q.front( ); q.pop( );
    b.SE = q.front( ); q.pop( );
    int bb = 0, ww = 0;
    for( auto& e : game ) {
      if( e == 'W' ) {
        ww++;
        swap( w.FI, w.SE );
        update( b, bb );
        q.push( abs( b.SE ) );
        b.SE = -abs( b.FI );
        b.FI = q.front( ); q.pop( );
        bb = 0;
      } else {
        bb++;
        swap( b.FI, b.SE );
        update( w, ww );
        q.push( abs( w.SE ) );
        w.SE = -abs( w.FI );
        w.FI = q.front( ); q.pop( );
        ww = 0;
      }
    }
    update( b, bb );
    update( w, ww );
    for( auto& e : ans ) {
      cout << player[ e.FI ] << ' ' << player[ e.SE ] << '\n'; 
    }
  }

  return 0;
}