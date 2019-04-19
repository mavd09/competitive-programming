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

const int MAXN = int( 5e5 )+10;
const int MOD  = int( 360 );
const ll  oo   = LLONG_MAX;

int n;
ll a[ MAXN ];

ll val[ 3 ][ 4*MAXN ];

void update_node( int node ) {
  int l = 2*node, r = l+1;
  val[ 0 ][ node ] = val[ 0 ][ l ]+val[ 0 ][ r ];
  val[ 1 ][ node ] = min( val[ 1 ][ l ], val[ 1 ][ r ] );
  val[ 2 ][ node ] = min( val[ 2 ][ l ], val[ 2 ][ r ] );
}

void build( int node, int ll, int rr ) {
  if( ll == rr ) {
    val[ 0 ][ node ] = a[ ll ];
    val[ 1 ][ node ] = a[ ll ]+( n-ll-1 );
    val[ 2 ][ node ] = a[ ll ]+( ll );
    return ;
  }
  int mm = (ll+rr)/2;
  build( 2*node, ll, mm );
  build( 2*node+1, mm+1, rr );
  update_node( node );
}

void modify( int node, int ll, int rr, int pos ) {
  if( ll == rr ) {
    val[ 0 ][ node ] = a[ ll ];
    val[ 1 ][ node ] = a[ ll ]+( n-ll-1 );
    val[ 2 ][ node ] = a[ ll ]+( ll );
    return ;
  }
  int mm = (ll+rr)/2;
  if( pos <= mm ) {
    modify( 2*node, ll, mm, pos );
  } else {
    modify( 2*node+1, mm+1, rr, pos );
  }
  update_node( node );
}

ll query( int node, int ll, int rr, int l, int r, int t ) {
  if( r < ll || l > rr ) {
    return ( t == 0 ? 0 : oo );
  }
  if( l <= ll && rr <= r ) {
    return val[ t ][ node ];
  }
  int mm = (ll+rr)/2;
  if( t == 0 ) {
    return query( 2*node, ll, mm, l, r, t )+query( 2*node+1, mm+1, rr, l, r, t );
  }
  return min( query( 2*node, ll, mm, l, r, t ), query( 2*node+1, mm+1, rr, l, r, t ) );
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
    for( int i = 0; i < n; i++ ) {
      cin >> a[ i ];
    }
    build( 1, 0, n-1 );
    int q; cin >> q;
    for( int i = 0; i < q; i++ ) {
      int t, c, v; cin >> t >> c >> v; c--;
      if( t == 1 ) {
        a[ c ] = v;
        modify( 1, 0, n-1, c );
      } else {
        if( v == 1 ) {
          ll h = min( a[ c ], min( c+1, n-c )*1LL );
          if( c ) {
            h = min( h, query( 1, 0, n-1, 0, c-1, 1 )-( n-c-1 ) );
          }
          if( c+1 != n ) {
            h = min( h, query( 1, 0, n-1, c+1, n-1, 2 )-c ); 
          }
          ll sum = query( 1, 0, n-1, c-h+1, c+h-1, 0 ) - h - h*(h-1);
          cout << h << " " << sum << "\n";
        } else {
          ll h = a[ c ];
          if( c ) {
            h = min( h, query( 1, 0, n-1, 0, c-1, 1 )-( n-c-1 ) );
          }
          if( c+1 != n ) {
            h = min( h, query( 1, 0, n-1, c+1, n-1, 2 )-c ); 
          }
          ll sum = query( 1, 0, n-1, max( 0, int(c-h+1) ), min( n-1, int(c+h-1) ), 0 ) - h - h*(h-1);
          if( c-h+1 < 0 ) {
            ll x = -( c-h+1 );
            sum += x*(x+1)/2LL;
          }
          if( c+h-1 >= n ) {
            ll x = c+h-1 - (n-1);
            sum += x*(x+1)/2LL;
          }
          cout << h << " " << sum << "\n";
        }
      }
    }
  }

  return 0;
}