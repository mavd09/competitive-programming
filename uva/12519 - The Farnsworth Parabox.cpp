#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 150 )
#define INF 	INT_MAX/5
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, b, fr, to, t;
int minDist[ MAX ][ MAX ];

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( scanf( "%d %d", &n, &b ) != EOF ) && ( n+b > 0 ) ) {

        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                minDist[ i ][ j ] = INF;
            }
            minDist[ i ][ i ] = 0;
        }

        for( int i = 0; i < b; i++ ) {
            scanf( "%d %d %d", &fr, &to, &t );
            minDist[ fr ][ to ] = t;
            minDist[ to ][ fr ] = -t;
        }

        for( int k = 1; k <= n; k++ ) {
            for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                    minDist[ i ][ j ] = min( minDist[ i ][ j ], minDist[ i ][ k ]+minDist[ k ][ j ] );
                }
            }
        }

        bool ans = false;
        for( int i = 1; i <= n; i++ ) ans |= ( minDist[ i ][ i ] < 0 );
        printf( "%c\n", ( ans ? 'Y' : 'N' ) );

    }

    return 0;
}
