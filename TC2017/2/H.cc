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

const int MAXN = int( 2e3 );
const int MOD  = int( 360 );
const int oo   = INT_MAX;

const lf EPS = 1e-9;
const lf PI = acos( -1.0 );

struct pt {
  lf x, y;
  pt( ) { }
  pt( lf x, lf y ) : x( x ), y ( y ) { }
};

inline lf x( pt P ) { return P.x; }
inline lf y( pt P ) { return P.y; }

istream& operator >> ( istream& in, pt& p ) {
  lf x,y; in >> x >> y;
  p = pt(x,y); return in;
}

ostream& operator << ( ostream& out, const pt& p ) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

pt operator + ( const pt& A, const pt& B ) {
  return { x(A)+x(B), y(A)+y(B) };
}

pt operator - ( const pt& A, const pt& B ) {
  return { x(A)-x(B), y(A)-y(B) };
}

pt operator * ( const pt& A, const pt& B ) {
  return { x(A)*x(B)-y(A)*y(B), x(A)*y(B)+y(A)*x(B) };
}

pt operator * ( const pt& A, const lf& B ) {
  return { x(A)*B, y(A)*B };
}

pt operator * ( const lf& B, const pt& A ) {
  return { x(A)*B, y(A)*B };
}

pt operator / ( const pt& A, const lf& B ) {
  return { x(A)/B, y(A)/B };
}

inline lf cross( pt A, pt B ) {
  return x(A)*y(B) - y(A)*x(B);
}

inline lf dot( pt A, pt B ) {
  return x(A)*x(B) + y(A)*y(B);
}

inline lf norm( pt A ) {
  return x(A)*x(A) + y(A)*y(A);
}

inline lf abs( pt A ) {
  return sqrt( norm(A) );
}

inline lf arg( pt A ) {
  return atan2( y(A), x(A) );
}

inline pt exp( pt A ) {
  return pt( exp( x(A) )*cos( y(A) ), exp( x(A) )*sin( y(A) ) ) ;
}

inline bool same ( lf a, lf b ) {
  return a+EPS > b && b+EPS > a;
}

inline bool samePt ( pt A, pt B ) {
  return same ( x(A), x(B) ) && same ( y(A), y(B) );
}

inline bool segContains ( pt X, pt A, pt B) {
  if ( !same ( 0, cross ( A-X, B-X ) ) ) return 0;
  return ( dot ( A-X, B-X ) <= EPS );
}

inline bool collinearSegsIntersects ( pt A, pt B, pt C, pt D ) {
  return segContains(A,C,D) || segContains(B,C,D)
      || segContains(C,A,B) || segContains(D,A,B);
}

pt linesIntersection ( pt A, pt B, pt C, pt D ) {
  lf x = cross ( C, D-C ) - cross ( A, D-C );
  x /= cross ( B-A, D-C );
  return A + x*(B-A);
}

bool segmentsIntersect(pt A, pt B, pt C, pt D, pt& aux) {
  aux = linesIntersection(A,B,C,D);
  return segContains(aux,A,B) && segContains(aux,C,D);
}

struct Event { pt p;
               int t, idx; };

struct Cmp_Event{
  bool operator ( ) ( const Event& e1, const Event& e2 ) {
    if( x(e1.p) == x(e2.p) )
      return e1.t > e2.t;
    return x(e1.p) > x(e2.p)+EPS;
  }
};

priority_queue< Event, vector<Event>, Cmp_Event > pq;
pt P[ 3 ][ MAXN ];
double area;
bool open;
vector<int> lines;
pt slope[ 2 ];
pt lastPoint;

void init( ) {
  area = 0.0;
  open = false;
  lines.clear();
  lastPoint = pt( 0, 0 );
}

void go( Event e ) {
  if( e.t == 1 ) {
    change_triangle();
  }
  else if( e.t == 2 ) {
    intersection();
  }
  else if( e.t == 3 ) {
    start_triangle( P[ 0 ][ e.idx ], P[ 1 ][ e.idx ], e.idx );
  }
  else {
    close_triangle();
  }
}

void start_triangle( pt A, pt B, int idx ) {
  if( !open ) {
    open = true;
    slope[ 0 ] = A;
    slope[ 1 ] = B;
    lines.PB( idx );
  }
  else {

  }
}

void close_triangle() {
  if( lines.size() == 1 ) {
    open = false;
    lines.clear();
  }
  else {

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

  while( cin >> n ) {
    if( n == -1 ) {
      break;
    }
    init();
    for( int i = 1; i <= n; ++i ) {
      int a, b, c; cin >> a >> b >> c;
      P[ 0 ][ i ] = pt( a, 0 );
      P[ 1 ][ i ] = pt( (a+b)/2.0, c );
      P[ 2 ][ i ] = pt( b, 0 );
      pq.push( { P[0][i], 3, i } );
      pq.push( { P[1][i], 1, i } );
      pq.push( { P[2][i], 4, i });
    }
    while( !pq.empty() ) {
      Event cur = pq.top(); pq.pop();
      go( cur );
    }
    cout << area << '\n';
  }


  return 0;
}