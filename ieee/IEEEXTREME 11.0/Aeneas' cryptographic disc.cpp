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

const int MAXN = int( 1e3 )+10;
const int MOD  = int( 360 );
const int oo   = INT_MAX;
const lf PI = acos(-1.0);

lf r, ang[ MAXN ];

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

  cin >> r;
  for( int i = 0; i < 26; ++i ) {
    char c; lf a; cin >> c >> a;
    ang[ c-'A' ] = a*PI/180.0;
  }
  string s;
  cin.ignore();
  getline(cin, s);
  lf ans = 0.0;
  int i = 0;
  while( i < SIZE(s) && !('a' <= s[i] && s[i] <= 'z') && !('A' <= s[i] && s[i] <= 'Z') ) {
    ++i;
  }
  if( i < SIZE(s) ) {
    ans += r;
    int cur = toupper(s[i])-65;
    ++i;
    for(; i < SIZE(s); ++i ) {
      if( (!('a' <= s[i] && s[i] <= 'z') && !('A' <= s[i] && s[i] <= 'Z')) || toupper(s[i])-65 == cur ) continue;
      //cout << cur << " " << toupper(s[i])-65 << " " << abs( ang[cur] - ang[toupper(s[i])-65] ) << " " << double(ans) << endl;
      ans += 2.0*r*sin( fabs( ang[cur] - ang[toupper(s[i])-65] )/2.0 );
      cur = toupper(s[i])-65;
    }
  }
  cout << int(ceil(ans)) << '\n';
  return 0;
}
