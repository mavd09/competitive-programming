#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 1e3+100 )
#define MAXV    int( 6e2 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

typedef long long ll;

using namespace std;

int szV, szC;
int V[ MAXV ][ 30 ], C[ MAXV ][ 30 ];
int L[ MAX ], R[ MAX ];
string word;
vector< int > G[ MAX ];
bool seen[ MAX ];

bool findMatch( int v ) {
    if( seen[ v ] ) return false;
    seen[ v ] = true;
    for( int i = 0; i < int( G[ v ].size( ) ); i++ ) {
        int u = G[ v ][ i ];
        if( R[ u ] == -1 || findMatch( R[ u ] ) ) {
            L[ v ] = u;
            R[ u ] = v;
            return true;
        }
    }
    return false;
}

int maxBipartiteMatching( ) {
    int ans = 0;
    bool found = false;
    memset( L, -1, sizeof( L ) );
    memset( R, -1, sizeof( R ) );

    do {
        found = false;
        memset( seen, false, sizeof( seen ) );
        for( int i = 0; i < szV; i++ ) {
            if( L[ i ] == -1 && !seen[ i ] ) {
                if( findMatch( i ) ) {
                    ans++;
                    found = true;
                }
            }
        }
    } while( found );

    return ans;
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( cin >> szV >> szC ) {

        memset( V, 0, sizeof( V ) );
        memset( C, 0, sizeof( C ) );
        for( int i = 0; i < MAX; i++ ) G[ i ].clear( );

        for( int i = 0; i < szV; i++ ) {
            cin >> word;
            for( int j = 0; j < int( word.size( ) ); j++ )
                V[ i ][ word[ j ]-'a' ]++;
        }
        for( int i = 0; i < szC; i++ ) {
            cin >> word;
            for( int j = 0; j < int( word.size( ) ); j++ )
                C[ i ][ word[ j ]-'a' ]++;
        }

        for( int i = 0; i < szV; i++ ) {
            for( int j = 0; j < szC; j++ ) {
                bool can = true;
                for( int k = 0; k < 26; k++ ) {
                    can &= C[ j ][ k ] <= V[ i ][ k ];
                }
                if( can ) {
                    G[ i ].PB( szV+j );
                    G[ szV+j ].PB( i );
                }
            }
        }

        cout << maxBipartiteMatching( ) << "\n";

    }

    return 0;
}
