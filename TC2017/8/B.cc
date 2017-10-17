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
const int MOD  = int( 360 );
const int oo   = INT_MAX;

struct node { 
  ll k, p;
  ll sum;
  node *l, *r;
  node( ) { }
  node( ll k ) : k( k ), p( rand( ) ), sum( k ), l( nullptr ), r( nullptr ) { }
};

typedef node* pnode;

ll get_sum( pnode root ) {
  if( root != nullptr ) {
    return root->sum;
  }
  return 0;
}

void update_sum( pnode root ) {
  if( root != nullptr) {
    root->sum = get_sum( root->l )+get_sum( root->r )+root->k;
  }
}

void split( pnode root, int k, pnode &l, pnode &r ) {
  if( root == nullptr ) {
    l = r = nullptr;
  } else if( root->k <= k ) {
    split( root->r, k, root->r, r );
    l = root;
  } else {
    split( root->l, k, l, root->l );
    r = root;
  }
  update_sum( root );
}

void merge( pnode &root, pnode l, pnode r ) {
  if( l == nullptr || r == nullptr ) {
    root = ( l == nullptr ? r : l );
  } else if( l->p > r->p ) {
    merge( l->r, l->r, r );
    root = l;
  } else {
    merge( r->l, l, r->l );
    root = r;
  }
  update_sum( root );
}

void insert( pnode &root, pnode n ) {
  if( root == nullptr ) {
    root = n;
  } else if( root->p < n->p ) {
    split( root, n->k, n->l, n->r );
    root = n;
  } else if( root->k < n->k ) {
    insert( root->r, n );
  } else {
    insert( root->l, n );
  }
  update_sum( root );
}

void erase( pnode &root, int k ) {
  if( root == nullptr ) {
    return ;
  } else if( root->k == k ) {
    merge( root, root->l, root->r );
  } else if( root->k < k ) {
    erase( root->r, k );
  } else {
    erase( root->l, k );
  }
  update_sum( root );
}

ll search( pnode root, ll x ) {
  if( root == nullptr ) {
    return -1;
  }
  if( root->l == nullptr && root->k >= x ) {
    return root->k;
  }
  if( root->k < x ) {
    return search( root->r, x );
  }
  return search( root->l, x );
}

int query( pnode root ) {
  int ans = 0;
  ll x = 0;
  while( ( x = search( root, x ) ) != -1 ) {
    pnode l, r;
    split( root, x, l, r );
    if( get_sum( l ) <= x ) {
      ++ans;
      x = get_sum( l )+x;
    } else {
      x = get_sum( l );
    }
    merge( root, l, r );
  }
  return ans;
} 

void output( pnode root ) {
  if( root == nullptr )
    return;
  output( root->l );
  cout << root->k << ' ';
  output( root->r );
}

int n, m;
ll arr[ MAXN ];

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

  srand( time( NULL ) );

  while( cin >> n ) {
    pnode root = nullptr;
    for( int i = 0; i < n; ++i ) {
      cin >> arr[ i ];
      pnode new_node = new node( arr[ i ] );
      insert( root, new_node );
    }
    output( root );
    cout << '\n';
    cout << query( root ) << '\n';
    break;
    cin >> m;
    for( int i = 0; i < m; ++i ) {
      int idx; ll v; cin >> idx >> v; --idx;
      erase( root, arr[ idx ] );
      arr[ idx ] = v;
      pnode new_node = new node( arr[ idx ] );
      insert( root, new_node );
      cout << query( root ) << '\n';
    }
  }

  return 0;
}