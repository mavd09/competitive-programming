#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e5+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, f, a, b, c;
vector< pair< int, int > > G[ MAX ];
bool F[ MAX ], visited[ MAX ];

struct Tuple {

    bool s;
    int  x, y;

    Tuple( ) { }
    Tuple( bool s, int x, int y ) : s( s ), x( x ), y( y ) { }
    int getAnswer( ) { return x-y; }

};

Tuple dfs( int node ) {

    visited[ node ] = true;
    Tuple ret( F[ node ], 0, 0 );

    for( int i = 0; i < int( G[ node ].size( ) ); i++ ) {
        if( !visited[ G[ node ][ i ].FI ] ) {
            Tuple tmp = dfs( G[ node ][ i ].FI );
            if( tmp.s == true ) {
                ret.s = true;
                ret.x += tmp.x+G[ node ][ i ].SE;
                ret.y = max( ret.y, tmp.y+G[ node ][ i ].SE );
            }
        }
    }

    return ret;

}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( scanf( "%d %d", &n, &f ) != EOF ) {

        memset( visited, false, sizeof( visited ) );
        memset( F, false, sizeof( F ) );
        for( int i = 0; i <= n; i++ ) G[ i ].clear( );
        for( int i = 1; i < n; i++ ) {
            scanf( "%d %d %d", &a, &b, &c );
            G[ a ].PB( MP( b, c ) );
            G[ b ].PB( MP( a, c ) );
        }
        for( int i = 0; i < f; i++ ) {
            scanf( "%d", &a );
            F[ a ] = true;
        }

        printf( "%d\n", dfs( 1 ).getAnswer( ) );
    }

    return 0;
}
