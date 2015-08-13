#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAXN 	int( 10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

const int dx[ ] = {  1  ,  1  ,  2  ,  2  , -1  , -1  , -2  , -2  };
const int dy[ ] = {  2  , -2  ,  1  , -1  ,  2  , -2  ,  1  , -1  };

int R = 8, C = 8;
string fr, to;
int dp[ MAXN ][ MAXN ][ MAXN ][ MAXN ];

int solve( ) {
    int fx = ( fr[ 0 ]-'a' ), fy = ( fr[ 1 ]-'1' );
    int tx = ( to[ 0 ]-'a' ), ty = ( to[ 1 ]-'1' );
    if( dp[ fx ][ fy ][ tx ][ ty ] != -1 ) return dp[ fx ][ fy ][ tx ][ ty ];
    queue< int > q;
    q.push( fx );
    q.push( fy );
    dp[ fx ][ fy ][ fx ][ fy ] = 0;
    while( !q.empty( ) ) {
        int a = q.front( ); q.pop( );
        int b = q.front( ); q.pop( );
        for( int i = 0; i < 8; i++ ) {
            int na = a+dx[ i ], nb = b+dy[ i ];
            if( 0 <= na && na < R && 0 <= nb && nb < C && dp[ fx ][ fy ][ na ][ nb ] == -1 ) {
                dp[ fx ][ fy ][ na ][ nb ] = dp[ fx ][ fy ][ a ][ b ]+1;
                q.push( na );
                q.push( nb );
            }
        }
    }
    return dp[ fx ][ fy ][ tx ][ ty ];
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    memset( dp, -1, sizeof( dp ) );

    while( cin >> fr >> to )
        cout << "To get from " << fr << " to " << to << " takes " << solve( ) << " knight moves.\n";

    return 0;
}
