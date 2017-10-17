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
typedef long long         lf;
typedef pair< int, int >    pii;
typedef pair< ll, ll >      pll;
typedef vector< bool >      vb;
typedef vector< lf >        vd;
typedef vector< ll >        vll;
typedef vector< int >       vi;
typedef vector< pii >       vpii;

const int MAXN = int( 1e4 )+10;
const int MOD  = int( 1e9 )+7;
const int oo   = INT_MAX;

const int DIM = 2;
struct pt {
  lf v[DIM];  
  pt( ) { }
  pt( lf x, lf y ) {
    v[0] = x;
    v[1] = y;
  }
};

inline lf x( pt P ) { return P.v[0]; }
inline lf y( pt P ) { return P.v[1]; }

inline lf cross( pt A, pt B ) { return x(A)*y(B) - y(A)*x(B); }

istream& operator >> ( istream& in, pt& p ) {
  for( int i = 0; i < DIM; ++i ) {
    in >> p.v[i];
  }
  return in;
}

ll get_points( pt p, pt q ) {
  return __gcd( abs(x(p)-x(q)), abs(y(p)-y(q)) );
}

double signedArea(const vector<pt> &P) {
  double result = 0.0;
  for(int i = 0; i < (int)P.size()-1; i++) result += cross( P[i],P[i+1] );
    return result / 2.0;
}

double area(const vector<pt> &P) { return fabs(signedArea(P)); }

int t;
int n;

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

  cin >> t;
  for( int test = 1; test <= t; ++test ) {
    cin >> n;
    vector<pt> P(n+1);
    for( int i = 0; i < n; ++i ) {
      cin >> P[i];
    }
    P[n] = P[0];
    double b  = 0;
    for( int i = 0; i < n; ++i ) {
      b += get_points( P[i], P[i+1] );
    }
    double A = area( P );
    cout << "Case " << test << ": ";
    cout << ll(A-b/2.0+1) << '\n';
  } 

  return 0;
}

