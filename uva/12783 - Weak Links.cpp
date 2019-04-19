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
#define INF 	INT_MAX/5
#define EPS 	int( 1e-7 )
#define MOD 	int( 1e7+7 )
#define PI 	    acos( -1 )

#define EMPTY   0
#define GREEN   1
#define RED     2

typedef long long ll;

using namespace std;

int n, m, f, t, T;
vector< int > G[ MAX ];
bool seen[ MAX ];
int D[ MAX ], L[ MAX ], P[ MAX ];
set< pair< int, int > > ans;

void initialize( ) {
    T = 0;
    memset( P, -1, sizeof( P ) );
    memset( seen, false, sizeof( seen ) );
    ans.clear( );
    for( int i = 0; i < n; i++ ) G[ i ].clear( );
}

void bridgeUtil( int u ) {
    seen[ u ] = true;
    D[ u ] = L[ u ] = ++T;
    for( int i = 0; i < int( G[ u ].size( ) ); i++ ) {
        int v = G[ u ][ i ];
        if( !seen[ v ] ) {
            P[ v ] = u;
            bridgeUtil( v );
            L[ u ] = min( L[ u ], L[ v ] );
            if( L[ v ] > D[ u ] ) ans.insert( MP( min( u, v ), max( u, v ) ) );
        }
        else if( v != P[ u ] ) {
            L[ u ] = min( L[ u ], D[ v ] );
        }
    }
}

void findBridges( ) {
    for( int i = 0; i < n; i++ )
        if( !seen[ i ] )
            bridgeUtil( i );
    printf( "%d", int( ans.size( ) ) );
    for( set< pair< int, int > >::iterator it = ans.begin( ); it != ans.end( ); it++ )
        printf( " %d %d", (*it).FI, (*it).SE );
    printf( "\n" );
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( scanf( "%d %d", &n, &m ) != EOF ) && ( n+m > 0 ) ) {

        initialize( );

        for( int i = 0; i < m; i++ ) {
            scanf( "%d %d", &f, &t );
            G[ f ].PB( t );
            G[ t ].PB( f );
        }

        findBridges( );

    }

    return 0;
}
