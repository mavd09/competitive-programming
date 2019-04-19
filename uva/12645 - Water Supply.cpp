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

int n, m, a, b;
vector< int > G[ MAX ], ts;
int seen[ MAX ];

void topologicalSort( int node ) {
    seen[ node ] = 1;
    for( int i = 0; i < int( G[ node ].size( ) ); i++ )
        if( seen[ G[ node ][ i ] ] != 1 )
            topologicalSort( G[ node ][ i ] );
    ts.PB( node );
}

void dfs( int node, int v ) {
    seen[ node ] = v;
    for( int i = 0; i < int( G[ node ].size( ) ); i++ )
        if( seen[ G[ node ][ i ] ] != v )
            dfs( G[ node ][ i ], v );
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( scanf( "%d %d", &n, &m ) != EOF ) {

        ts.clear( );
        memset( seen, 0, sizeof( seen ) );
        for( int i = 0; i <= n; i++ ) G[ i ].clear( );

        for( int i = 0; i < m; i++ ) {
            scanf( "%d %d", &a, &b );
            G[ a ].PB( b );
        }

        int ans = 0;
        dfs( 0, 1 );
        for( int i = 1; i <= n; i++ )
            if( seen[ i ] != 1 )
                topologicalSort( i );
        for( int i = int( ts.size( ) )-1; i >= 0; i-- ) {
            if( seen[ ts[ i ] ] != 2 )
                ans++, dfs( ts[ i ], 2 );
        }
        printf( "%d\n", ans );

    }

    return 0;
}
