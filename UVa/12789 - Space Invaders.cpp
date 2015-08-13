#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e3+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int r, c, s, a;
string board[ MAX ];
bool ans, p;

int parent[ MAX*MAX ], rnk[ MAX*MAX ], m[ MAX*MAX ], M[ MAX*MAX ];

void initialize( ) {
    for( int i = 0; i <= r*c; i++ ) {
        parent[ i ] = i;
        rnk[ i ] = 0;
        m[ i ] = M[ i ] = i/c;
    }
}

int Find( int x ) {
    if( x == parent[ x ] ) return x;
    return parent[ x ] = Find( parent[ x ] );
}

bool Merge( int x, int y ) {
    int xRoot = Find( x );
    int yRoot = Find( y );
    if( xRoot == yRoot ) return m[ xRoot ] == 0 && M[ xRoot ] == r-1;
    if( rnk[ xRoot ] > rnk[ yRoot ] ) {
        parent[ yRoot ] = xRoot;
        m[ xRoot ] = min( m[ xRoot ], m[ yRoot ] );
        M[ xRoot ] = max( M[ xRoot ], M[ yRoot ] );
        return m[ xRoot ] == 0 && M[ xRoot ] == r-1;
    }
    else {
        parent[ xRoot ] = yRoot;
        m[ yRoot ] = min( m[ yRoot ], m[ xRoot ] );
        M[ yRoot ] = max( M[ yRoot ], M[ xRoot ] );
        if( rnk[ xRoot ] == rnk[ yRoot ] ) rnk[ yRoot ]++;
        return m[ yRoot ] == 0 && M[ yRoot ] == r-1;
    }
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> r >> c >> s ) {
        ans = false; p = false;
        for( int i = 0; i < r; i++ ) cin >> board[ i ];
        initialize( );
        for( int i = 0; i < r; i++ ) {
            for( int j = 0; j < c; j++ ) {
                if( board[ i ][ j ] == '#' ) continue;
                if( r == 1 ) ans = true;
                if( i+1 < r && board[ i+1 ][ j ] == '.' ) ans |= Merge( i*c+j, (i+1)*c+j );
                if( j+1 < c && board[ i ][ j+1 ] == '.' ) ans |= Merge( i*c+j, i*c+(j+1) );
            }
        }
        if( ans ) cout << "0\n", p = true;
        for( int i = 0; i < s; i++ ) {
            cin >> a;
            if( a > 0 ) {
                a--;
                for( int j = 0; j < r; j++ ) {
                    if( board[ j ][ a ] == '#' ) {
                        if( j-1 >= 0 && board[ j-1 ][ a ] == '.' ) ans |= Merge( j*c+a, (j-1)*c+a );
                        if( a-1 >= 0 && board[ j ][ a-1 ] == '.' ) ans |= Merge( j*c+a, j*c+(a-1) );
                        if( j+1 < r && board[ j+1 ][ a ] == '.' )  ans |= Merge( j*c+a, (j+1)*c+a );
                        if( a+1 < c && board[ j ][ a+1 ] == '.' )  ans |= Merge( j*c+a, j*c+(a+1) );
                        if( r == 1 ) ans = true;
                        board[ j ][ a ] = '.';
                        break;
                    }
                }
                if( !p && ans ) cout << i+1 << "\n", p = true;
            }
            else {
                a = -a;
                a--;
                for( int j = r-1; j >= 0; j-- ) {
                    if( board[ j ][ a ] == '#' ) {
                        if( j-1 >= 0 && board[ j-1 ][ a ] == '.' ) ans |= Merge( j*c+a, (j-1)*c+a );
                        if( a-1 >= 0 && board[ j ][ a-1 ] == '.' ) ans |= Merge( j*c+a, j*c+(a-1) );
                        if( j+1 < r && board[ j+1 ][ a ] == '.' )  ans |= Merge( j*c+a, (j+1)*c+a );
                        if( a+1 < c && board[ j ][ a+1 ] == '.' )  ans |= Merge( j*c+a, j*c+(a+1) );
                        if( r == 1 ) ans = true;
                        board[ j ][ a ] = '.';
                        break;
                    }
                }
                if( !p && ans ) cout << -(i+1) << "\n", p = true;
            }
        }
        if( !p ) cout << "X\n";
    }

    return 0;
}
