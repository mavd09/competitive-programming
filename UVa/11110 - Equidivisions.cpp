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

const int DX[ ] = {  0  ,  0  ,  1  , -1  };
const int DY[ ] = {  1  , -1  ,  0  ,  0  };

int n, a, b, na, nb;
int board[ MAXN ][ MAXN ];
bool seen[ MAXN ][ MAXN ];
string line;

bool bfs( int x, int y ) {
    int cur = 0;
    queue< int > q;
    q.push( x );
    q.push( y );
    seen[ x ][ y ] = true;
    while( !q.empty( ) ) {
        a = q.front( ); q.pop( );
        b = q.front( ); q.pop( );
        cur++;
        for( int i = 0; i < 4; i++ ) {
            na = a+DX[ i ];
            nb = b+DY[ i ];
            if( 0 <= na && na < n && 0 <= nb && nb < n && !seen[ na ][ nb ] && board[ na ][ nb ] == board[ x ][ y ] ) {
                seen[ na ][ nb ] = true;
                q.push( na );
                q.push( nb );
            }
        }
    }
    return cur == n;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> n ) && ( n > 0 ) ) {
        memset( seen, false, sizeof( seen ) );
        memset( board, 0, sizeof( board ) );
        cin.ignore( );
        for( int i = 1; i < n; i++ ) {
            getline( cin, line );
            stringstream ss( line );
            while( ss >> a >> b ) board[ a-1 ][ b-1 ] = i;
        }
        bool can = true;
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( !seen[ i ][ j ] )
                    can &= bfs( i, j );
            }
        }
        if( can ) cout << "good\n";
        else      cout << "wrong\n";
    }

    return 0;
}
