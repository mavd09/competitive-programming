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

const int MAXN = 15;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int pascal[MAXN][MAXN];

bool get_pol( const vpii& v, vi& pol, int mask ) {
  for( int i = 0; i <= n; ++i ) pol[i] = 0;
  int mx = 0;
  for( int i = 0; i < SIZE(v); ++i ) {
    if( (mask>>i)&1 ) {
      int x = v[i].FI, y = v[i].SE;
      mx = max( mx, x+y );
      for( int j = 0, sgn = 1; j <= y; ++j, sgn *= -1 ) {
        pol[j+x] += sgn*pascal[y][j];
      }
    }
  }
  return mx == n;
}

int f( const vector< vpii >& v ) {
  int t = SIZE(v[1]);
  map< vi, int > ok;
  map< vi, int > nok;
  vi p( n+1 );
  for( int mask = 0; mask < (1<<t); ++mask ) {
    if( get_pol( v[1], p, mask ) )
      ok[ p ]++;
    else
      nok[ p ]++;
  }
  t = SIZE(v[0]);
  int ans = 0;
  for( int mask = 0; mask < (1<<t); ++mask ) {
    bool can = get_pol( v[0], p, mask );
    for( int i = 1; i < t; ++i ) {
      p[i] = -p[i];
    }
    p[0] = 1-p[0];
    if( can && nok.count(p) ) {
      ans += nok[p];
    }
    if( ok.count(p) ) {
      ans += ok[p];
    }
  }
  return ans;
}

bool check( const vi& p ) {
  for( int i = 1; i <= n; ++i ) {
    if( p[i] != 0 ){
      return false;
    }
  }
  return p[0] == 1;
}

void go( const vpii& v ) {
  int t = SIZE(v);
  vi p( n+1 );
  int ans = 0;
  for( int mask = 0; mask < (1<<t); ++mask ) {
    if( get_pol( v, p, mask) && check(p) ) {
      for( int j = 0; j < t; ++j ) {
        if( (mask>>j)&1 ) {
          cout << "x^" << v[j].FI << "y^" << v[j].SE << ' ';
        }
      }
      cout << endl;
    }
  }
  cout << ans << '\n';
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

  pascal[0][0] = 1;
  for( int i = 1; i < MAXN; ++i ) {
    pascal[i][0] = 1;
    for( int j = 1; j <= i; ++j ) {
      pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
    }
  }

  for( n = 4; n < 5; ++n ) {
    vector< vpii > v( 2 );
    for( int i = 0, id = 0; i <= n; ++i ) {
      for( int j = 0; i+j <= n; ++j, id = 1-id ) {
        v[ 0 ].PB( {i, j} );
      }
    }
    cout << SIZE(v[0]) << ' ' << SIZE(v[1]) << endl;
    go( v[0] );
    break;
    int ans = f(v);
    cout << ans << '\n';
  }

  return 0;
}
