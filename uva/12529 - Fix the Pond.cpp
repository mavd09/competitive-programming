#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 500 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

#define LEFT     1
#define UP       2
#define RIGHT    4
#define DOWN     8

typedef long long ll;

using namespace std;

int N, t;
int board[ 2*MAX ][ 2*MAX ];
int seen[ 2*MAX ][ 2*MAX ];
string d;

bool can( int x, int y ) {
    return 0 <= x && x < 2*N && 0 <= y && y < 2*N+1 && seen[ x ][ y ] != t;
}

void mark( int x, int y ) {
    queue< int > q;
    q.push( x ); q.push( y );
    seen[ x ][ y ] = t;
    while( !q.empty( ) ) {
        x = q.front( ); q.pop( );
        y = q.front( ); q.pop( );
        if( can( x, y-1 ) && !(board[ x ][ y ]&LEFT)  ) {
            seen[ x ][ y-1 ] = t;
            q.push( x ); q.push( y-1 );
        }
        if( can( x, y+1 ) && !(board[ x ][ y ]&RIGHT) ) {
            seen[ x ][ y+1 ] = t;
            q.push( x ); q.push( y+1 );
        }
        if( can( x-1, y ) && !(board[ x ][ y ]&UP)    ) {
            seen[ x-1 ][ y ] = t;
            q.push( x-1 ); q.push( y );
        }
        if( can( x+1, y ) && !(board[ x ][ y ]&DOWN)  ) {
            seen[ x+1 ][ y ] = t;
            q.push( x+1 ); q.push( y );
        }
    }
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> N ) {
        t++;
        memset( board, 0, sizeof( board ) );
        for( int i = 0; i < 2*N-1; i++ ) {
            cin >> d;
            for( int j = 0; j < N; j++ ) {
                if( d[ j ] == 'H' ) {
                    board[  i  ][  (i&1)+(2*j)  ] |= DOWN;
                    board[  i  ][ (i&1)+(2*j+1) ] |= DOWN;
                    board[ i+1 ][  (i&1)+(2*j)  ] |= UP;
                    board[ i+1 ][ (i&1)+(2*j+1) ] |= UP;
                }
                else {
                    board[  i  ][  (i&1)+(2*j)  ] |= RIGHT;
                    board[  i  ][ (i&1)+(2*j+1) ] |= LEFT;
                    board[ i+1 ][  (i&1)+(2*j)  ] |= RIGHT;
                    board[ i+1 ][ (i&1)+(2*j+1) ] |= LEFT;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < 2*N; i++ ) {
            for( int j = 0; j < 2*N+1; j++ ) {
                if( seen[ i ][ j ] != t ) {
                    mark( i, j );
                    ans++;
                }
            }
        }
        cout << ans-1 << "\n";
    }

    return 0;
}
