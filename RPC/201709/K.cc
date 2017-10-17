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
const int oo   = INT_MAX;

int n;
int arr[ MAXN ];
int cnt[ MAXN ];

typedef pair< int, int > mint;
const int MOD[ ] = { 1001864327, 1001265673 };
const mint BASE( 135791, 135791 ), ZERO( 0, 0 ), ONE( 1, 1 );
inline int add( int a, int b, const int& mod ) { return ( a+b >= mod ) ? a+b-mod : a+b; }
inline int sbt( int a, int b, const int& mod ) { return ( a-b < 0 ? a-b+mod : a-b ); }
inline int mul( int a, int b, const int& mod ) { return ll(a)*ll(b) % ll(mod); }

inline ll operator ! ( const mint a ) { return (ll(a.FI)<<32)|ll(a.SE); }
inline mint operator + ( const mint a, const mint b ) {
  return mint( add( a.FI, b.FI, MOD[0] ), add( a.SE, b.SE, MOD[1] ) );
}
inline mint operator - ( const mint a, const mint b ) {
  return mint( sbt( a.FI, b.FI, MOD[0] ), sbt( a.SE, b.SE, MOD[1] ) );
}
inline mint operator * ( const mint a, const mint b ) {
  return mint( mul( a.FI, b.FI, MOD[0] ), mul( a.SE, b.SE, MOD[1] ) );
}


mint base[ MAXN ];

#define L(x)        ((x<<1)|0)
#define R(x)        ((x<<1)|1)

pair< mint, mint > st[ 4*MAXN ];

void pull( int node, int l, int m, int r ) {
  st[ node ].FI = st[ L(node) ].FI*base[r-m] + st[ R(node) ].FI;
  st[ node ].SE = st[ R(node) ].SE*base[m-l+1] + st[ L(node) ].SE;
}

void build( int node, int l, int r ) {
  if( l == r ) {
    st[ node ].FI = st[ node ].SE = mint( arr[ l ], arr[ l ] );
    //cout << "Node " << l << " = " << arr[l] << '\n';
    return ;
  }
  int m = (l+r)>>1;
  build( L(node), l, m );
  build( R(node), m+1, r );
  pull( node, l, m, r );
  //cout << '[' << l << ',' << r << ']' << " = " << st[node].FI.FI << ' ' << st[node].FI.SE << '\n';
}

void update( int node, int l, int r, int p ) {
  if( l == r ) {
    st[ node ].FI = st[ node ].SE = mint( arr[ l ], arr[ l ] );
    return ;
  }
  int m = (l+r)>>1;
  if( p <= m ) update( L(node), l, m, p );
  else update( R(node), m+1, r, p );
  pull( node, l, m, r );
}

pair< mint, mint > query( int node, int l, int r, int ll, int rr ) {
  int m = (l+r)>>1;
  pair< mint, mint > a, b;
  if( l == ll && r == rr ) a = st[node];
  else if( rr <= m ) a = query( L(node), l, m, ll, rr );
  else if( ll > m ) a = query( R(node), m+1, r, ll, rr );
  else {
    a = query( L(node), l, m, ll, m );
    b = query( R(node), m+1, r, m+1, rr );
    a.FI = a.FI*base[rr-m] + b.FI;
    a.SE = b.SE*base[m-ll+1] + a.SE;
  }
  //cout << "[" << l << "," << r << "] = " << a.FI.FI << " " << a.FI.SE << '\n';
  return a;
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

  base[ 0 ] = ONE;
  for( int i = 1; i < MAXN; ++i ) {
    base[ i ] = base[ i-1 ]*BASE;
  }

  vi ulam;
  ulam.PB( 1 );
  cnt[1] = cnt[2] = 1;
  for( int i = 2; SIZE(ulam) < int(1e4); ++i ) {
    if( cnt[i] == 1 ) {
      for( auto& e : ulam )
        cnt[ i+e ]++;
      ulam.PB( i );
    }
  }

  while( cin >> n ) {
    for( int i = 1; i <= n; ++i ) {
      cin >> arr[i];
    }
    build( 1, 1, n );
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      char cmd; cin >> cmd;
      if( cmd == 'U' ) {
        int pos, val; cin >> pos >> val;
        arr[ pos ] = val;
        update( 1, 1, n, pos );
      } else {
        int l, r; cin >> l >> r;
        if( cnt[ arr[l] ] != 1 ) {
          puts( "N" );
          continue;
        }
        pair< mint, mint > ans = query( 1, 1, n, l, r );
        //cout << ans.FI.FI << ' ' << ans.SE.FI << '\n';
        if( ans.FI == ans.SE ) puts( "Y" );
        else puts( "N" );
      }
    }
  }

  return 0;
}

