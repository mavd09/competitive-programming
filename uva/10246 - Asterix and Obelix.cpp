#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 1e2 )
#define INF 	INT_MAX/10
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int C, R, Q, fr, to, d, f, t;
int G[ MAXN ][ MAXN ][ MAXN ], F[ MAXN ];

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> C >> R >> Q ) && C+R+Q > 0 ) {

        for( int c = 1; c <= C; c++ ) {
            for( int i = 1; i <= C; i++ ) {
                for( int j = 1; j <= C; j++ ) {
                    G[ c ][ i ][ j ] = INF;
                }
                G[ c ][ i ][ i ] = 0;
            }
        }

        for( int i = 1; i <= C; i++ )
            cin >> F[ i ];

        for( int i = 1; i <= R; i++ ) {
            cin >> fr >> to >> d;
            for( int c = 1; c <= C; c++ ) {
                if( F[ fr ] <= F[ c ] && F[ to ] <= F[ c ] ) {
                    G[ c ][ fr ][ to ] = G[ c ][ to ][ fr ] = d;
                }
            }

        }

        for( int c = 1; c <= C; c++ ) {
            for( int k = 1; k <= C; k++ ) {
                for( int i = 1; i <= C; i++ ) {
                    for( int j = 1; j <= C; j++ ) {
                        G[ c ][ i ][ j ] = min( G[ c ][ i ][ j ], G[ c ][ i ][ k ]+G[ c ][ k ][ j ] );
                    }
                }
            }
        }

        if( t ) cout << "\n";
        cout << "Case #" << ++t << "\n";
        for( int i = 1; i <= Q; i++ ) {
            cin >> fr >> to;
            int ans = INF;
            for( int c = 1; c <= C; c++ )
                ans = min( ans, G[ c ][ fr ][ to ]+F[ c ] );
            if( ans == INF ) ans = -1;
            cout << ans << "\n";
        }

    }

    return 0;
}
