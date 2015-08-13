#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e2+10 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, m;
int b[ MAX ][ MAX ], p[ MAX ][ MAX ], r[ MAX ][ MAX ];

void solve( ) {

    int minSum = INT_MAX, row;

    for( int i = 0; i < n; i++ ) {
        p[ i ][ m-1 ] = -1;
        r[ i ][ m-1 ] = b[ i ][ m-1 ];
        if( r[ i ][ m-1 ] < minSum ) {
            minSum = r[ i ][ m-1 ];
            row = i;
        }
    }

    for( int j = m-2; j >= 0; j-- ) {
        minSum = INT_MAX;
        for( int i = 0; i < n; i++ ) {
            r[ i ][ j ] = r[ i ][ j+1 ]+b[ i ][ j ];
            p[ i ][ j ] = i;
            if( r[ (i+1)%n ][ j+1 ]+b[ i ][ j ] < r[ i ][ j ] ) {
                r[ i ][ j ] = r[ (i+1)%n ][ j+1 ]+b[ i ][ j ];
                p[ i ][ j ] = (i+1)%n;
            }
            else if( r[ (i+1)%n ][ j+1 ]+b[ i ][ j ] == r[ i ][ j ] ) {
                p[ i ][ j ] = min( p[ i ][ j ], (i+1)%n );
            }
            if( r[ ( i-1+n)%n ][ j+1 ]+b[ i ][ j ] < r[ i ][ j ] ) {
                r[ i ][ j ] = r[ ( i-1+n)%n ][ j+1 ]+b[ i ][ j ];
                p[ i ][ j ] = (i-1+n)%n;
            }
            else if( r[ ( i-1+n)%n ][ j+1 ]+b[ i ][ j ] == r[ i ][ j ] ) {
                p[ i ][ j ] = min( p[ i ][ j ], (i-1+n)%n );
            }
            if( r[ i ][ j ] < minSum ) {
                minSum = r[ i ][ j ];
                row = i;
            }
        }
    }

    for( int i = 0; i < m; i++ ) {
        if( i ) cout << " ";
        cout << row+1;
        row = p[ row ][ i ];
    }
    cout << "\n" << minSum << "\n";

}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> n >> m ) {
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < m; j++ )
                cin >> b[ i ][ j ];
        solve( );
    }

    return 0;
}
