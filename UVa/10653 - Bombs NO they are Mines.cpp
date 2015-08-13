#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 1e3+100 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

const int dx[ ] = {  0  ,  0  ,  1  , -1  };
const int dy[ ] = {  1  , -1  ,  0  ,  0  };

int r, c, k, fx, fy, tx, ty;
bool seen[ MAXN ][ MAXN ];

int solve( ) {
    queue< int > q;
    q.push( fx );
    q.push( fy );
    q.push( 0 );
    seen[ fx ][ fy ] = true;
    while( !q.empty( ) ) {
        int x = q.front( ); q.pop( );
        int y = q.front( ); q.pop( );
        int cost = q.front( ); q.pop( );
        if( x == tx && y == ty ) return cost;
        for( int i = 0; i < 4; i++ ) {
            int nx = x+dx[ i ];
            int ny = y+dy[ i ];
            if( 0 <= nx && nx < r && 0 <= ny && ny < c && !seen[ nx ][ ny ] ) {
                seen[ nx ][ ny ] = true;
                q.push( nx );
                q.push( ny );
                q.push( cost+1 );
            }
        }
    }
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> r >> c ) && ( r+c > 0 ) ) {
        memset( seen, false, sizeof( seen ) );
        cin >> k;
        for( int i = 0; i < k; i++ ) {
            int x, y, cant;
            cin >> x >> cant;
            for( int j = 0; j < cant; j++ ) {
                cin >> y;
                seen[ x ][ y ] = true;
            }
        }
        cin >> fx >> fy >> tx >> ty;
        cout << solve( ) << "\n";
    }

    return 0;
}
