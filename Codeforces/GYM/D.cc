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

const int MAXN = int( 2e5 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

int n;
int arr[ MAXN ], m_arr[ MAXN ], zip[ MAXN ];
int lst[ MAXN ];

int free_node;
int root[ MAXN ];
int V[ 80*MAXN ], L[ 80*MAXN ], R[ 80*MAXN ];
vi pos[ MAXN ];

int update( int node, int l, int r, int v ) {
  int nnode = free_node++;
  V[ nnode ] = V[ node ];
  L[ nnode ] = L[ node ]; R[ nnode ] = R[ node ];
  if( l == r ) {
    V[ nnode ]++;
    return nnode;
  }
  int m = (l+r)>>1;
  if( v <= m ) {
    L[ nnode ] = update( L[node], l, m, v );
  } else {
    R[ nnode ] = update( R[node], m+1, r, v );
  }
  V[ nnode ] = V[ L[nnode] ]+V[ R[nnode] ];
  return nnode;
}

int query( int r1, int r2, int l, int r, int ll, int rr ) {
  if( rr < l || ll > r ) return 0;
  if( ll <= l && r <= rr ) {
    return V[r2] - V[r1];
  }
  int m = (l+r)>>1;
  return query( L[r1], L[r2], l, m, ll, rr ) + query( R[r1], R[r2], m+1, r, ll, rr );
}

int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  freopen( "data.in", "r", stdin );
  freopen( "data.out", "w", stdout );
  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );
#endif

  while( cin >> n ) {
    for( int i = 1; i <= n; ++i ) {
      cin >> arr[i];
      pos[i].clear();
      lst[ i-1 ] = -1;
    }
    memcpy( zip, arr+1, sizeof(int)*n );
    sort( zip, zip+n );
    int nzip = unique( zip, zip+n )-zip;
    for( int i = 1; i <= n; ++i ) {
      arr[i] = lower_bound( zip, zip+nzip, arr[i] )-zip;
      pos[ arr[i] ].PB( i );
    }
    for( int i = n; i > 0; --i ) {
      m_arr[ i ] = ( lst[ arr[i] ] == -1 ? n+1 : lst[ arr[i] ] );
      lst[ arr[i] ] = i;
    }
    free_node = 1;
    root[0] = L[0] = R[0] = 0;
    for( int i = 1; i <= n; ++i ) {
      root[i] = update( root[i-1], 1, n+1, m_arr[i] );
    }
    int q; cin >> q;
    for( int i = 0; i < q; ++i ) {
      int x, p; cin >> x >> p;
      int id = lower_bound( ALL( pos[ arr[p+x-1] ] ), x )-pos[ arr[p+x-1] ].begin();
      p = pos[ arr[p+x-1] ][ id ];
      cout << query( root[x-1], root[p-1], 1, n+1, p, n+1 )+1 << '\n';
    }
  }

  return 0;
}

