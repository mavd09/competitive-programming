#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 1e2+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

const int dx[ ] = {  0  ,  0  ,  1  , -1  };
const int dy[ ] = {  1  , -1  ,  0  ,  0  };

int r, c, t;
string board[ MAXN ];
vector< pair< int, int > > ans;

pair< int, char > bfs( int x, int y ) {
    char cur = board[ x ][ y ];
    int ret = 0;
    queue< int > q;
    q.push( x );
    q.push( y );
    board[ x ][ y ] = '.';
    while( !q.empty( ) ) {
        int a = q.front( ); q.pop( );
        int b = q.front( ); q.pop( );
        ret++;
        for( int i = 0; i < 4; i++ ) {
            int na = a+dx[ i ];
            int nb = b+dy[ i ];
            if( 0 <= na && na < r && 0 <= nb && nb < c && board[ na ][ nb ] == cur ) {
                board[ na ][ nb ] = '.';
                q.push( na );
                q.push( nb );
            }
        }
    }
    return MP( ret, -cur );
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> r >> c ) && ( r+c > 0 ) ) {
        ans.clear( );
        for( int i = 0; i < r; i++ )
            cin >> board[ i ];
        for( int i = 0; i < r; i++ ) {
            for( int j = 0; j < c; j++ ) {
                if( board[ i ][ j ] != '.' ) {
                    ans.PB( bfs( i, j ) );
                }
            }
        }
        sort( ans.rbegin( ), ans.rend( ) );
        cout << "Problem " << ++t << ":\n";
        for( int i = 0; i < int( ans.size( ) ); i++ )
            cout << char( -ans[ i ].SE ) << " " << ans[ i ].FI << "\n";
    }

    return 0;
}
