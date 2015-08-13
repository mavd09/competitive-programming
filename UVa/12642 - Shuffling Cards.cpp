#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e3+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int N, t;
ll R;
int ans[ MAX ], P[ MAX ];
int seen[ MAX ];
vector< int > inCycle;

int dfs( int cur ) {
    if( seen[ cur ] == t ) return 0;
    seen[ cur ] = t;
    inCycle.PB( cur );
    return dfs( P[ cur ] )+1;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( scanf( "%d %lld", &N, &R ) != EOF ) {
        for( int i = 1; i <= N; i++ ) {
            scanf( "%d", &P[ i ] );
            ans[ i ] = i;
        }
        ++t;
        for( int i = 1; i <= N; i++ ) {
            if( seen[ i ] == t ) continue;
            inCycle.clear( );
            int cycleSize = dfs( i );
            for( int j = 0; j < cycleSize; j++ ) {
                int id = ( ( R%ll(cycleSize) )+j )%cycleSize;
                ans[ inCycle[ j ] ] = inCycle[ id ];
            }
        }

        for( int i = 1; i <= N; i++ ) {
            if( i != 1 ) printf( " " );
            printf( "%d", ans[ i ] );
        }
        printf( "\n" );
    }

    return 0;
}
