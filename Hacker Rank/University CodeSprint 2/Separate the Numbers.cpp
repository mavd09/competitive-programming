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

typedef complex< lf >       pt;

const int MAXN = int( 1e5 );
const int MOD  = int( 360 );
const ll  oo   = LLONG_MAX;

string line;
ll ans;

void solve( int i, ll lst, ll f ) {
  if( i == SIZE( line ) ) {
    ans = min( ans, f );
    return ;
  }
  if( lst == -1 ) {
    ll cur = 0;
    while( i+1 < SIZE( line ) ) {
      int d = line[ i ]-'0';
      if( cur == 0 && d == 0 ) break;
      cur = cur*10 + d;
      solve( i+1, cur, cur );
      i++;
    }
  }
  else {
    ll cur = 0;
    while( i < SIZE( line ) && cur != lst+1 ) {
      int d = line[ i ]-'0';
      if( cur == 0 && d == 0 ) break;
      cur = cur*10 + d;
      i++;
    }
    if( cur == lst+1 )
      solve( i, cur, f );
  }
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

  int q;
  cin >> q;

  while( q-- ) {
    cin >> line;
    ans = oo;
    solve( 0, -1, -1 );
    if( ans != oo )
      cout << "YES " << ans << "\n";
    else
      cout << "NO\n";
  }

  return 0;
}
