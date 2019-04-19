#include <bits/stdc++.h>

#define FILE 	0
#define INPUT 	"input"
#define OUTPUT 	"output"

#define MP 	    make_pair
#define MT 	    make_tuple
#define PB 	    push_back
#define FI 	    first
#define SE 	    second

#define MAX 	int( 200 )
#define INF 	INT_MAX
#define EPS 	int(1e-7)
#define MOD 	int(1e7+7)
#define PI 	    acos(-1)

#define LEFT    1
#define RIGHT   2

typedef long long ll;

using namespace std;

int r, c, p, z;
int board[ MAX ][ MAX ];
string location, Z[ MAX*MAX ];
char dir;

bool cmp( string a, string b ) {
    if( a[ 0 ] != b[ 0 ] ) return a[ 0 ] < b[ 0 ];
    if( a[ 1 ] != b[ 1 ] ) return a[ 1 ] < b[ 1 ];
    return a[ 2 ] < b[ 2 ];
}

int main( ) {

    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 );
    cout.tie( 0 );

	if( FILE & 1 ) freopen( INPUT , "r", stdin  );
	if( FILE & 2 ) freopen( OUTPUT, "w", stdout );

    while( ( cin >> r >> c ) && ( r+c > 0 ) ) {
        cin >> p;
        for( int i = 0; i < p; i++ ) {
            cin >> location >> dir;
            if( int( location.size( ) ) == 2 ) {
                location += location[ 1 ];
                location[ 1 ] = '0';
            }
            int x = location[ 0 ]-'A'+1;
            int y = (location[ 1 ]-'0')*10+(location[ 2 ]-'0');
            if( dir == '-' ) {
                board[ x ][ y ]   |= LEFT;
                board[ x ][ y-1 ] |= RIGHT;
            }
            else {
                board[ x ][ y ]   |= RIGHT;
                board[ x ][ y+1 ] |= LEFT;
            }
        }
        cin >> z;
        for( int i = 0; i < z; i++ ) {
            cin >> Z[ i ];
            if( int( Z[ i ].size( ) ) == 2 ) {
                Z[ i ] += Z[ i ][ 1 ];
                Z[ i ][ 1 ] = '0';
            }
        }
        sort( Z, Z+z, cmp );
        bool can = true;
        for( int i = 0; i < z; i++ ) {
            int x = Z[ i ][ 0 ]-'A'+1;
            int y = (Z[ i ][ 1 ]-'0')*10+(Z[ i ][ 2 ]-'0');
            if( !( board[ x ][ y ]&LEFT ) ) {
                board[ x ][ y ]   |= LEFT;
                board[ x ][ y-1 ] |= RIGHT;
            }
            else if( !( board[ x ][ y ]&RIGHT ) ) {
                board[ x ][ y ]   |= RIGHT;
                board[ x ][ y+1 ] |= LEFT;
            }
            else {
                can = false;
                break;
            }
        }
        cout << ( can ? "YES" : "NO" ) << "\n";

        memset( board, 0, sizeof( board ) );
    }

    return 0;
}
