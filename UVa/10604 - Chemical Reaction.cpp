#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX_K   10
#define MAX_M   6

#define INF     ( 1LL<<60 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int nTest, m, k;
int c[ MAX_M ];
int g[ MAX_M ][ MAX_M ];
ll  h[ MAX_M ][ MAX_M ];

ll   dp[ MAX_K ][ MAX_K ][ MAX_K ][ MAX_K ][ MAX_K ][ MAX_K ];
bool ok[ MAX_K ][ MAX_K ][ MAX_K ][ MAX_K ][ MAX_K ][ MAX_K ];

ll go( int cur ) {
    if( cur+1 == k ) return 0;
    ll&   r = dp[ c[ 0 ] ][ c[ 1 ] ][ c[ 2 ] ][ c[ 3 ] ][ c[ 4 ] ][ c[ 5 ] ];
    bool& u = ok[ c[ 0 ] ][ c[ 1 ] ][ c[ 2 ] ][ c[ 3 ] ][ c[ 4 ] ][ c[ 5 ] ];
    if( u ) return r;
    r = INF;
    u = 1;
    for( int i = 0; i < m; i++ ) {
        if( c[ i ] == 0 ) continue;
        c[ i ]--;
        for( int j = 0; j < m; j++ ) {
            if( c[ j ] == 0 ) continue;
            c[ j ]--;
            c[ g[ i ][ j ] ]++;
            r = min( r, h[ i ][ j ]+go( cur+1 ) );
            c[ g[ i ][ j ] ]--;
            c[ j ]++;
        }
        c[ i ]++;
    }
    return r;
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    cin >> nTest;
    while( nTest-- ) {
        memset( dp, -1, sizeof( dp ) );
        memset( ok,  0, sizeof( ok ) );
        memset( c ,  0, sizeof( c  ) );
        cin >> m;
        for( int i = 0; i < m; i++ ) {
            for( int j = 0; j < m; j++ ) {
                cin >> g[ i ][ j ] >> h[ i ][ j ];
                g[ i ][ j ]--;
            }
        }
        cin >> k;
        for( int i = 0, t; i < k; i++ ) {
            cin >> t;
            t--;
            c[ t ]++;
        }
        cout << go( 0 ) << "\n";
        char garbage;
        cin >> garbage;
    }

    return 0;
}
