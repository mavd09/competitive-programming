#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <set>
#include <deque>
#include <utility>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#include <math.h>
#include <algorithm>
#include <limits.h>
#include <iomanip>

#include <cstdio>
#include <cmath>
#include <climits>
#include <cassert>

#include <complex>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< vb >        vvb;
typedef vector< lf >        vd;
typedef vector< vd >        vvd;
typedef vector< vvd >       vvvd;
typedef vector< ll >        vll;
typedef vector< vll >       vvll;
typedef vector< int >       vi;
typedef vector< vi >        vvi;
typedef vector< vvi >       vvvi;
typedef vector< vvvi >      vvvvi;
typedef vector< pii >       vpii;
typedef vector< vpii >      vvpii;

typedef complex< lf >       pt;

const int MX  = 123;
const int MOD = int( 360 );
const int oo  = int( 2e9 );

const int rounds = 20;

long long mod_mul(long long a, long long b, long long mod) {
  long long x = 0, y = a % mod;
  while (b > 0) {
    if (b & 1)
      x = (x + y) % mod;
    y = (y * 2) % mod;
    b /= 2;
  }
  return x % mod;
}

long long mod_pow(long long a, long long exp, long long mod) {
  long long ans = 1;
  while (exp > 0) {
    if (exp & 1)
      ans = mod_mul(ans, a, mod);
    a = mod_mul(a, a, mod);
    exp >>= 1;
  }
  return ans;
}

bool witness(long long a, long long n) {
  long long u = n - 1;
  int t = 0;
  while (u % 2 == 0) {
    t++;
    u >>= 1;
  }
  long long next = mod_pow(a, u, n);
  if (next == 1) return false;
  long long last;
  for (int i = 0; i < t; ++i) {
    last = next;
    next = mod_mul(last, last, n);
    if (next == 1) {
      return last != n - 1;
    }
  }
  return next != 1;
}

bool miller_rabin( ll n, int it = rounds ) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 0; i < it; ++i) {
    ll a = rand() % (n - 1) + 1;
    if (witness(a, n)) {
      return false;
    }
  }
  return true;
}

bitset< 10000010 > is_prime;

vi sieve( const ll mx ) {
  is_prime.set( );
  is_prime[ 0 ] = is_prime[ 1 ] = 0;
  for( int i = 2; i*i < mx; i++ ) {
    if( is_prime[ i ] ) {
      for( int j = i*i; j < mx; j += i ) {
        is_prime[ j ] = 0;
      }
    }
  }
  vi primes;
  for( int i = 0; i < mx; i++ ) {
    if( is_prime[ i ] ) {
      primes.PB( i );
    }
  }
  return primes;
}

int main( ) {

  #ifdef LOCAL
    freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #else
    //freopen( "input", "r", stdin );
    //freopen( "output", "w", stdout );
  #endif

  srand( time( NULL ) );

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  vi primes = sieve( 10000010 );

  ll n, m; cin >> n;
  
  if( n == 6 ) {
    cout << "2 2 2\n";
    return 0;
  }
  m = n;
  if( n%2 == 0 ) {
    cout << "counterexample\n";
    return 0;
  }
  m -= 4;
  while( !miller_rabin( m ) ) {
    m -= 2;
  }
  n -= m;
  for( auto& p : primes ) {
    if( n-p <= 0 ) {
      break;
    }
    if( is_prime[ n-p ] ) {
      cout << m << " " << p << " " << n-p << "\n";
      return 0;
    }
  }
  cout << "counterexample\n";

  return 0;
}