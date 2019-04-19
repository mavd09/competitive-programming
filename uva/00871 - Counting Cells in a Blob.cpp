#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 50 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int nTest, r, c, curX, curY;
string board[ MAXN ];
bool seen[ MAXN ][ MAXN ];

int dfs( int x, int y ) {
    int ret = 0;
    seen[ x ][ y ] = true;
    for( int dx = -1; dx <= 1; dx++ ) {
        for( int dy = -1; dy <= 1; dy++ ) {
            if( dx == 0 && dy == 0 ) continue;
            curX = x+dx; curY = y+dy;
            if( 0 <= curX && curX < r && 0 <= curY && curY < c && !seen[ curX ][ curY ] && board[ curX ][ curY ] == '1' )
                ret += dfs( curX, curY );
        }
    }
    return ret+1;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    cin >> nTest;
    cin.ignore( 2 );
    while( nTest-- ) {

        memset( seen, false, sizeof( seen ) );

        for( r = 0, c = 0; ; r++ ) {
            getline( cin, board[ r ] );
            c = max( c, int( board[ r ].size( ) ) );
            if( int( board[ r ].size( ) ) == 0 ) break;
        }

        int ans = 0;
        for( int i = 0; i < r; i++ ) {
            for( int j = 0; j < c; j++ ) {
                if( board[ i ][ j ] == '1' && !seen[ i ][ j ] )
                    ans = max( ans, dfs( i, j ) );
            }
        }
        cout << ans << "\n";
        if( nTest ) cout << "\n";

    }

    return 0;
}
