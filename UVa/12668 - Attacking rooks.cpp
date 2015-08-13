#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 110 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int n, r, c, curr, curc;
char board[ MAX ][ MAX ];
int idr[ MAX ][ MAX ], idc[ MAX ][ MAX ];
int R[ MAX*MAX ], C[ MAX*MAX ];
bool seen[ MAX*MAX ];
vector< int > G[ MAX*MAX ];

bool findMatch( int node ) {
    if( seen[ node ] ) return false;
    seen[ node ] = true;
    for( int i = 0; i < int( G[ node ].size( ) ); i++ ) {
        if( C[ G[ node ][ i ] ] == -1 || findMatch( C[ G[ node ][ i ] ] ) ) {
            R[ node ] = G[ node ][ i ];
            C[ G[ node ][ i ] ] = node;
            return true;
        }
    }
    return false;
}

int maxBipartiteMatching( ) {
    int ans = 0;
    bool found = false;
    memset( R, -1, sizeof( R ) );
    memset( C, -1, sizeof( C ) );
    do {
        found = false;
        memset( seen, false, sizeof( seen ) );
        for( int i = 0; i < r; i++ ) {
            if( R[ i ] == -1 && !seen[ i ] ) {
                if( findMatch( i ) ) {
                    ans++;
                    found = true;
                }
            }
        }
    } while( found );
    /*for( int i = 0; i < c; i++ ) {
        if( C[ r+i ] != -1 )
            cout << C[ r+i ] << " " << i << endl;
    }/**/
    return ans;
}

int main( ) {

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( scanf( "%d", &n ) != EOF ) {
        for( int i = 0; i < n; i++ ) scanf( "%s", board[ i ] );
        r = c = curr = curc = 0;
        memset( idr, -1, sizeof( idr ) );
        memset( idc, -1, sizeof( idc ) );
        for( int i = 0; i < MAX*MAX; i++ ) G[ i ].clear( );

        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( board[ i ][ j ] == 'X' ) {
                    if( curr ) r++;
                    curr = 0;
                }
                else {
                    idr[ i ][ j ] = r;
                    curr++;
                }
                if( board[ j ][ i ] == 'X' ) {
                    if( curc ) c++;
                    curc = 0;
                }
                else {
                    idc[ j ][ i ] = c;
                    curc++;
                }
            }
            if( curr ) r++;
            if( curc ) c++;
            curr = curc = 0;
        }
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ ) {
                if( idr[ i ][ j ] != -1 ) {
                    G[ idr[ i ][ j ] ].PB( r+idc[ i ][ j ] );
                    G[ r+idc[ i ][ j ] ].PB( idr[ i ][ j ] );
                }
            }
        }

        printf( "%d\n", maxBipartiteMatching( ) );

    }

    return 0;
}
