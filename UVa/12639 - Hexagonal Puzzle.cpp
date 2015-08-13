#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int(1e7+10)
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int h[ 7 ][ 6 ];
vector< int > p( 7 );

bool check( ) {
    for( int i = 0; i < 6; i++ ) {
        for( int j = 0; j < 6; j++ ) {
            if( h[ p[ 6 ] ][ i ] == h[ p[ i ] ][ j ] ) {
                for( int k = 0; k < 6; k++ ) {
                    if( h[ p[ i ] ][ (j-1+6)%6 ] == h[ p[ (i+1)%6 ] ][ k ] ) {
                        if( h[ p[ 6 ] ][ (i+1)%6 ] != h[ p[ (i+1)%6 ] ][ (k-1+6)%6 ] )
                            return false;
                    }
                }
                break;
            }
        }
    }
    return true;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

	for( int i = 0; i < 7; i++ ) p[ i ] = i;

    while( scanf( "%d %d %d %d %d %d", &h[ 0 ][ 0 ], &h[ 0 ][ 1 ], &h[ 0 ][ 2 ], &h[ 0 ][ 3 ], &h[ 0 ][ 4 ], &h[ 0 ][ 5 ] ) != EOF ) {
        for( int i = 1; i < 7; i++ )
            scanf( "%d %d %d %d %d %d", &h[ i ][ 0 ], &h[ i ][ 1 ], &h[ i ][ 2 ], &h[ i ][ 3 ], &h[ i ][ 4 ], &h[ i ][ 5 ] );
        bool ans = false;
        do ans |= check( );
        while( next_permutation( p.begin( ), p.end( ) ) );
        cout << ( ans ? "YES" : "NO" ) << "\n";
    }

    return 0;
}
