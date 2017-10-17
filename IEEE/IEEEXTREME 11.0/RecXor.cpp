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

const int MAXN = int( 1e5 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;

ll t,row,col,n,d1,d2;
ll ans, c1,c2, lft, rght;

ll start( ll x ) {
  if( x%4LL == 0 ) return 0;
  ll r = x; ++x;
  while( x%4LL ) {
    r ^= x;
    ++x;
  }
  return r;
}

ll finish( ll x ) {
  if( x%4LL == 3LL ) return 0;
  ll r = x; --x;
  while( x%4LL != 3LL ) {
    r ^= x;
    --x;
  }
  //r ^= x;
  return r;
}

ll go( ll x, ll y ) {
  ll r = 0LL;
  if( y-x <= 8LL ) {
    for( ; x <= y; ++x ) {
      r ^= x;
    }
  }
  else {
    r = start(x) ^ finish(y);
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

  cin >> t;
  while( t-- ) {
    cin >> col >> row >> n >> d1 >> d2;
    ans = go( n, row*col+n-1LL );
    c1 = (d1-n)%col;
    c2 = (d2-n)%col;
    if( c1 <= c2 ) {
      lft = d1;
      rght = d1+(c2-c1);
    }
    else {
      lft = d1-(c1-c2);
      rght = d1;
      d2 += (c1-c2);
    }
    for( ; rght <= d2; lft += col, rght += col ) {
      //cout << "---> " << lft << " " << rght << endl;
      ans ^= go( lft, rght );
    }
    cout << ans << '\n';
  }

  return 0;
}
