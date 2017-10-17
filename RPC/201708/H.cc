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

const int MAXN = int( 100 )+10;
const int MOD  = int( 1e9 )+7;
const ull  oo   = 1LL<<63;

int b;
ll n;

bool is_prime( ll x ) {
  for( ll i = 2; i*i <= x; ++i ) {
    if( x%i == 0 ) {
      return false;
    }
  }
  return true;
}

ll overflowm( ll x, ll y ) {
  return x >= b/y;
}

ll mod_mul( ull a, ull b, ull mod ) {
  ll x = 0, y = a%mod;
  while( b > 0 ) {
    if( b&1 ) {
      x = x+y;
      x = ( x > mod ? x-mod : x );
    }
    y = y*2LL;
    y = ( y > mod ? y-mod : y );
    b >>= 1;
  }
  return x;
}

ll mod_pow( ll a, ll e, ll mod ) {
  ll r = 1;
  while( e > 0 ) {
    if( e&1 )
      r = mod_mul( r, a, mod );
    a = mod_mul( a, a, mod );
    e >>= 1;
  }
  return r;
}

bool witness( ll a, ll n ) {
  ll u = n-1;
  int t = 0;
  while( !( u&1 ) ) {
    t++;
    u >>= 1;
  }
  ll next = mod_pow( a, u, n );
  if( next == 1 ) return false;
  ll last;
  for( int i = 0; i < t; ++i ) {
    last = next;
    next = mod_mul( last, last, n );
    if( next == 1 )
      return ( last != n - 1 );
  }
  return next != 1;
}

bool miller_rabin( ll n, int it = 20 ) {
  if( n <= 1 ) return false;
  if( n == 2 ) return true;
  if( n%2 == 0 ) return false;
  for( int i = 0; i < it; ++i ) {
    ll a = rand( )%( n-1 ) + 1;
    if( witness( a, n ) )
      return false;
  }
  return true;
}

ll pollard_rho( ll n ) {
  ll x, y, i = 1, k = 2, d;
  x = y = rand( )%n;
  while( true ) {
    ++i;
    x = mod_mul( x, x, n );
    x += 2;
    if( x >= n ) x -= n;
    if( x == y ) return 1;
    d = __gcd( abs( x-y ), n );
    if( d != 1 ) return d;
    if( i == k ) {
      y = x;
      k *= 2;
    }
  }
  return 1;
}

vll factorize( ll n ) {
  vll ans;
  if( n == 1 )
    return ans;
  if( miller_rabin( n ) )
    ans.PB( n );
  else {
    ll d = 1;
    while( d == 1 ) d = pollard_rho( n );
    vll dd = factorize( d );
    ans = factorize( n/d );
    for( int i = 0; i < SIZE( dd ); i++ )
      ans.PB( dd[ i ] );
  }
  return ans;
}

bool used[ MAXN ];
vll best, f, v;

void save_best( ) {
  vll cur = v;
  sort( ALL( cur ) );
  if( SIZE( best ) == 0 || SIZE( cur ) < SIZE( best ) ) {
    best = cur;
  } else {
    for( int i = 0; i < SIZE( best ); ++i ) {
      if( cur[ i ] < best[ i ] ) {
        best = cur;
        break;
      }
    }
  }
}

void go( ) {
  int idx = 1;
  while( idx < SIZE( f ) && used[ idx ] ) idx++;
  if( idx == SIZE( f ) ) {
    save_best( );
    return ;
  }
  used[ idx ] = true;
  if( !overflowm( v.back( ), f[ idx ] ) ) {
    v.back( ) = v.back( )*f[ idx ];
    go( );
    v.back( ) = v.back( )/f[ idx ];
  }
  v.PB( f[ idx ] );
  go( );
  v.pop_back( );
  used[ idx ] = false;
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
/*
  for( int i = 2; ; ++i ) {
    if( is_prime( i ) ) {
      if( SIZE( f ) == 15 ) {
        break;
      }
      f.PB( i );
    }
  }

  b = 10000;

  v.PB( f[ 0 ] );
  go( );
  for( auto& e : best ) {
    cout << e << ' ';
  }

  return 0;
*/
  while( cin >> b >> n ) {
    bool ok = true;
    f = factorize( n );
    for( auto& e : f ) {
      if( e >= b ) {
        ok = false;
      }
    }
    if( !ok ) {
      cout << "impossible\n";
    } else {
      for( auto& e : f ) {
        cout << e << ' ';
      }
      cout << '\n';
      cout << SIZE( f ) << endl;
      best.clear( );
      memset( used, false, sizeof( used ) );
      v = { f[ 0 ] }; used[ 0 ] = true;
      go( );
      cout << "waza" << endl;
      ull ans = 0, pot = 1;
      reverse( ALL( best ) );
      for( int i = 0; i < SIZE( best ); ++i, pot = pot*ull(b) ) {
        ans += ull(best[i])*pot;
      }
      cout << ans << '\n';
    }
    break;
  }

  return 0;
}