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

struct Tree { 
  int v;
  Tree *a, *b, *c, *d;
  Tree( int v ) {
    this->v = v;
    a = b = c = d = nullptr;
  }
};

string t1, t2;

Tree* create_tree( const string& t, int& i ) {
  Tree *node = new Tree( t[i++] );
  if( node->v == 'p' ) {
    node->a = create_tree( t, i );
    node->b = create_tree( t, i );
    node->c = create_tree( t, i );
    node->d = create_tree( t, i );
  }
  return node;
}

Tree* mv( Tree* r, int i ) {
  if( r == nullptr ) return nullptr;
  if( r->v != 'p' ) return nullptr; 
  if( i == 0 ) return r->a;
  if( i == 1 ) return r->b;
  if( i == 2 ) return r->c;
  if( i == 3 ) return r->d;
  return nullptr;
}

int mix( Tree* r1, Tree* r2, int d = 32 ) {
  if( r1 == nullptr && r2 == nullptr ) {
    return 0;
  }
  if( ( r1 != nullptr && r1->v == 'f' ) || ( r2 != nullptr && r2->v == 'f' ) ) {
    return d*d;
  }
  int r = 0;
  for( int i = 0; i < 4; ++i ) {
    r += mix( mv(r1,i), mv(r2,i), d/2 );
  }
  return r;
}

void print( Tree* r ) {
  if( r == nullptr ) return ;
  cout << char(r->v) << ' ';
  print( r->a );
  print( r->b );
  print( r->c );
  print( r->d );
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

  int n_test; cin >> n_test;

  while( n_test-- ) {
    cin >> t1 >> t2;
    int f;
    f = 0; Tree *r1 = create_tree( t1, f );
    f = 0; Tree *r2 = create_tree( t2, f );
    int ans = mix( r1, r2 );
    cout << "There are " << ans << " black pixels.\n";
  }

  return 0;
}

