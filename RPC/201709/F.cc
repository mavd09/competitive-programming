#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second
#define SIZE( A )   int( ( A ).size( ) )
#define ALL( A )    ( A ).begin( ), ( A ).end( )
#define ALLR( A )   ( A ).rbegin( ), ( A ).rend( )

using namespace std;
using namespace __gnu_pbds;

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
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const int MAXM = 32*MAXN;

typedef tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;

struct Query { int l, k, id; };

int n;
int a[ MAXN ];
/*
vector< Query > query[ MAXN ];
int ans[ MAXN ];
*/

int next_node;
int root[ MAXN ];
int V[ MAXM ], L[ MAXM ], R[ MAXM ];

int update( int node, int l, int r, int x, int v ) {
  int new_node = next_node++;
  L[ new_node ] = L[ node ]; R[ new_node ] = R[ node ];
  if( l == r ) {
    V[ new_node ] = v;
    return new_node;
  }
  int m = (l+r)>>1;
  if( x <= m ) {
    L[ new_node ] = update( L[node], l, m, x, v );
  } else {
    R[ new_node ] = update( R[node], m+1, r, x, v );
  }
  V[ new_node ] = V[ L[new_node] ]+V[ R[new_node] ];
  return new_node;
}

int query( int node, int l, int r, int ll, int rr ) {
  if( l == ll && r == rr ) {
    return V[node];
  }
  int m = (l+r)>>1;
  if( rr <= m ) return query( L[node], l, m, ll, rr );
  if( ll > m ) return query( R[node], m+1, r, ll, rr );
  return query( L[node], l, m, ll, m )+
         query( R[node], m+1, r, m+1, rr );
}  

int query( int node, int l, int r, int k ) {
  if( V[node] < k ) return -1;
  if( l == r ) return l;
  int m = (l+r)>>1;
  if( k <= V[ L[node] ] ) return query( L[node], l, m, k );
  return query( R[node], m+1, r, k-V[ L[node] ] );
}


int main( ) {

#ifdef LOCAL
  freopen( "input", "r", stdin );
  //freopen( "output", "w", stdout );
#else
  //freopen( ".in", "r", stdin );
  //freopen( ".out", "w", stdout );
#endif

  while( scanf( "%d", &n ) == 1 ) {

    next_node = 1;
    unordered_map< int, int > lst; 
    root[ 0 ] = L[ 0 ] = R[ 0 ] = 0;
    for( int i = 1; i <= n; ++i ) {
      scanf( "%d", &a[i] );
      if( !lst.count( a[i] ) ) {
       root[ i ] = update( root[i-1], 1, n, i, 1 );
      } else {
       root[ i ] = update( root[i-1], 1, n, i, 1 );
       root[ i ] = update( root[i], 1, n, lst[ a[i] ], 0 );
      }
      lst[ a[i] ] = i;
    }
    int q; scanf( "%d", &q );
    for( int i = 0; i < q; ++i ) {
      int l, r, k; scanf( "%d%d%d", &l, &r, &k );
      int x = 0;
      if( 1 < l ) x = query( root[r], 1, n, 1, l-1 );
      int pos = query( root[r], 1, n, x+k );
      if( pos != -1 ) printf( "%d\n", a[pos] );
      else puts( ":(" );
    }
/*
    for( int i = 0; i < n; ++i ) {
      scanf( "%d", &a[i] );
      query[i].clear();
    }
    int q; scanf( "%d", &q );
    for( int i = 0; i < q; ++i ) {
      int l, r, k; scanf( "%d%d%d", &l, &r, &k );
      query[r-1].PB( {l-1, k-1, i} );
    }
    unordered_map< int, int > lst;
    ordered_set s;
    for( int i = 0; i < n; ++i ) {
      if( lst.count( a[i] ) ) {
        s.erase( lst[ a[i] ] );
      }
      lst[ a[i] ] = i;
      s.insert( i );
      for( auto& e : query[i] ) {
        e.k += s.order_of_key(e.l);
        if( e.k >= SIZE(s) ) {
          ans[ e.id ] = -1;
        } else {
          ans[ e.id ] = a[ *s.find_by_order(e.k) ];
        }
      }
    }
    for( int i = 0; i < q; ++i ) {
      if( ans[i] == -1 ) puts( ":(" );
      else printf( "%d\n", ans[i] );
    }
*/
  }

  return 0;
}

