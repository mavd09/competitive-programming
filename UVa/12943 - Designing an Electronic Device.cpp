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
const ll  mod = ( 1LL<<31 )-1LL;
const int oo  = 1e8;

struct Fraction { ll numerator, denominator; };

istream& operator >> ( istream& in, Fraction& a ) {
  ll numerator, denominator;
  in >> numerator >> denominator;
  ll gcd = __gcd( numerator, denominator );
  a = { numerator/gcd, denominator/gcd };
  return in;
}

Fraction operator + ( const Fraction& a, const Fraction& b ) {
  ll gcd = __gcd( a.denominator, b.denominator );
  ll denominator = a.denominator/gcd*b.denominator;
  ll numerator = denominator/a.denominator*a.numerator + denominator/b.denominator*b.numerator;
  return { numerator, denominator };
}

Fraction operator - ( const Fraction& a, const Fraction& b ) {
  ll gcd = __gcd( a.denominator, b.denominator );
  ll denominator = a.denominator/gcd*b.denominator;
  ll numerator = denominator/a.denominator*a.numerator - denominator/b.denominator*b.numerator;
  return { numerator, denominator };
}

Fraction operator * ( const Fraction& a, const Fraction& b ) {
  ll numerator = a.numerator*b.numerator;
  ll denominator = a.denominator*b.denominator;
  ll gcd = __gcd( numerator, denominator );
  return { numerator/gcd, denominator/gcd };
}

Fraction operator / ( const Fraction& a, const Fraction& b ) {
  ll numerator = a.numerator*b.denominator;
  ll denominator = a.denominator*b.numerator;
  ll gcd = __gcd( numerator, denominator );
  return { numerator/gcd, denominator/gcd };
}

bool operator < ( const Fraction& a, const Fraction& b ) {
  return lf( a.numerator )*lf( b.denominator ) < lf( b.numerator )*lf( a.denominator );
}

ostream& operator << ( ostream& out, const Fraction& a ) {
  out << a.numerator << "/" << a.denominator;
  return out;
}

const Fraction ONE = { 1, 1 };
const Fraction ZERO = { 0, 1 };

int main( ) {

  ios_base::sync_with_stdio( 0 );
  cin.tie( 0 );

  int n, k;

  while( cin >> n >> k ) {
    vi m( n );
    for( auto& e : m ) {
      cin >> e;
    }
    vector< vector< Fraction > > dp( n+1, vector< Fraction >( k+1, ZERO ) );
    dp[ 0 ][ 0 ] = ONE;
    for( int i = 0; i < n; i++ ) {
      for( int j = 0; j < m[ i ]; j++ ) {
        Fraction a; int c; cin >> a >> c;
        a = ONE-a;
        for( int kk = 0; kk+c <= k; kk++ ) {
          dp[ i+1 ][ kk+c ] = max( dp[ i+1 ][ kk+c ], dp[ i ][ kk ]*a );
        }
      }
    }
    Fraction ans = ZERO;
    for( int kk = 0; kk <= k; kk++ ) {
      ans = max( ans, dp[ n ][ kk ] );
    }
    ans = ONE-ans;
    cout << ans << "\n";
  }

  return 0;
}