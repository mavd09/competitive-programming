#include <bits/stdc++.h>

#define MP          make_pair
#define PB          push_back
#define FI          first
#define SE          second

#define MAX         110
#define LOG_MAX     14

#define MAX_TIME    4000

#define INF         ( INT_MAX )

#define MOD         1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n;
int G[ MAX ][ MAX ], ans[ MAX ][ MAX ];
int mark[ 2 ][ MAX ];

void dfs( int id, int u, int k ) {
    mark[ id ][ u ] = true;
    for( int v = 0; v < n; v++ )
        if( G[ u ][ v ] && !mark[ id ][ v ] && v != k )
            dfs( id, v, k );
}

int main( ) {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );
    
    int nTest;
    cin >> nTest;
    
    for( int tc = 1; nTest--; tc++ ) {
        cin >> n;
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                cin >> G[ i ][ j ];
        memset( ans, false,  sizeof( ans ) );
        memset( mark[ 0 ], false, sizeof( mark[ 0 ] ) );
        dfs( 0, 0, -1 );
        for( int u = 0; u < n; u++ ) {
            memset( mark[ 1 ], false, sizeof( mark[ 1 ] ) );
            if( u ) dfs( 1, 0, u );
            for( int v = 0; v < n; v++ )
                if( mark[ 0 ][ v ] && !mark[ 1 ][ v ] )
                    ans[ u ][ v ] = true;
        }
        cout << "Case " << tc << ":\n";
        cout << "+" << string( 2*n-1, '-' ) << "+\n";
        for( int i = 0; i < n; i++ ) {
            for( int j = 0; j < n; j++ )
                cout << "|" << ( ans[ i ][ j ] ? 'Y' : 'N' );
            cout << "|\n";
            cout << "+" << string( 2*n-1, '-' ) << "+\n";
        }
    }
    
    return 0;
    
}