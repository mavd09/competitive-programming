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

#define MODS                2
int mods[ MODS ] = { 1000000007, 1000000009/*1000016411/*, 1000017737*/ };
#define FOR                 for( int i = 0; i < MODS; ++i )

inline int fmpow( int b, ll e, int mod ) {
  int r = 1;
  while( e ) {
    if( e&1LL ) r = ll( r )*ll( b )%ll( mod );
    b = ll( b )*ll( b )%ll( mod );
    e >>= 1;
  }
  return r;
}

class mint {

#define X         x[i]
#define MOD       mods[i]
  int x[ MODS ];

public:

  inline mint inv()const{mint r;FOR r.X=fmpow(X,MOD-2,MOD);return r;}
  ll encode(){return (ll(x[0])<<32)+ll(x[1]);} //for unordered_map/set

  inline int operator()(int i)const{return X;}
  inline mint operator-()const{mint r(*this);FOR r.X=(X?MOD-X:0);return r;}
  inline mint operator+(const mint& a)const{mint r;FOR r.X=(X+a.X)%MOD;return r;}
  inline mint operator-(const mint& a)const{mint r;FOR{r.X=X-a.X;if(r.X<0)r.X+=MOD;}return r;}
  inline mint operator*(const mint& a)const{mint r;FOR r.X=int(ll(X)*ll(a.X)%ll(MOD));return r;}
  inline mint operator/(const mint& a)const{return (*this)*a.inv();}

  inline mint&operator+=(const mint& a){*this=*this+a;return*this;}
  inline mint&operator-=(const mint& a){*this=*this-a;return*this;}
  inline mint&operator*=(const mint& a){*this=*this*a;return*this;}
  inline mint&operator/=(const mint& a){*this=*this/a;return*this;}

  inline mint&operator=(const mint&a){FOR X=a.X;return*this;}

  inline bool operator==(const mint&a)const{FOR if(X!=a.X)return 0;return 1;}
  inline bool operator!=(const mint&a)const{FOR if(X==a.X)return 0;return 1;}
  inline bool operator<(const mint&a)const{FOR if(X!=a.X)return X<a.X;return 0;}

  mint(){FOR X=0;}
  mint(ll v){FOR{X=int(v%ll(MOD));if(X<0)X+=MOD;}}
  mint(const mint&a){FOR X=a.X;}

};

ostream&operator<<(ostream&o,const mint&m){ o<<"{ ";FOR o<<m(i)<<' ';o<<"}";return o;}
istream&operator>>(istream&i,mint&m){ll x;i>>x;m=mint(x);return i;}

void findMOD( ) {
  srand(time(nullptr));
  FOR {
    MOD = 1000000000 + rand()%5000000;
    while ( true ) {
      bool isPrime = true;
      for ( int j = 2; j*j <= MOD; ++j )
        if ( MOD%j == 0 ) {
          isPrime = false;
          break;
        }
      if ( isPrime ) break;
      MOD++;
    }
    cout << MOD << endl;
  }
}

const int MAXN = int( 1e5 )+100;

int n, q, l;
string word;
mint base( 30 ), val[ 30 ];
mint pow_base[ MAXN ];

mint get_hash( ) {
  mint r;
  for( int i = 0; i < l; i++ )
    r += val[ word[ i ]-'a'+1 ]*pow_base[ i ];
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

  for( int i = 0; i < 30; i++ )
    val[ i ] = mint( i );

  pow_base[ 0 ] = mint( 1 );
  for( int i = 1; i < MAXN; i++ )
    pow_base[ i ] = pow_base[ i-1 ]*base;

  while( cin >> n >> q >> l ) {
    map< ll, int > cnt;
    for( int i = 0; i < n; i++ ) {
      cin >> word;
      cnt[ get_hash( ).encode( ) ]++;
    }
    for( int i = 0; i < q; i++ ) {
      cin >> word;
      ll ans = 0, code;
      mint cur_hash = get_hash( );
      for( int j = 0; j < l; j++ ) {
        mint new_hash = cur_hash - val[ word[ j ]-'a'+1 ]*pow_base[ j ];
        for( int k = 1; k <= 26; k++ ) {
          new_hash += pow_base[ j ];
          code = new_hash.encode( );
          if( cnt.count( code ) )
            ans += cnt[ code ];
        }
      }
      cout << ans << "\n";
    }
  }

  return 0;
}