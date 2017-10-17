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

const int MAXN = int( 1e3 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
string name[ MAXN ];
int p[ MAXN ], w[ MAXN ];

bool cmp( int a, int b ) {
  if( w[a] != w[b] ) return w[a] < w[b];
  return name[a] < name[b];
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

  cin >> n;

  for( int i = 0; i < n; ++i ) {
    cin >> name[i] >> w[i];
    p[i] = i;
  }

  sort( p, p+n, cmp );

  for( int i = 0; i < n; ) {
    int j = i;
    while( j < n && w[ p[j] ] == w[ p[i] ] ) {
      cout << name[ p[j] ] << ' ';
      j++;
    }
    cout << i+1 << ' ' << j << '\n';
    i = j;
  }

  return 0;
}

