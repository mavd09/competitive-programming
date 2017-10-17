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

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int f( int x ) {
 int r = 0;
 while( x ) {
  r++;
  x /= 10;
 }
 return r;
}

int g( int x ) {
 int r = 0;
 while( x ) {
   r = r*10 + (x%10);
   x /= 10;
 }
 return r;
}

set< int > s;
void dfs( int x, int d ) {
  if( d == 16 ) {
    if( f(x) == 4 ) {
      s.insert(x);
    }
    return ;
  }
  dfs( x*3, d+1 );
  dfs( x+5, d+1 );
  dfs( g(x), d+1 );
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


  dfs( 100, 0 );

  for( int i = 1000; i < 10000; ++i ) {
    if( !s.count(i) ) {
      cout << i << endl;
    }
  }

  return 0;
}

