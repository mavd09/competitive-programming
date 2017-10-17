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
int matrix[ MAXN ][ MAXN ];

int add( int x, int y ) {
  return (x+y >= n ? x+y-n : x+y );
}

bool gen( int x ) {
  return __gcd(x,n) == 1;
}

bool first( ) {
  set<int> s;
  for( int i = 0; i < n; ++i ) {
    s.insert( matrix[i][i] );
  }
  return SIZE(s) == n;
}

bool second() {
  set<int> s;
  for( int i = 0; i < n; ++i ) {
    s.insert( matrix[n-i-1][i] );
  }
  return SIZE(s) == n;
}

void print() {
  cout << "Yes\n";
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < n; ++j ) {
      cout << matrix[i][j] << ' ';
    }
    cout << '\n';
  }
}

bool fill( int x ) {
  if( !gen(x) ) return false;
  //cout << x << endl;
  int cur = 0;
  for( int i = 0; i < n; ++i ) {
    for( int j = 0; j < n; ++j ) {
      matrix[i][ add(cur,j) ] = j+1;
    }
    cur = add(cur,x);
  }
  return first() && second();
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  freopen( "avangard.in", "r", stdin );
  freopen( "avangard.out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  while( cin >> n ) {
    if( n == 1 ) {
      cout << "Yes\n1\n";
      continue;
    }
    bool flag = false;
    for( int i = 2; i+1 < n; ++i ) {
      if( fill(i) ) {
        print();
        flag = true;
        break;
      }
    }
    if( !flag ) {
      cout << "No\n";
    }
  }

  return 0;
}

