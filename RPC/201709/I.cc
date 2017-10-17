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

ll m, k;

bool is_valid( ll m, ll mask, ll k ) {
  for( int i = 0; i+k-1 < 60; ++i, mask <<= 1 ) {
    if( (m&mask) == mask ) {
      return true;
    } 
  }
  return false;
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

  while( cin >> m >> k ) {
    int id = -1;
    for( int i = 0; i < 55; ++i ) {
      if( ((m>>i)&1) && i-k+1 >= 0 ) {
        id = i;
        break;
      }
    }
//    cout << bitset<15>(m) << ' ';
    ll mask = (1LL<<k)-1;
    if( is_valid(m, mask, k) ) cout<< m << '\n';
    else if( id == -1 ) cout << mask << '\n';
    else if( id-k > 0 ) cout << (m|mask) << '\n';
    else {
      for( int i = 0; i < k; ++i ) {
        m |= (1LL<<(id-i));
      }
      cout << m << '\n';
    }
  }

  return 0;
}

