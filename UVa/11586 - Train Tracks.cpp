#include <bits/stdc++.h>

#define FILE    0

#define MP      make_pair
#define PB      push_back
#define FI      first
#define SE      second

#define MAX     55

#define INF     ( 1LL<<60 )

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int connect[ 3 ][ 3 ] = { { -1  ,  0  ,  1  },
                                {  0  ,  1  ,  2  },
                                {  1  ,  2  , -1  } };

int nPieces, cnt[ 3 ];
int dp[ MAX ][ MAX ][ MAX ];

int can( ) {

    int& r = dp[ cnt[ 0 ] ][ cnt[ 1 ] ][ cnt[ 2 ] ];
    if( r != -1 ) return r;
    if( cnt[ 0 ]+cnt[ 1 ]+cnt[ 2 ] == 1 ) return cnt[ 1 ] && ( nPieces > 1 );
    r = 0;
    for( int i = 0; i < 3; i++ ) {
        if( cnt[ i ] == 0 ) continue;
        cnt[ i ]--;
        for( int j = 0; j < 3; j++ ) {
            if( cnt[ j ] == 0 || connect[ i ][ j ] == -1 ) continue;
            cnt[ j ]--;
            cnt[ connect[ i ][ j ] ]++;
            r |= can( );
            cnt[ connect[ i ][ j ] ]--;
            cnt[ j ]++;
        }
        cnt[ i ]++;
    }
    return r;

}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

    if( FILE&1 ) freopen( "input" , "r", stdin  );
    if( FILE&2 ) freopen( "output", "w", stdout );

    int nTest;
    string line, piece;

    cin >> nTest; cin.ignore( );
    while( nTest-- ) {
        memset( dp, -1, sizeof( dp ) );
        memset( cnt, 0, sizeof( cnt ) );
        getline( cin, line );
        stringstream ss( line );
        nPieces = 0;
        while( ss >> piece ) {
            nPieces++;
            if( piece == "MM" )      cnt[ 0 ]++;
            else if( piece == "FF" ) cnt[ 2 ]++;
            else                     cnt[ 1 ]++;
        }
        cout << ( can( ) ? "LOOP" : "NO LOOP" ) << "\n";
    }

    return 0;
}
