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

const int MAXN = int( 2e5 );
const int MOD  = int( 10 );
const int oo   = INT_MAX;

typedef vector< vi >        Matrix;

Matrix res( 4, vi( 4 ) );

void mul( Matrix& a, Matrix& b ) {
  for( int i = 0; i < 4; i++ ) {
    for( int j = 0; j < 4; j++ ) {
      res[ i ][ j ] = 0;
      for( int k = 0; k < 4; k++ ) {
        res[ i ][ j ] += ( a[ i ][ k ]*b[ k ][ j ] )%MOD;
      }
    }
  }
  a = res;
}

Matrix fpow( Matrix r, Matrix b, ll e ) {
  while( e ) {
    if( e&1 ) mul( r, b );
    mul( b, b );
    e /= 2;
  }
  return r;
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

  Matrix base = { { 4, 7, 7, 0 }, { 5, 6, 6, 0 }, { 9, 1, 0, 0 }, { 8, 4, 3, 1 } };
  Matrix iden = { { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } };

  int n_test; cin >> n_test;

  for( int tc = 1; n_test--; tc++ ) {
    ll n, sz; int a, b, c;
    cin >> n >> a >> b >> c; n--;
    n %= 15;
    Matrix r = fpow( iden, base, n+1 );
    int ans = ( r[ 3 ][ 0 ]*a + r[ 3 ][ 1 ]*b + r[ 3 ][ 2 ]*c + r[ 3 ][ 3 ]*1 )%MOD;
    ans = ( ans-1+MOD )%MOD;
    cout << ans << "\n";
  }

  return 0;
}