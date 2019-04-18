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

vector< vi > test;
vi cur(5);

void dfs( int i, int t ) {
  if( i == 5 ) {
    if( t == 0 ) test.PB( cur );
    return ;
  }
  for( int v = 0; v <= t; ++v ) {
    cur[i] = v;
    dfs(i+1,t-v);
    cur[i] = 0;
  }
}

int main( ) {

  freopen( "A.cc.in", "w", stdout );
  //freopen( ".out", "w", stdout );

  dfs(0,5);
  cout << SIZE(test) << endl;
  for( int i = 0; i < SIZE(test); ++i ) {
    cout << 5 << endl << test[i][0];
    for( int j = 1; j < 5; ++j ) cout << " " << test[i][j];
    cout << endl;
  }

  return 0;
}

